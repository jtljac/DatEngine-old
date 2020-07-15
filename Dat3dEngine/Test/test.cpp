#include <iostream>
#include <Engine/Utilities/Logging.h>
#include <Rendering/Vulkan/VulkanRenderer.h>
#include <Engine/Assets/AssetManager/AssetManager.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/mat4x4.hpp>

int main() {
	VulkanRenderer theRenderer;

	AssetManager assMan;

	theRenderer.initialise(800, 600, "Vulkan Test");

	// Main Loop
	while (!theRenderer.windowWantsToClose()) {
		glfwPollEvents();
	}

	theRenderer.cleanup();

	return 0;
}