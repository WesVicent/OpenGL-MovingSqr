/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef WINDOW_H
#define WINDOW_H

class Window {
protected:
	Window(int width, int height, const char* title, GLFWkeyfun keyCallback);

	void setKeyCallBack(GLFWwindow* window, GLFWkeyfun cbfun); // TODO: test set key callback in another app's state.

	GLFWwindow* context;

public:
	// Virtual destructor to compiler automagically call base destructor on child destructior.
	virtual ~Window();

private:
	

};

Window::Window(int width, int height, const char* title, GLFWkeyfun keyCallback) {
	glfwInit();

	// Setting up OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
	///////////////////

	this->context = glfwCreateWindow(width, height, title, nullptr, nullptr);

	glfwMakeContextCurrent(context);

	glfwSetKeyCallback(context, keyCallback); // TODO: test set key callback in another app's state.

	glewExperimental = GL_TRUE;
	glewInit();

	glViewport(0, 0, width, height);
}

Window::~Window() {
}

#endif // !WINDOW_H

