/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef MAIN_LOOP_H
#define MAIN_LOOP_H

class MainLoop {
protected:

public:
	static void exec(GLFWwindow* context, Entity::Player* player, bool keypool[349], Entity::EnabledKey* enabledKeys);
private:

};

void MainLoop::exec(GLFWwindow* context, Entity::Player* player, bool keypool[349], Entity::EnabledKey* enabledKeys) {
	while (!glfwWindowShouldClose(context)) {
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);

		if (keypool != nullptr) {
			player->allowMovements(enabledKeys);
		}

		player->draw();

		glfwSwapBuffers(context);
	}

	delete player;

	glfwTerminate();
}
#endif // !MAIN_LOOP_H

