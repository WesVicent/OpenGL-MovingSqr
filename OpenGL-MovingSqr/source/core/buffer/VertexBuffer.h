/**
	Created by: Wes Ferreira 2021-05-26
*/

#pragma once
#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include "Buffer.h"

class VertexBuffer {
protected:

public:
	unsigned int id;

	/*unsigned int indices[18] = {
		0, 1, 2, 2, 3, 0,

		4, 5, 6, 6, 7, 4,

		8, 9, 10, 10, 11, 8
	};*/

	VertexBuffer(const std::function<void()>& whenBond);
	virtual ~VertexBuffer();

private:
	unsigned int indiceBufferId;

};

VertexBuffer::VertexBuffer(const std::function<void()>& whenBond) {
	Buffer* buffer = new Buffer([&]() {
		glGenVertexArrays(1, &this->id);
		glBindVertexArray(this->id);

		whenBond();
		unsigned int* data = 0;

		if (G::INDICES.size() > 0) data = &G::INDICES[0];

		glGenBuffers(1, &this->indiceBufferId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indiceBufferId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * G::INDICES.size(), data, GL_STATIC_DRAW);

		glBindVertexArray(0); // Unbinding VAO
	});

}

VertexBuffer::~VertexBuffer() {
	glDeleteVertexArrays(1, &this->id);
	glDeleteBuffers(1, &this->indiceBufferId);
}


#endif // !VERTEX_BUFFER_H

