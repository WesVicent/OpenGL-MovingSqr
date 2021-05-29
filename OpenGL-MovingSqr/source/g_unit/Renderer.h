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

		void add(SqrData unit);
		void fillBuffer();
		void draw();
		void updateUniforms();
		void callUpdate();
		Entity();
	private:
	};

	void Entity::add(SqrData unit) {
		for(int i = 0; i < unit.indices.size(); i++) {
			unit.indices.at(i) += G::VERTICES_COUNT;
		}

		// std::copy() delegates the calls to memmove() when the type is TriviallyCopyable.
		std::copy(unit.indices.begin(), unit.indices.end(), std::back_inserter(G::INDICES));
		
		//G::POOL.push_back(unit); // This element "G::POOL" could belong to that class.

		memcpy(G::VERTICES + G::VERTICES_COUNT, unit.vertices.data(), unit.size);
		G::VERTICES_COUNT += unit.vertices.size();


	}

	void Entity::fillBuffer() {
		batch = std::make_unique<G::Batch>();
	}

	void Entity::updateUniforms() {
		glUseProgram(this->batch->programShader);
		int u_movement = glGetUniformLocation(this->batch->programShader, "movement");
		glm::mat4 movement = glm::mat4(1.0);
		movement = glm::translate(movement, glm::vec3(0.5f, 0.0f, 0.0f));

		glUniformMatrix4fv(u_movement, 1, GL_FALSE, glm::value_ptr(movement));
	}

	void Entity::callUpdate() {
		update = true;
	}

	void Entity::draw() {
		// LOOP
		glBindBuffer(GL_ARRAY_BUFFER, this->batch->buffer->id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(G::VERTICES), G::VERTICES, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// LOOP


		glBindVertexArray(this->batch->buffer->id);
		glDrawElements(GL_TRIANGLES, sizeof(unsigned int) * G::INDICES.size(), GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}

	std::unique_ptr<Renderer::Entity> Entity::init() {
		return std::make_unique<Renderer::Entity>();
	}

	Entity::Entity() { }
}


#endif // !RENDERER_H

