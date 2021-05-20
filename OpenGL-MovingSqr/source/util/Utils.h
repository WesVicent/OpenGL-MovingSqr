#pragma once
#ifndef UTILS_H
#define UTILS_H
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
#endif // !UTILS_H
