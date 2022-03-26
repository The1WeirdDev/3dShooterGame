#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Mesh.h"

class BasicMesh {
private:
	unsigned int vbo_id = 0;
	unsigned int ebo_id = 0;
public:
	void drawMesh();
	void cleanUp();
public:
	unsigned int getVboId() { return vbo_id; }
	unsigned int getEboId() { return ebo_id; }
};