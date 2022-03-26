#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Display/Display.h"
#include "Utils/Time.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

int main(int argc, char** argv) {
	int width = 1920;
	int height = 1080;
	const char* title = "Client - Shooter";

	Display::CreateWindow(width, height, title);

	Time::Init();
	while (Display::ShouldUpdate()) {
		Display::PreUpdate();
		Time::CalculateDeltaTime();



		Display::Prepare();

		Display::PostUpdate();
	}
	Display::DestroyWindow();
	glfwTerminate();
	return 0;
}