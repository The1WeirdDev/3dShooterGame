#include "Time.h"

double Time::current_time = 0.0;
double Time::last_time = 0.0;
double Time::delta_time = 0.0;

void Time::Init() {
	current_time = glfwGetTime();
	last_time = current_time;
	delta_time = 0;
}

void Time::CalculateDeltaTime() {
	current_time = glfwGetTime();
	delta_time = current_time - delta_time;
	last_time = current_time;
}