#include "BasicMesh.h"

void BasicMesh::CreateMesh(float* vertices, int* indices, int vertices_count, int indices_count) {
	//Vertex Array
	vao_id = GenerateVao();

	//Vertices
	vbo_id = GenerateVbo(GL_ARRAY_BUFFER);
	StoreDataInAttribute(0, 3, GL_ARRAY_BUFFER, vertices, vertices_count);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Indices
	ebo_id = GenerateVbo(GL_ELEMENT_ARRAY_BUFFER);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices_count, indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
	//Unbinding and setting Vertex Count
	glBindVertexArray(0);
	vertex_count = indices_count;
}

void BasicMesh::DrawMesh() {
	//Binding Vao, Vbo, and Ebo
	glBindVertexArray(vao_id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);

	glEnableVertexAttribArray(0);
	glDrawElements(GL_TRIANGLES, vertex_count, GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);

	//Unbinding Vao, Vbo, and Ebo
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
void BasicMesh::CleanUp() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glDeleteBuffers(1, &vbo_id);
	glDeleteBuffers(1, &ebo_id);
	glDeleteVertexArrays(1, &vao_id);

}