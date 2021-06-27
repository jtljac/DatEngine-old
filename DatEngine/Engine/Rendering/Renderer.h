#pragma once
#include <GLFW\glfw3.h>
#include <iostream>

class Renderer {
protected:
	GLFWwindow* window = nullptr;
	bool framebufferResized = false;

    virtual void glfwHints() {};

	virtual void framebufferResizeCallback_internal(GLFWwindow* window, int width, int height) {
		framebufferResized = true;
	}

private:
	static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
		Renderer* app = reinterpret_cast<Renderer*>(glfwGetWindowUserPointer(window));
		app->framebufferResizeCallback_internal(window, width, height);
	}
public:
	int initialise(int Width, int Height, std::string WindowTitle) {
		glfwInit();
		glfwHints();
		window = glfwCreateWindow(Width, Height, WindowTitle.c_str(), nullptr, nullptr);

		glfwSetWindowUserPointer(window, this);
		glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
		return 0;
	}

	bool windowWantsToClose() {
		return glfwWindowShouldClose(window);
	}

    virtual void cleanup() {
		glfwDestroyWindow(window);
		window = nullptr;
		glfwTerminate();
	}
};