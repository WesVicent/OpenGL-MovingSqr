/**
	Created by: Wes Ferreira 2021-05-21
*/

#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "window/MainWindow.h"
#include "MainLoop.h"

class Application { // Singleton
protected:
public:
	GLFWwindow* windowContext;
	Entity::Player* player;

	static Application* getInstance();
	~Application();

private:
	static Application* instance;

	Application();

};
Application* Application::instance = 0;


Application::Application() {
	this->windowContext = MainWindow::exec();

	this->player = new Entity::Player();

	MainLoop::exec(this->windowContext, this->player);
}

Application* Application::getInstance() {
	if (instance == 0) {
		instance = new Application();
	}

	return instance;
}

Application::~Application() {
}

#endif // !APPLICATION_H

