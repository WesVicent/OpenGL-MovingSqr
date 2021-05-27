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

		std::unique_ptr<G::Batch> batch = std::make_unique<G::Batch>(); // TODO: Implement more than one batch.

		batch->processShaders(); // TODO: Implement a default shader.

		auto quad = G::Primitive::createSqr(0.0f, 0.0f);
		auto quad1 = G::Primitive::createSqr(0.10f, 0.0f);
		auto quad2 = G::Primitive::createSqr(0.20f, 0.0f);

		batch->add(quad);
		batch->add(quad1);
		batch->add(quad2);

		while (!glfwWindowShouldClose(context)) {
			glfwPollEvents();

			glClear(GL_COLOR_BUFFER_BIT);


			/*for (int i = 0; i < G::UNIT_POOL.size(); i++) {
				if (G::UNIT_POOL[i] != 0)
				G::UNIT_POOL[i]->allowMovements(MainWindowSpecs::enabledKeys);
			}*/

			batch->draw();

			glfwSwapBuffers(context);
		}

		for (int i = 0; i < G::UNIT_POOL.size(); i++) {
			delete G::UNIT_POOL[i];
		}

	}
}
#endif // !MAIN_LOOP_H

