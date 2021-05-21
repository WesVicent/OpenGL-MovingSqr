/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "../base/Window.h";
#include "../const/WindowConfig.h";

class MainWindow : public Window {
protected:

public:
	static GLFWwindow* exec(GLFWkeyfun keyCallback);
	~MainWindow();

private:
	MainWindow(int width, int height, const char* title, GLFWkeyfun keyCallback);

};

MainWindow::MainWindow(int width, int height, const char* title, GLFWkeyfun keyCallback) :Window(width, height, title, keyCallback) {

}

GLFWwindow* MainWindow::exec(GLFWkeyfun keyCallback) {
	MainWindow* window = new MainWindow(WindowConfig::WIDTH, WindowConfig::HEIGHT, WindowConfig::TITLE, keyCallback);

	return window->context;
}

MainWindow::~MainWindow() {
}

#endif // !MAIN_WINDOW_H

