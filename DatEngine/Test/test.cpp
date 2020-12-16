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