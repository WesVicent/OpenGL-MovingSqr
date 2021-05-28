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

	static Application* getInstance();
	~Application();

private:
	static Application* instance;

	Application();

};
Application* Application::instance = 0;


Application::Application() {
	this->windowContext = MainWindow::Entity::init();
	
	MainWindow::renderer = Renderer::Entity::init();

	auto quad = G::Primitive::createSqr(0.0f, 0.0f);
	auto quad1 = G::Primitive::createSqr(0.10f, 0.0f);
	auto quad2 = G::Primitive::createSqr(0.20f, 0.0f);

	MainWindow::renderer->batch->add(quad);
	MainWindow::renderer->batch->add(quad1);
	MainWindow::renderer->batch->add(quad2);
	MainWindow::renderer->callUpdate();

	MainLoop::Entity::init(this->windowContext);
}

Application* Application::getInstance() {
	if (instance == 0) {
		instance = new Application();
	}

	return instance;
}

Application::~Application() {
	glfwTerminate();

	delete[] windowContext;
	delete instance;
}

#endif // !APPLICATION_H

