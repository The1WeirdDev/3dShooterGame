#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Mesh {
protected:
	unsigned int vao_id;

public:
	virtual void drawMesh();
	virtual void cleanUp();

public:
	unsigned int generateVao();
	unsigned int generateVbo(GLenum type);

public:
	unsigned int getVaoId() { return vao_id; }
};