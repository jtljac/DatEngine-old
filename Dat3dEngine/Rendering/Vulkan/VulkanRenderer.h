#pragma once

#define GLFW_INCLUDE_VULKAN
#include "../Renderer.h"
#include <Engine/Utilities/Logging.h>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <optional>
#include <set>
#include <cstdint>
#include <algorithm>

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
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    }
private:
	VkInstance instance;                                    // The Vulkan instance

    VkDebugUtilsMessengerEXT debugMessenger;                // The debug messenger for debug from vulkan

    VkSurfaceKHR surface;                                   // The vulkan surface
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;       // The physical device vulkan is using
    VkDevice device;                                        // The logical device vulkan is using

    VkQueue graphicsQueue;                                  // The queue for graphics commands
    VkQueue presentQueue;                                   // The queue for present commands

    VkSwapchainKHR swapChain = VK_NULL_HANDLE;              // The swap chain
    std::vector<VkImage> swapChainImages;                   // The images in the swap chain
    VkFormat swapChainImageFormat;                          // The format of the images in the swap chain
    VkExtent2D swapChainExtent;                             // The extent of the swap chain
    std::vector<VkImageView> swapChainImageViews;           // The image views in the swap chain

    // The frame buffers in the swap chain
    std::vector<VkFramebuffer> swapChainFramebuffers;

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
    void createSwapChain();

    /**
     * Creates the image views for the swap chain
     */
    void createImageViews();

    /**
     * Creates the graphics pipeline
     */
    void createGraphicsPipelixne();

    void createFramebuffers();

public:
    VulkanRenderer() {}

    VulkanRenderer(const std::vector<const char*> &ValidationLayers) {
        validationLayers = std::vector<const char*>(ValidationLayers);
    }

	int initialise(int Width, int Height, std::string WindowTitle) {
        Renderer::initialise(Width, Height, WindowTitle);
        
        createInstance();
        setupDebugMessenger();
        createSurface();
        pickPhysicalDevice();
        createLogicalDevice();
        createSwapChain();
        createImageViews();
        createGraphicsPipeline();

        return 0;
	}

    void cleanup() {
        for (auto imageView : swapChainImageViews) {
            vkDestroyImageView(device, imageView, nullptr);
        }

        vkDestroySwapchainKHR(device, swapChain, nullptr);

        vkDestroyDevice(device, nullptr);

        if (enableValidationLayers) {
            DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
        }

        vkDestroySurfaceKHR(instance, surface, nullptr);

        vkDestroyInstance(instance, nullptr);

        Renderer::cleanup();
    }
};