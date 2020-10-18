#include <iostream>
#include <Windows.h>
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
	theRenderer.initialise(800, 600, "Vulkan Test", &assMan);


	// Main Loop
	LARGE_INTEGER Frequency;
	QueryPerformanceFrequency(&Frequency);
	LARGE_INTEGER LastTime, newTime;
	QueryPerformanceCounter(&LastTime);
	double deltaTime = 0.f;
	while (!theRenderer.windowWantsToClose()) {
		// QueryPerformanceCounter(&newTime);
		// deltaTime = ((double) (newTime.QuadPart - LastTime.QuadPart)) / Frequency.QuadPart;
		// QueryPerformanceCounter(&LastTime);
		// std::cout << deltaTime << " seconds" << std::endl;
		glfwPollEvents();
		theRenderer.drawFrame();
		
	}


	theRenderer.cleanup();

	return 0;
}