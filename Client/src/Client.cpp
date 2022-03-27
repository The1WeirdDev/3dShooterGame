#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Display/Display.h"
#include "Mesh/Meshes/BasicMesh.h"
#include "Utils/Time.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

int main(int argc, char** argv) {
	int width = 1920;
	int height = 1080;
	const char* title = "Client - Shooter";

	Display::CreateWindow(width, height, title);

	float* vertices = new float[12] {
		0, 0, -.9,
		0, 1, -.9,
		1, 0, -.9,
		1, 1, -.9
	};

	int* indices = new int[6]{
		0, 1, 2, 2, 1, 3
	};

	BasicMesh mesh;
	mesh.CreateMesh(vertices, indices, 12, 6);

	Time::Init();
	while (Display::ShouldUpdate()) {
		Display::PreUpdate();
		Time::CalculateDeltaTime();

		Display::Prepare();

		mesh.DrawMesh();

		Display::PostUpdate();
	}
	mesh.CleanUp();
	Display::DestroyWindow();
	glfwTerminate();
	return 0;
}