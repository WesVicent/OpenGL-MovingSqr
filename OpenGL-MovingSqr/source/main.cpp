#include <iostream>
#include <sstream>
#include <string>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "util/Path.h"
#include "file/File.h"
#include "input/Handler.h"
#include "input/Keys.h"
#include "entity/player/Player.h"

#include <SOIL.h>

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void printGLSLErrors(GLuint* shader, GLint success);

Entity::EnabledKey* enabledKeys = new Entity::EnabledKey();

bool keypool[349];

int main() {
	// Setup window, glew and OpenGL viewPort.
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);

	int width = 800;
	int height = 600;

	GLFWwindow* window = glfwCreateWindow(height, height, "WesFerreira OpenGL", nullptr, nullptr);

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, keyCallback);

	glewExperimental = GL_TRUE;
	glewInit();

	glViewport(0, 0, 600, 600);
	// ----------------------------------------------

	Entity::Player* player = new Entity::Player();

	// --------------------------------------------------------------------------------------
	// -------------------------------------------------------------------------------- LOOP
	// --------------------------------------------------------------------------------------
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);

		if (keypool != nullptr) {
			player->allowMovements(enabledKeys);
		}

		player->draw();

		glfwSwapBuffers(window);
	}

	delete player;

	glfwTerminate();
	return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancoe, int action, int mode) {
	Input::Handler::intercept(key, action, keypool);

	enabledKeys->right = keypool[Input::KEY::RIGHT];
	enabledKeys->left = keypool[Input::KEY::LEFT];
	enabledKeys->up = keypool[Input::KEY::UP];
	enabledKeys->down = keypool[Input::KEY::DOWN];

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

void printGLSLErrors(GLuint* shader, GLint success) {
	GLchar infoLog[512];
	if (!success) {
		glGetShaderInfoLog(*shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}
