/**
	Created by: Wes Ferreira 2021-05-21
*/

#pragma once
#ifndef BATCH_H
#define BATCH_H

//#include "player/Player.h"
#include "../core/buffer/VertexBuffer.h"

namespace G {

	class Batch {
	public:
		static void add(SqrData unit);
		
		void draw();
		void processShaders();

		Batch();

	private:
		std::unique_ptr<VertexBuffer> buffer;
		GLuint programShader;
	};

	Batch::Batch() {
		this->buffer = std::make_unique<VertexBuffer>([&]() {
			// Statements for when VertexBuffer is bonded.
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)0);

			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)sizeof(glm::vec3));
		});
	}

	void Batch::add(SqrData unit) {
		G::POOL.push_back(unit); // This element "G::POOL" could belong to that class.

		memcpy(G::VERTICES + G::VERTICES_COUNT, unit.vertices.data(), unit.size);

		G::VERTICES_COUNT += unit.vertices.size();
	}

	void Batch::draw() {
		glBindBuffer(GL_ARRAY_BUFFER, this->buffer->id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(G::VERTICES), G::VERTICES, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glUseProgram(this->programShader);
		int u_movement = glGetUniformLocation(this->programShader, "movement");
		glm::mat4 movement = glm::mat4(1.0);
		movement = glm::translate(movement, glm::vec3(0.0f, 0.0f, 0.0f));

		glUniformMatrix4fv(u_movement, 1, GL_FALSE, glm::value_ptr(movement));

		glBindVertexArray(this->buffer->id);
		glDrawElements(GL_TRIANGLES, sizeof(this->buffer->indices), GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}

	void Batch::processShaders() {
		const char* vertexShaderSource = File::Handler::read(Path::shaders + "player.vert");
		const char* fragmentShaderSource = File::Handler::read(Path::shaders + "player.frag");

		GLuint vertexShader, fragmentShader;
		GLint success;

		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

		delete vertexShaderSource;
		delete fragmentShaderSource;

		// Linking shaders.
		this->programShader = glCreateProgram();
		glAttachShader(this->programShader, vertexShader);
		glAttachShader(this->programShader, fragmentShader);
		glLinkProgram(this->programShader);

		glGetProgramiv(this->programShader, GL_LINK_STATUS, &success);

		// Cleaning shaders.
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}
}

#endif // !BATCH_H

