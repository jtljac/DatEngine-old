#pragma once
#include <GLFW\glfw3.h>
#include <iostream>

class Renderer {
protected:
	GLFWwindow* window = nullptr;
	bool framebufferResized = false;

    virtual void glfwHints() {};

	virtual void framebufferResizeCallback_internal(GLFWwindow* glfwWindow, int width, int height) {
		framebufferResized = true;
	}

private:
	static void framebufferResizeCallback(GLFWwindow* glfwWindow, int width, int height) {
		auto* app = reinterpret_cast<Renderer*>(glfwGetWindowUserPointer(glfwWindow));
		app->framebufferResizeCallback_internal(glfwWindow, width, height);
	}

public:
	virtual int initialise(int width, int height, const std::string& windowTitle) {
		glfwInit();
		glfwHints();
		this->window = glfwCreateWindow(width, height, windowTitle.c_str(), nullptr, nullptr);

		glfwSetWindowUserPointer(this->window, this);
		glfwSetFramebufferSizeCallback(this->window, framebufferResizeCallback);
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