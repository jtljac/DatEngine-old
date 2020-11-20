#include <iostream>
#include <Platform/Timing.h>
#include <Utilities/Logging.h>
#include <Rendering/Vulkan/VulkanRenderer.h>
#include <AssetManager/AssetManager.h>
#include <AssetManager/Factories/VertShaderFactory.h>
#include <AssetManager/Factories/FragShaderFactory.h>

#include <Profiling/Profiler.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_XYZW_ONLY
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Maths/Vector.h>
#include <Maths/Matrix.h>

VulkanRenderer theRenderer;

int main() {
	AssetManager assMan;
	assMan.registerFactory<FragShader>(new FragShaderFactory());
	assMan.registerFactory<VertShader>(new VertShaderFactory());
	Timing::initialise();
	theRenderer.initialise(800, 600, "Vulkan Test", &assMan);

	float start[2][4] = {{2.f, 3.f, 4.f, 5.f}, {2.f, 3.f, 4.f, 6.f}};
	float start2[2][4] = {{3.f, 4.f, 5.f, 6.f }, {3.f, 4.f, 5.f, 7.f }};

	// glm::perspective

	FMat4 matTest = Mat<4, 4, float>::identity();

	// Mat<4, 4, float> matTest(start);
	glm::mat4 testMAT(1.f);

	glm::vec3 testVEC(2.f, 3.f, 4.f);
	glm::vec4 testVEC2(0.f, 0.f, 0.f, 1.f);

	glm::translate(testMAT, testVEC);

	testVEC2 = glm::translate(testMAT, testVEC) * testVEC2;

	FVector vecTest(4., 6., 3.);
	vecTest.normalise();

	// matTest *= matTest2;

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