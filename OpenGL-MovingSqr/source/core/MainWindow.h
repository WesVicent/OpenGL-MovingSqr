/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "../base/Window.h";
#include "../specs/MainWindowSpecs.h";

class MainWindow : public Window {
protected:

public:
	static GLFWwindow* exec();
	
	~MainWindow();

private:
	MainWindow(int width, int height, const char* title);

};

MainWindow::MainWindow(int width, int height, const char* title) :Window(width, height, title) { }

GLFWwindow* MainWindow::exec() {
	MainWindow* window = new MainWindow(MainWindowSpecs::WIDTH, MainWindowSpecs::HEIGHT, MainWindowSpecs::TITLE);

	window->bindKeyCallBack(MainWindowSpecs::KEY_CALLBACK);

	return window->context;
}

MainWindow::~MainWindow() {
}

#endif // !MAIN_WINDOW_H

