#pragma once
#ifndef UTILS_H
#define UTILS_H

#include "Path.h"
#include "namespaces/MainWindow.h"
#include "namespaces/Input.h"

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
/////////////////
#endif // !UTILS_H
