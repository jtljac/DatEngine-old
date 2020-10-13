#include <iostream>
#include <Utilities/Logging.h>
#include <Rendering/Vulkan/VulkanRenderer.h>
#include <AssetManager/AssetManager.h>
#include <AssetManager/Factories/VertShaderFactory.h>
#include <AssetManager/Factories/FragShaderFactory.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

#include <Maths/Vectors/Vec3.h>

VulkanRenderer theRenderer;




int main() {

	Vec3<3, float> test();

	test.test();

	AssetManager assMan;
	assMan.registerFactory<FragShader>(new FragShaderFactory());
	assMan.registerFactory<VertShader>(new VertShaderFactory());

	theRenderer.initialise(800, 600, "Vulkan Test", &assMan);


	// Main Loop
	while (!theRenderer.windowWantsToClose()) {
		glfwPollEvents();
		theRenderer.drawFrame();
	}


	theRenderer.cleanup();

	return 0;
}