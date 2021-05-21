/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef WINDOW_CONFIG_H
#define WINDOW_CONFIG_H

class MainWindowSpecs {
public:
	static const int WIDTH = 800;
	static const int HEIGHT = 800;
	static const char* TITLE;

	static bool keypool[349];
	static EnabledKeys enabledKeys;

protected:
	static void KEY_CALLBACK(GLFWwindow* window, int key, int scancoe, int action, int mode);
};

// STATIC INIT
const char* MainWindowSpecs::TITLE = "WesFerreira OpenGL";
EnabledKeys MainWindowSpecs::enabledKeys = EnabledKeys();
bool MainWindowSpecs::keypool[349] = {};
//////////////

void MainWindowSpecs::KEY_CALLBACK(GLFWwindow* window, int key, int scancoe, int action, int mode) {
	Input::Handler::intercept(key, action, MainWindowSpecs::keypool);

	MainWindowSpecs::enabledKeys.right = MainWindowSpecs::keypool[Input::KEY::RIGHT];
	MainWindowSpecs::enabledKeys.left = MainWindowSpecs::keypool[Input::KEY::LEFT];
	MainWindowSpecs::enabledKeys.up = MainWindowSpecs::keypool[Input::KEY::UP];
	MainWindowSpecs::enabledKeys.down = MainWindowSpecs::keypool[Input::KEY::DOWN];

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

#endif // !WINDOW_CONFIG_H

