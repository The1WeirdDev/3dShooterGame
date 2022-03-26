#include "Display.h"

unsigned int Display::width = 0;
unsigned int Display::height = 0;
const char* Display::title = nullptr;

GLFWwindow* Display::window = nullptr;

void Display::CreateWindow(unsigned int width, unsigned int height, const char* title) {
	//Setting Data
	Display::width = width;
	Display::height = height;
	Display::title = title;

	if (!glfwInit()) {
		std::cout << "Unable to initialize GLFW" << std::endl;
		std::exit(-1);
	}

	//Creating Window
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Unable to create Window" << std::endl;
		glfwTerminate();
		std::exit(-1);
	}

	//Setting Window Position
	GLFWvidmode* videoMode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(window, (videoMode->width - width) / 2, (videoMode->height - height) / 2);
	glfwMakeContextCurrent(window);

	//Initializing GLEW
	if (glewInit() != GLEW_OK) {
		std::cout << "Unable to initialize GLEW" << std::endl;
		glfwDestroyWindow(window);
		glfwTerminate();
		std::exit(-1);
	}


}

void Display::DestroyWindow() {
	glfwDestroyWindow(window);
}

void Display::PreUpdate() {
	glfwSwapBuffers(window);
}
void Display::Prepare() {
	glClearColor(0.0, 0.5, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
}
void Display::PostUpdate() {
	glDisable(GL_DEPTH_TEST);
	glfwPollEvents();
}