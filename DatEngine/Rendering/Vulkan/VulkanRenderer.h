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

#include <Engine/Utilities/Logging.h>
#include <Engine/AssetManager/AssetManager.h>
#include <Engine/AssetManager/Assets/Shaders/VertShader.h>
#include <Engine/AssetManager/Assets/Shaders/FragShader.h>

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

class VulkanRenderer : public Renderer {
    inline const static std::string TAG = "Vulkan";

    std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
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
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;       // The physical device vulkan is using
    VkDevice device;                                        // The logical device vulkan is using

    VkQueue graphicsQueue;                                  // The queue for graphics commands
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

    VkCommandPool commandPool;                              // The command pool
    std::vector<VkCommandBuffer> commandBuffers;            // The command buffers

    std::vector<VkSemaphore> imageAvailableSemaphores;      // Image Available semaphores
    std::vector<VkSemaphore> renderFinishedSemaphores;      // Render Finished semaphores
    std::vector<VkFence> inFlightFences;                    // The in flight fences
    std::vector<VkFence> imagesInFlight;                    // The images in flight
    size_t currentFrame = 0;                                // The current frame

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
    std::vector<const char*> getRequiredExtensions();

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
     * @param device the device to query
     */
    void listQueueFamilies(VkPhysicalDevice device);

    // Physical Device stuff
    /**
     * Looks through the queue families of the given device to make sure it has the ones we need
     * @param device The device we're checking
     * @return The indicies of the queue family
     */
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    /**
     * Checks to see if the given device supports all of the required extensions
     * @param device The device to check
     */
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    /**
     * Get the details for the the swap chain
     * @param device The device to query
     * @return The details for the swapchain
     */
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

    /**
     * Get the best format for the device
     * @param availableFormats A vector of the available formats
     * @return The best swap surface format
     */
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);

    /**
     * Get the best present mode for the device
     * @param availableFormats A vector of the available present mode
     * @return The best present mode
     */
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);

    /**
     * Get the closest extent to our window size we can manage
     * @param capabilities The device capabilities
     * @return the closest extent to our window size
     */
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

    /**
     * Rates the given device on how suitable it is for the engine
     * @param device the device to rate
     * @return A score representing how suitable the device is
     */
    int rateDeviceSuitability(VkPhysicalDevice device);

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
    void createCommandPool();

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

        vkFreeCommandBuffers(device, commandPool, static_cast<uint32_t>(commandBuffers.size()), commandBuffers.data());

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
        createCommandPool();
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

    void cleanup() {
        // Wait for vulkan to finish
        vkDeviceWaitIdle(device);

        cleanupSwapChain();

        // Semaphores and fences
        for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
            vkDestroySemaphore(device, renderFinishedSemaphores[i], nullptr);
            vkDestroySemaphore(device, imageAvailableSemaphores[i], nullptr);
            vkDestroyFence(device, inFlightFences[i], nullptr);
        }

        vkDestroyCommandPool(device, commandPool, nullptr);

        vkDestroyDevice(device, nullptr);

        if (enableValidationLayers) {
            DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
        }

        vkDestroySurfaceKHR(instance, surface, nullptr);

        vkDestroyInstance(instance, nullptr);

        Renderer::cleanup();
    }
};