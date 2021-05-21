#include <iostream>
#include <sstream>
#include <string>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "structs.h"
#include "util/Path.h"
#include "file/File.h"
#include "input/Handler.h"
#include "input/Keys.h"
#include "entity/player/Player.h"
#include "core/Application.h"

#include <SOIL.h>

void printGLSLErrors(GLuint* shader, GLint success);

int main() {
	Application* app = Application::getInstance();

	return 0;
}

void printGLSLErrors(GLuint* shader, GLint success) {
	GLchar infoLog[512];
	if (!success) {
		glGetShaderInfoLog(*shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}
