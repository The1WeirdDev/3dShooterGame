#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Mesh {
protected:
	unsigned int vao_id = 0;
	unsigned int vertex_count = 0;
public:
	virtual void DrawMesh();
	virtual void CleanUp();

public:
	unsigned int GenerateVao();
	unsigned int GenerateVbo(GLenum type);

	void StoreDataInAttribute(int attribute, int size, GLenum type, float* data, int data_size);

public:
	unsigned int GetVaoId() { return vao_id; }
	unsigned int GetVertexCount() { return vertex_count; }
};