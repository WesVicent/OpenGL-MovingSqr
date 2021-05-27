#pragma once
#ifndef UTILS_H
#define UTILS_H

#include "Path.h"
#include "namespaces/MainWindow.h"
#include "namespaces/Input.h"
#include "namespaces/G.h"

struct Utils {

	// Handmade "strcpy" by Paker
	static const char* strclone(const char* src) {
		int size = strlen(src) + 1;
		char* dest = (char*)malloc(sizeof(char) * size);

		if (dest != 0) {
			memcpy(dest, src, size);
		}

		return dest;
	}
};

// USEFUL STRUCTS
struct Coordinates {
	float x;
	float y;
};

struct VertexData {
	glm::vec3 position;
	glm::vec4 color;
};

struct SqrData {
	VertexData v0;
	VertexData v1;
	VertexData v2;
	VertexData v3;

	std::array<VertexData, 4> vertices = { v0, v1, v2, v3 };

	int size = 4 * sizeof(VertexData);
};

/////////////////
#endif // !UTILS_H
