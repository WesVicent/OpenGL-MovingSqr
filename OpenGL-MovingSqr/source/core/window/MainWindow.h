/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "Window.h"
#include "MainWindowSpecs.h"


namespace MainWindow {
	class Entity : public Window, public MainWindowSpecs {
	protected:

	public:
		static GLFWwindow* init();

		~Entity();

	private:
		Entity(int width, int height, const char* title);

	};

	Entity::Entity(int width, int height, const char* title) :Window(width, height, title) { }

	GLFWwindow* Entity::init() {
		MainWindow::Entity* window = new MainWindow::Entity(MainWindowSpecs::WIDTH, MainWindowSpecs::HEIGHT, MainWindowSpecs::TITLE);

		window->bindKeyCallBack(KEY_CALLBACK);

		return window->context;
	}

	Entity::~Entity() { }
}

#endif // !MAIN_WINDOW_H

