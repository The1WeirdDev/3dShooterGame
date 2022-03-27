#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Mesh.h"

class BasicMesh : Mesh {
private:
	unsigned int vbo_id = 0;
	unsigned int ebo_id = 0;
public:
	void CreateMesh(float* vertices, int* indices, int vertices_count, int indices_count);
	void DrawMesh();
	void CleanUp();
public:
	unsigned int GetVboId() { return vbo_id; }
	unsigned int GetEboId() { return ebo_id; }
};