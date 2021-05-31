/**
	Created by: Wes Ferreira 2021-05-21
*/

#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "window/MainWindow.h"
#include "MainLoop.h"
//
#include "g_unit/player/Player.h"

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

	std::vector<glm::vec4> gradient { 
		glm::vec4 { 1.0f, 0.372f, 0.427f, 1.0f },
		glm::vec4 { 1.0f, 0.372f, 0.427f, 1.0f },
		glm::vec4 { 1.0f, 0.764f, 0.443f, 1.0f },
		glm::vec4 { 1.0f, 0.764f, 0.443f, 1.0f }
	};
	auto quad2 = G::Primitive::createSqr(0.20f, 0.0f, gradient);

	std::shared_ptr<G::Batch> batch2 = std::make_shared<G::Batch>(quad2);

	std::shared_ptr player = std::make_shared<Player>(0.0f, 0.0f);

	MainWindow::renderer->addUnit(player);
	MainWindow::renderer->add(batch2);

	MainLoop::Entity::init(this->windowContext);
}

Application* Application::getInstance() {
	if(instance == 0) {
		instance = new Application();
	}

	return instance;
}

Application::~Application() {
	glfwTerminate();

	delete instance;
}

#endif // !APPLICATION_H

