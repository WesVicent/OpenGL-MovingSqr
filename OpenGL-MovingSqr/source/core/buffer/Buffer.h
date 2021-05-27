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
	Buffer(const std::function<void()> &whenBond);

	// Virtual destructor to compiler automagically call base destructor on child destructior.
	virtual ~Buffer();

private:
	unsigned int id;

};

Buffer::Buffer(const std::function<void()> &whenBond) {
	glGenBuffers(1, &this->id);
	glBindBuffer(GL_ARRAY_BUFFER, this->id);

	glBufferData(GL_ARRAY_BUFFER, sizeof(G::VERTICES), G::VERTICES, GL_STATIC_DRAW);

	whenBond();

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbinding buffer
}

Buffer::~Buffer() {
	glDeleteBuffers(1, &this->id);
}

#endif // !BUFFER_H

