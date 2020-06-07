#include <iostream>
#include <Engine/Utilities/Logging.h>
#include <Rendering/Vulkan/VulkanRenderer.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/mat4x4.hpp>

int main() {

	Log::e("TAG", "Testing testing");

	VulkanRenderer theRenderer;


	theRenderer.initialise(800, 600, "Vulkan Test");

	// Main Loop
	while (!theRenderer.windowWantsToClose()) {
		glfwPollEvents();
	}

	return 0;
}