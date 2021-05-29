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
		std::unique_ptr<VertexBuffer> buffer;
		GLuint programShader;

		static void add(SqrData unit);
		
		void processShaders();

		Batch();
	private:
	};

	Batch::Batch() {
		this->buffer = std::make_unique<VertexBuffer>([&]() {
			// Statements for when VertexBuffer is bonded.
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)0);

			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)sizeof(glm::vec3));
		});

		//processShaders(); // TODO: Implement a default shader.
	}

	void Batch::add(SqrData unit) {
		//G::POOL.push_back(unit); // This element "G::POOL" could belong to that class.

		memcpy(G::VERTICES + G::VERTICES_COUNT, unit.vertices.data(), unit.size);
		
		G::VERTICES_COUNT += unit.vertices.size();

		for(int i = 0; i < unit.indices.size(); i++) {
			unit.indices.at(i) += G::VERTICES_COUNT;
		}

		// std::copy() delegates the calls to memmove() when the type is TriviallyCopyable.
		std::copy(unit.indices.begin(), unit.indices.end(), std::back_inserter(G::INDICES));
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

