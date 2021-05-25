#include <iostream>
#include <sstream>
#include <string>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// TODO: Manage includes.
#include "util/Utils.h"
#include "handlers/File.h"
#include "handlers/Input.h"
#include "g_unit/Units.h"
#include "g_unit/player/Player.h"
#include "core/Application.h"

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
