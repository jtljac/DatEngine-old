#pragma once
#include <GLFW\glfw3.h>
#include <iostream>

class Renderer {
protected:
	GLFWwindow* window = nullptr;

	virtual void glfwHints() = 0;
public:
	int initialise(int Width, int Height, std::string WindowTitle) {
		glfwInit();
		glfwHints();
		window = glfwCreateWindow(Width, Height, WindowTitle.c_str(), nullptr, nullptr);
		return 0;
	}

	bool windowWantsToClose() {
		return glfwWindowShouldClose(window);
	}

	void cleanup() {
		glfwDestroyWindow(window);
		window = nullptr;
		glfwTerminate();
	}
};