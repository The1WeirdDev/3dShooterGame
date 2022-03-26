#pragma once

#include <iostream>

//Graphics
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Display {
private:
	static unsigned int width;
	static unsigned int height;
	static const char* title;

	static GLFWwindow* window;

public:
	static void CreateWindow(unsigned int width, unsigned int height, const char* title);
	static void DestroyWindow();

	static bool ShouldUpdate() { return !glfwWindowShouldClose(window); }
	static void PreUpdate();
	static void Prepare();
	static void PostUpdate();

};