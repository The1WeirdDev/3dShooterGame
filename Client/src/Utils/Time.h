#pragma once

#include <iostream>

#include <GLFW/glfw3.h>

class Time {
private:
	static double current_time;
	static double last_time;
	static double delta_time;

public:
	static void Init();

	static void CalculateDeltaTime();

public:
	static double getCurrentTime() { return current_time; }
	static double getLastTime() { return last_time; }
	static double getDeltaTime() { return delta_time; }
};