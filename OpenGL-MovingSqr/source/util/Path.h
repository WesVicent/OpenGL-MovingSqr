/**
	Created by: Wes Ferreira 2019-12-28
*/

#pragma once

#ifndef PATH_H
#define PATH_H

#include <filesystem>

namespace Path {
	std::string shaders = std::filesystem::path("resource/shaders/").string();
	std::string textures = std::filesystem::path("resource/textures/").string();
}
#endif // !PATH_H

