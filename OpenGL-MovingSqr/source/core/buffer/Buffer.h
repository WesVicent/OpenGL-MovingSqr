/**
	Created by: Wes Ferreira 2021-05-26
*/

#pragma once
#ifndef BUFFER_H
#define BUFFER_H

#include <functional>

class Buffer {
protected:

public:
	Buffer(const std::function<void()> &append);

	// Virtual destructor to compiler automagically call base destructor on child destructior.
	virtual ~Buffer();

private:
	unsigned int id;

};

Buffer::Buffer(const std::function<void()> &append) {
	glGenBuffers(1, &this->id);
	glBindBuffer(GL_ARRAY_BUFFER, this->id);

	auto quad = G::Unit::createSqr(0.0f, 0.0f);
	auto quad1 = G::Unit::createSqr(0.10f, 0.0f);
	auto quad2 = G::Unit::createSqr(0.20f, 0.0f);

	VertexData vertices[4 * 3];
	std::vector<VertexData> v;

	memcpy(vertices, quad.vertices.data(), quad.size);
	memcpy(vertices + quad.vertices.size(), quad1.vertices.data(), quad.size);
	memcpy(vertices + quad1.vertices.size() * 2, quad2.vertices.data(), quad.size);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glBufferData(GL_ARRAY_BUFFER, sizeof(G::VERTICES), G::VERTICES, GL_STATIC_DRAW);

	append();

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbinding buffer
}

Buffer::~Buffer() {
	glDeleteBuffers(1, &this->id);
}

#endif // !BUFFER_H

