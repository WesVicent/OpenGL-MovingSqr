/**
	Created by: Wes Ferreira 2019-12-28
*/

#pragma once

#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <sstream>
#include "../util/Utils.h"

class File {
public:
	static const char* read(std::string fileName);

private:

};

const char* File::read(std::string fileName) {
	std::stringstream content;
	std::string line;
	std::ifstream file(fileName);

	if (file.is_open()) {
		while (std::getline(file, line)) {
			content << line << '\n';
		}
		file.close();
	} else {
		std::cout << "Unable to open file: " + fileName << std::endl;
	}

	// The c_str() function return haven't reference on another scope, to keep reference we clone it return.
	return Utils::strclone(content.str().c_str());
}

#endif // !FILE_H
