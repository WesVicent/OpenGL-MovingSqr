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
		//Player* player = new Player();

		//G::UNITS::prepare();

		while (!glfwWindowShouldClose(context)) {
			glfwPollEvents();

			glClear(GL_COLOR_BUFFER_BIT);

			if (MainWindowSpecs::keypool != nullptr) {
				for (int i = 0; i < G::UNIT_MAX_COUNT; i++) {
					G::UNIT_POOL[i]->allowMovements(MainWindowSpecs::enabledKeys);
				}

				//player->allowMovements(MainWindowSpecs::enabledKeys);
			}

			for (int i = 0; i < G::UNIT_MAX_COUNT; i++) {
				G::UNIT_POOL[i]->draw();
			}

			//player->draw();

			glfwSwapBuffers(context);
		}

		for (int i = 0; i < G::UNIT_MAX_COUNT; i++) {
			delete G::UNIT_POOL[i];
		}

		//delete player;
	}
}
#endif // !MAIN_LOOP_H

