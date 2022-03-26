#include "Mesh.h"

void Mesh::drawMesh() {

}
void Mesh::cleanUp() {

}


unsigned int Mesh::generateVao() {
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	return vao;
}
unsigned int Mesh::generateVbo(GLenum type) {
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(type, buffer);
	return buffer;
}