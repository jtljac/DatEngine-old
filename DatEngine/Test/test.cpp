#include <iostream>
#include <Platform/Timing.h>
#include <Utilities/Logging.h>
#include <Rendering/Vulkan/VulkanRenderer.h>
#include <AssetManager/AssetManager.h>
#include <AssetManager/Factories/VertShaderFactory.h>
#include <AssetManager/Factories/FragShaderFactory.h>

#include <Profiling/Profiler.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/mat4x4.hpp>

#include <Maths/Vector.h>

VulkanRenderer theRenderer;

int main() {
	AssetManager assMan;
	assMan.registerFactory<FragShader>(new FragShaderFactory());
	assMan.registerFactory<VertShader>(new VertShaderFactory());
	Timing::initialise();
	theRenderer.initialise(800, 600, "Vulkan Test", &assMan);

	FVector test(20);
	FVector test2(24);
	
	test = -test;

	test.normalise();

	// Main Loop
	double lastTime = Timing::getTime();
	double deltaTime;
	while (!theRenderer.windowWantsToClose()) {
		deltaTime = Timing::getTime() - lastTime;
		lastTime = Timing::getTime();
		// if (fmod(Timing::getTime(), 1) ) std::cout << deltaTime << " seconds, " << 1 / deltaTime << " fps" << std::endl;
		glfwPollEvents();
		theRenderer.drawFrame();
	}


	theRenderer.cleanup();

	return 0;
}