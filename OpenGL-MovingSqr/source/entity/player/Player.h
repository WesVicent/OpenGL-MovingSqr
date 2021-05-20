/**
	Created by: Wes Ferreira 2020-01-05
*/

#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "../../type/Type.h"

namespace Entity {

	struct EnabledKey { // Todo: Make it an array.
		bool right;
		bool left;
		bool up;
		bool down;
	};

	class Player {
	public:
		bool canMove = false;
		//
		Player();
		~Player();
		void allowMovements(Entity::EnabledKey* key);
		void draw();

	private:
		unsigned int programShader;
		const float velocity = 0.0002f;
		int u_movement;
		unsigned int VAO, VBO, IBO;
		glm::mat4* movement = new glm::mat4(1.0);
		float vertices[12] = {
			-0.05f, -0.05f, 0.0f,
			 0.05f, -0.05f, 0.0f,
			 0.05f,  0.05f, 0.0f,
			-0.05f,  0.05f, 0.0f
		}; // Default vertices
		unsigned int indices[6] = {
			0, 1, 2,
			2, 3, 0
		}; // Default indices

		//
		void checkMovementCall(Entity::EnabledKey* key);
		Type::Coordinates calculateMovements(Entity::EnabledKey* key);
		void processShaders();
		void processBuffers();
	};

	Player::Player() {
		processShaders();
		processBuffers();

		glUseProgram(this->programShader);
		this->u_movement = glGetUniformLocation(this->programShader, "transform");
	}

	Player::~Player() {
		glDeleteVertexArrays(1, &this->VAO);
		glDeleteBuffers(1, &this->VBO);
		glDeleteBuffers(1, &this->IBO);
	}

	void Player::draw() {
		glBindVertexArray(this->VAO);
		glDrawElements(GL_TRIANGLE_STRIP, sizeof(this->indices), GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}

	void Player::processBuffers() {

		glGenVertexArrays(1, &this->VAO);
		glGenBuffers(1, &this->VBO);
		glGenBuffers(1, &this->IBO);

		glBindVertexArray(this->VAO);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbinding VBO

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indices), this->indices, GL_STATIC_DRAW);

		glBindVertexArray(0); // Unbinding VAO
	}

	void Player::processShaders() {
		const char* vertexShaderSource = File::read(Path::shaders + "player.vert");
		const char* fragmentShaderSource = File::read(Path::shaders + "player.frag");

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

	void Player::allowMovements(Entity::EnabledKey* key) {
		checkMovementCall(key);

		if (this->canMove) {
			Type::Coordinates calculated = calculateMovements(key);

			*this->movement = glm::translate(*this->movement, glm::vec3(calculated.x, calculated.y, 0.0f));

		} else *this->movement = glm::translate(*this->movement, glm::vec3(0.0f, 0.0f, 0.0f)); // Default value when start.

		glUseProgram(this->programShader);
		glUniformMatrix4fv(this->u_movement, 1, GL_FALSE, glm::value_ptr(*this->movement));
	}

	void Player::checkMovementCall(Entity::EnabledKey* key) {
		this->canMove = key->right || key->left || key->up || key->down;
	}

	Type::Coordinates Player::calculateMovements(Entity::EnabledKey* key) {
		float x = 0.0f;
		float y = 0.0f;

		if (key->right) {
			if (key->up) {
				x = velocity;
				y = velocity;
			} else if (key->down) {
				x = velocity;
				y = velocity / -2;
			} else {
				x = velocity;
				y = 0.0f;
			}
		} else if (key->left) {
			if (key->up) {
				x = velocity * -1;
				y = velocity / 2;
			} else if (key->down) {
				x = velocity * -1;
				y = velocity / -2;
			} else {
				x = velocity * -1;
				y = 0.0f;
			}
		} else if (key->up) {
			x = 0.0f;
			y = velocity;
		} else if (key->down) {
			x = 0.0f;
			y = velocity * -1;
		}

		return Type::Coordinates{ x, y };
	}
}

#endif // !PLAYER_H
