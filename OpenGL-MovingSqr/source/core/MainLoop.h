/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef MAIN_LOOP_H
#define MAIN_LOOP_H
namespace MainLoop {
	class Entity {
	protected:

	public:
		static void init(GLFWwindow* context);
	private:

	};

	void Entity::init(GLFWwindow* context) {
		while (!glfwWindowShouldClose(context)) {
			glfwPollEvents();

			glClear(GL_COLOR_BUFFER_BIT);


			/*for (int i = 0; i < G::UNIT_POOL.size(); i++) {
				if (G::UNIT_POOL[i] != 0)
				G::UNIT_POOL[i]->allowMovements(MainWindowSpecs::enabledKeys);
			}*/

			if (MainWindow::renderer->update) MainWindow::renderer->draw();

			glfwSwapBuffers(context);
		}
		

		for (int i = 0; i < G::UNIT_POOL.size(); i++) {
			delete G::UNIT_POOL[i];
		}

	}
}
#endif // !MAIN_LOOP_H

