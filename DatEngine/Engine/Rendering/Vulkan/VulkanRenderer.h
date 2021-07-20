#pragma once

#define GLFW_INCLUDE_VULKAN
#include "../Renderer.h"

#include <stdexcept>
#include <iostream>
#include <vector>
#include <optional>
#include <set>
#include <cstdint>
#include <algorithm>

#include <Utilities/Logging.h>
#include <AssetManager/AssetManager.h>
#include <AssetManager/Assets/Shaders/VertShader.h>
#include <AssetManager/Assets/Shaders/FragShader.h>
#include <Mesh/Primitives/Vertex.h>

#include <Maths/Matrix.h>

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> transferFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value() && transferFamily.has_value();
    }

    bool isUniqueTransferQueue() {
        return transferFamily.value() != graphicsFamily.value();
    }
};

struct UniformBufferObject {
    FMat4 model;
    FMat4 view;
    FMat4 proj;
};

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

class VulkanRenderer : public Renderer {
    inline const static std::string TAG = "Vulkan";

    std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation",
        "VK_LAYER_LUNARG_monitor"
    };

    const std::vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

protected:
    void glfwHints() override {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        // glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    }
private:
    AssetManager* assMan;

    const int MAX_FRAMES_IN_FLIGHT = 2;
	VkInstance instance;                                    // The Vulkan instance

    VkDebugUtilsMessengerEXT debugMessenger;                // The debug messenger for debug from vulkan

    VkSurfaceKHR surface;                                   // The vulkan surface
    QueueFamilyIndices queueFamilies;                       // The queue families in use
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;       // The physical device vulkan is using
    VkDevice device;                                        // The logical device vulkan is using

    VkQueue graphicsQueue;                                  // The queue for graphics commands
    VkQueue transferQueue;                                  // The queue for transfer commands
    VkQueue presentQueue;                                   // The queue for present commands

    VkSwapchainKHR swapChain = VK_NULL_HANDLE;              // The swap chain
    std::vector<VkImage> swapChainImages;                   // The images in the swap chain
    VkFormat swapChainImageFormat;                          // The format of the images in the swapchain
    VkExtent2D swapChainExtent;                             // The extent of the swapchain
    std::vector<VkImageView> swapChainImageViews;           // The image views in the swapchain
    std::vector<VkFramebuffer> swapChainFramebuffers;       // The framebuffers in the swapchain

    VkRenderPass renderPass;                                // The renderpass
    VkPipelineLayout pipelineLayout;                        // The layout of the pipeline
    VkPipeline graphicsPipeline;                            // The graphics pipeline itself

    VkCommandPool graphicsCommandPool;                              // The graphics command pool
    VkCommandPool transferCommandPool;                              // The transfer command pool
    std::vector<VkCommandBuffer> commandBuffers;            // The command buffers

    VkBuffer vertexBuffer;                                  // The vertex buffer
    VkDeviceMemory vertexBufferMemory;                      // The allocated memory for the vertex buffer
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;

    std::vector<VkSemaphore> imageAvailableSemaphores;      // Image Available semaphores
    std::vector<VkSemaphore> renderFinishedSemaphores;      // Render Finished semaphores
    std::vector<VkFence> inFlightFences;                    // The in flight fences
    std::vector<VkFence> imagesInFlight;                    // The images in flight
    size_t currentFrame = 0;                                // The current frame


    const std::vector<Vertex> vertices = {
        {{0.0f, -0.5f}, {1.0f, 1.0f, 1.0f}},
        {{0.5f, 0.5f}, {0.0f, 1.0f, 0.0f}},
        {{-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}}
    };

    const std::vector<uint16_t> indices = {
        0, 1, 2,
        2, 3, 0
    };

    /**
     * Checks the machine supports the required validation layers
     */
    bool checkValidationLayerSupport();

    // Debug Module Load & unload
    static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
        // Get the function handle from the module
        PFN_vkCreateDebugUtilsMessengerEXT func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
        if (func != nullptr) {
            return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
        }
        else {
            return VK_ERROR_EXTENSION_NOT_PRESENT;
        }
    }
    static void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
        PFN_vkDestroyDebugUtilsMessengerEXT func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
        if (func != nullptr) {
            func(instance, debugMessenger, pAllocator);
        }
    }

    // Validation Layer Callback
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);

    /**
     * Populates the given VkDebugUtilsMessengerCreateInfoEXT with the necessary values
     * @param createInfo The VkDebugUtilsMessengerCreateInfoEXT to be populated
     */
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    /**
     * Sets up the debug messages from vulkan if enabled
     */
    void setupDebugMessenger();

    /**
     * Get all the extensions required by the engine
     * @return A vector containing all the required extensions
     */
    std::vector<const char*> getRequiredExtensions() const;

    /**
     * Creates the vulkan instance
     */
    void createInstance();

    /**
     * Creates a surface for vulkan to use
     */
    void createSurface();

    /**
     * A little debug function to print the capabilities of the gpu to the console
     * @param vkPhysicalDevice the vkPhysicalDevice to query
     */
    [[maybe_unused]] static void listQueueFamilies(VkPhysicalDevice vkPhysicalDevice);

    // Physical Device stuff
    /**
     * Looks through the queue families of the given vkPhysicalDevice to make sure it has the ones we need
     * @param vkPhysicalDevice The vkPhysicalDevice we're checking
     * @return The indicies of the queue family
     */
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice vkPhysicalDevice);

    /**
     * Checks to see if the given vkPhysicalDevice supports all of the required extensions
     * @param vkPhysicalDevice The vkPhysicalDevice to check
     */
    bool checkDeviceExtensionSupport(VkPhysicalDevice vkPhysicalDevice);

    /**
     * Get the details for the the swap chain
     * @param vkPhysicalDevice The vkPhysicalDevice to query
     * @return The details for the swapchain
     */
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice vkPhysicalDevice);

    /**
     * Get the best format for the device
     * @param availableFormats A vector of the available formats
     * @return The best swap surface format
     */
    static VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);

    /**
     * Get the best present mode for the device
     * @param availableFormats A vector of the available present mode
     * @return The best present mode
     */
    static VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);

    /**
     * Get the closest extent to our window size we can manage
     * @param capabilities The device capabilities
     * @return the closest extent to our window size
     */
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

    /**
     * Rates the given vkPhysicalDevice on how suitable it is for the engine
     * @param vkPhysicalDevice the vkPhysicalDevice to rate
     * @return A score representing how suitable the vkPhysicalDevice is
     */
    int rateDeviceSuitability(VkPhysicalDevice vkPhysicalDevice);

    /**
     * Selects a suitable device from all the devices available for rendering
     */
    void pickPhysicalDevice();

    // Logical Device

    /**
     * Creates a logical device for vulkan to use
     */
    void createLogicalDevice();

    /**
     * Creates a swap chan for vulkan to use
     * @param OldSwapChain The old swap chain (optional)
     */
    void createSwapChain(VkSwapchainKHR OldSwapChain = VK_NULL_HANDLE);

    /**
     * Creates the image views for the swap chain
     */
    void createImageViews();

    /**
     * Creates a shader model from the given bytecode
     * @param code The byte code to convert into a shadermodel
     * @return The resultant shader model
     */
    VkShaderModule createShaderModule(const std::vector<char>& code);

    /**
     * Creates the render pass
     */
    void createRenderPass();

    /**
     * Creates the graphics pipeline
     */
    void createGraphicsPipeline();

    /**
     * Creates The framebuffers
     */
    void createFramebuffers();

    /**
     * Creates the command pool
     */
    void createCommandPool(uint32_t queueFamilyIndex, VkCommandPool &commandPool);

    /**
     * Finds and returns the memory type fit for the given requirements
     */
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) {
        VkPhysicalDeviceMemoryProperties memProperties;
        vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProperties);

        for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
            if (typeFilter & (1 << i) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties) {
                return i;
            }
        }

        throw std::runtime_error("failed to find suitable memory type!");
    }

    /**
     * Creates a memory buffer on the video card
     * @param size The required size of the buffer
     * @param usage The usage flags for the buffer
     * @param properties The memory property flags for the buffer
     * @param buffer A reference to the Buffer
     * @param buffer A reference to the Buffer Memory
     */
    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);

    /**
     * Copies data from one video card buffer to another
     * @param srcBuffer The buffer to copy from
     * @param dstBuffer The buffer to copy to
     * @param size The size of the data to copy
     */
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

    /**
     * Creates the vertex buffer
     */
    void createVertexBuffer();

    /**
     * Creates the index buffer
     */
    void createIndexBuffer();

    /**
     * Creates the command buffers
     */
    void createCommandBuffers();

    /**
     * Creates the semaphores and fences
     */
    void createSyncObjects();

    void cleanupSwapChain(bool FullCleanup = true) {
        // Destroy framebuffers
        for (VkFramebuffer framebuffer : swapChainFramebuffers) {
            vkDestroyFramebuffer(device, framebuffer, nullptr);
        }

        vkFreeCommandBuffers(device, graphicsCommandPool, static_cast<uint32_t>(commandBuffers.size()), commandBuffers.data());

        // Destroy pipeline
        vkDestroyPipeline(device, graphicsPipeline, nullptr);
        vkDestroyPipelineLayout(device, pipelineLayout, nullptr);
        vkDestroyRenderPass(device, renderPass, nullptr);

        // Destroy image views
        for (VkImageView imageView : swapChainImageViews) {
            vkDestroyImageView(device, imageView, nullptr);
        }

        if (FullCleanup) vkDestroySwapchainKHR(device, swapChain, nullptr);
    }

public:
    VulkanRenderer() {}

    VulkanRenderer(const std::vector<const char*> &ValidationLayers) {
        validationLayers = std::vector<const char*>(ValidationLayers);
    }

	int initialise(int Width, int Height, std::string WindowTitle, AssetManager* AssMan) {
        Renderer::initialise(Width, Height, WindowTitle);

        Log::i(TAG, "Initialising Vulkan Renderer");
        
        assMan = AssMan;

        createInstance();
        setupDebugMessenger();
        createSurface();
        pickPhysicalDevice();
        createLogicalDevice();
        createSwapChain();
        createImageViews();
        createRenderPass();
        createGraphicsPipeline();
        createFramebuffers();
        createCommandPool(queueFamilies.graphicsFamily.value(), graphicsCommandPool);
        createCommandPool(queueFamilies.transferFamily.value(), transferCommandPool);
        createVertexBuffer();
        createIndexBuffer();
        createCommandBuffers();
        createSyncObjects();

        return 0;
	}

    void recreateSwapChain() {
        Log::i(TAG, "Changes to screen detected, recreating swap chain");
        int width = 0, height = 0;
        glfwGetFramebufferSize(window, &width, &height);
        while (width == 0 || height == 0) {
            glfwGetFramebufferSize(window, &width, &height);
            glfwWaitEvents();
        }

        vkDeviceWaitIdle(device);

        VkSwapchainKHR oldSwapChain = swapChain;

        cleanupSwapChain(false);

        createSwapChain(oldSwapChain);
        vkDestroySwapchainKHR(device, oldSwapChain, nullptr);

        createImageViews();
        createRenderPass();
        createGraphicsPipeline();
        createFramebuffers();
        createCommandBuffers();
    }

    void drawFrame() {
        vkWaitForFences(device, 1, &inFlightFences[currentFrame], VK_TRUE, UINT64_MAX);

        uint32_t imageIndex;
        VkResult result = vkAcquireNextImageKHR(device, swapChain, UINT64_MAX, imageAvailableSemaphores[currentFrame], VK_NULL_HANDLE, &imageIndex);

        if (result == VK_ERROR_OUT_OF_DATE_KHR) {
            recreateSwapChain();
            return;
        }
        else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
            throw std::runtime_error("failed to acquire swap chain image!");
        }

        // Check if a previous frame is using this image (i.e. there is its fence to wait on)
        if (imagesInFlight[imageIndex] != VK_NULL_HANDLE) {
            vkWaitForFences(device, 1, &imagesInFlight[imageIndex], VK_TRUE, UINT64_MAX);
        }
        // Mark the image as now being in use by this frame
        imagesInFlight[imageIndex] = inFlightFences[currentFrame];

        VkSubmitInfo submitInfo{};
        submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

        VkSemaphore waitSemaphores[] = { imageAvailableSemaphores[currentFrame] };
        VkPipelineStageFlags waitStages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
        submitInfo.waitSemaphoreCount = 1;
        submitInfo.pWaitSemaphores = waitSemaphores;
        submitInfo.pWaitDstStageMask = waitStages;

        submitInfo.commandBufferCount = 1;
        submitInfo.pCommandBuffers = &commandBuffers[imageIndex];

        VkSemaphore signalSemaphores[] = { renderFinishedSemaphores[currentFrame] };
        submitInfo.signalSemaphoreCount = 1;
        submitInfo.pSignalSemaphores = signalSemaphores;


        vkResetFences(device, 1, &inFlightFences[currentFrame]);

        if (vkQueueSubmit(graphicsQueue, 1, &submitInfo, inFlightFences[currentFrame]) != VK_SUCCESS) {
            throw std::runtime_error("failed to submit draw command buffer!");
        }

        VkPresentInfoKHR presentInfo{};
        presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

        presentInfo.waitSemaphoreCount = 1;
        presentInfo.pWaitSemaphores = signalSemaphores;

        VkSwapchainKHR swapChains[] = { swapChain };
        presentInfo.swapchainCount = 1;
        presentInfo.pSwapchains = swapChains;
        presentInfo.pImageIndices = &imageIndex;

        presentInfo.pResults = nullptr; // Optional

        result = vkQueuePresentKHR(presentQueue, &presentInfo);

        if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || framebufferResized) {
            framebufferResized = false;
            recreateSwapChain();
        }
        else if (result != VK_SUCCESS) {
            throw std::runtime_error("failed to present swap chain image!");
        }

        currentFrame = (currentFrame + 1) % MAX_FRAMES_IN_FLIGHT;
    }

    void cleanup() override {
        // Wait for vulkan to finish
        vkDeviceWaitIdle(device);

        cleanupSwapChain();

        vkDestroyBuffer(device, indexBuffer, nullptr);
        vkFreeMemory(device, indexBufferMemory, nullptr);

        vkDestroyBuffer(device, vertexBuffer, nullptr);
        vkFreeMemory(device, vertexBufferMemory, nullptr);

        // Semaphores and fences
        for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
            vkDestroySemaphore(device, renderFinishedSemaphores[i], nullptr);
            vkDestroySemaphore(device, imageAvailableSemaphores[i], nullptr);
            vkDestroyFence(device, inFlightFences[i], nullptr);
        }

        vkDestroyCommandPool(device, graphicsCommandPool, nullptr);
        vkDestroyCommandPool(device, transferCommandPool, nullptr);

        vkDestroyDevice(device, nullptr);

        if (enableValidationLayers) {
            DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
        }

        vkDestroySurfaceKHR(instance, surface, nullptr);

        vkDestroyInstance(instance, nullptr);

        Renderer::cleanup();
    }
};