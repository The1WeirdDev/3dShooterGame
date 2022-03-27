#include "Mesh.h"

void Mesh::DrawMesh() {

}
void Mesh::CleanUp() {

}

unsigned int Mesh::GenerateVao() {
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	return vao;
}
unsigned int Mesh::GenerateVbo(GLenum type) {
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(type, buffer);
	return buffer;
}

void Mesh::StoreDataInAttribute(int attribute, int size, GLenum type, float* data, int data_size) {
	/*
	glBufferData(type, sizeof(float) * data_size, data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(attribute);
	glVertexAttribPointer(attribute, size, GL_FLOAT, false, 0, 0);
	glDisableVertexAttribArray(attribute);
	*/

	glBufferData(type, sizeof(float) * data_size, data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(attribute);
	glVertexAttribPointer(attribute, size, GL_FLOAT, false, 0, 0);
	glDisableVertexAttribArray(attribute);
}