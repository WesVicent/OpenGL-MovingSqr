/**
	Created by: Wes Ferreira 2021-05-24
*/

#pragma once
#ifndef RENDERER_H
#define RENDERER_H

namespace Renderer {

	class Entity {
	public:
		std::unique_ptr<G::Batch> batch;
		bool update = false;

		static std::unique_ptr<Renderer::Entity> init();
		void draw();
		void callUpdate();
		Entity();
	private:
	};

	void Entity::callUpdate() {
		update = true;
	}

	void Entity::draw() {
		glBindBuffer(GL_ARRAY_BUFFER, this->batch->buffer->id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(G::VERTICES), G::VERTICES, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glUseProgram(this->batch->programShader);
		int u_movement = glGetUniformLocation(this->batch->programShader, "movement");
		glm::mat4 movement = glm::mat4(1.0);
		movement = glm::translate(movement, glm::vec3(0.0f, 0.0f, 0.0f));

		glUniformMatrix4fv(u_movement, 1, GL_FALSE, glm::value_ptr(movement));

		glBindVertexArray(this->batch->buffer->id);
		glDrawElements(GL_TRIANGLES, sizeof(this->batch->buffer->indices), GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}

	std::unique_ptr<Renderer::Entity> Entity::init() {
		return std::make_unique<Renderer::Entity>();
	}


	Entity::Entity() {
		batch = std::make_unique<G::Batch>();
	}
}


#endif // !RENDERER_H

