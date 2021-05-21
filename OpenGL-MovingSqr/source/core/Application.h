/**
	Created by: Wes Ferreira 2020-01-05
*/

#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "MainWindow.h"
#include "MainLoop.h"

class Application { // Singleton
protected:
public:
	GLFWwindow* windowContext;
	Entity::Player* player;

	static Application* getInstance(GLFWkeyfun keyCallback, bool keypool[349], Entity::EnabledKey* enabledKeys);
	~Application();

private:
	static Application* instance;
	Application(GLFWkeyfun keyCallback, bool keypool[349], Entity::EnabledKey* enabledKeys);

};
Application* Application::instance = 0;

Application* Application::getInstance(GLFWkeyfun keyCallback, bool keypool[349], Entity::EnabledKey* enabledKeys) {
	if (instance == 0) {
		instance = new Application(keyCallback, keypool, enabledKeys);
	}

	return instance;
}

Application::Application(GLFWkeyfun keyCallback, bool keypool[349], Entity::EnabledKey* enabledKeys) {
	this->windowContext = MainWindow::exec(keyCallback);

	this->player = new Entity::Player();

	MainLoop::exec(this->windowContext, this->player, keypool, enabledKeys);
}

Application::~Application() {
}

#endif // !APPLICATION_H

