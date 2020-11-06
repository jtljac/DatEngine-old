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
#include <glm/gtc/matrix_transform.hpp>

#include <Maths/Vector.h>
#include <Maths/Matrices/MatForward.h>

VulkanRenderer theRenderer;

int main() {
	AssetManager assMan;
	assMan.registerFactory<FragShader>(new FragShaderFactory());
	assMan.registerFactory<VertShader>(new VertShaderFactory());
	Timing::initialise();
	theRenderer.initialise(800, 600, "Vulkan Test", &assMan);

	float start[2][4] = {{2.f, 3.f, 4.f, 5.f}, {2.f, 3.f, 4.f, 6.f}};

	glm::perspective

	Mat<4, 2, float> matTest(start);

	float test = matTest[1][2];

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