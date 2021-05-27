/**
	Created by: Wes Ferreira 2020-01-05
*/

#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "../../core/buffer/VertexBuffer.h"

// TODO: extends private mode
class Player : public G::Unit {
public:
	bool canMove = false;
	//
	Player(float x, float y);
	Player();
	~Player();
	void virtual allowMovements(MainWindow::EnabledKeys key);
	void virtual draw();

private:
	unsigned int programShader;
	const float velocity = 0.0002f;
	int u_movement;
	//unsigned int VAO, VBO, IBO;
	glm::mat4 movement = glm::mat4(1.0);

	std::unique_ptr<VertexBuffer> buffer;


	void processShaders();
	void processBuffers();
	void checkMovementCall(MainWindow::EnabledKeys key);
	Coordinates calculateMovements(MainWindow::EnabledKeys key);
};

Player::Player() :Player(0.0f, 0.0f) { }

Player::Player(float x, float y) {
	processShaders();
	processBuffers();

	glUseProgram(this->programShader);
	this->u_movement = glGetUniformLocation(this->programShader, "transform");
	this->movement = glm::translate(this->movement, glm::vec3(x, y, 0.0f)); // Default value when start.
}

Player::~Player() {
}

void Player::draw() {
	glBindVertexArray(this->buffer->id);
	glDrawElements(GL_TRIANGLES, sizeof(this->buffer->indices), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
}

void Player::processBuffers() {
	buffer = std::make_unique<VertexBuffer>([&]() {
		// Statements for when VertexBuffer is binded.
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*) sizeof(glm::vec3));
	});
}

void Player::processShaders() {
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

void Player::allowMovements(MainWindow::EnabledKeys key) {
	checkMovementCall(key);

	if (this->canMove) {
		Coordinates calculated = calculateMovements(key);

		this->movement = glm::translate(this->movement, glm::vec3(calculated.x, calculated.y, 0.0f));

	}

	glUseProgram(this->programShader);
	glUniformMatrix4fv(this->u_movement, 1, GL_FALSE, glm::value_ptr(this->movement));
}

void Player::checkMovementCall(MainWindow::EnabledKeys key) {
	this->canMove = key.right || key.left || key.up || key.down;
}

Coordinates Player::calculateMovements(MainWindow::EnabledKeys key) {
	float x = 0.0f;
	float y = 0.0f;

	if (key.right) {
		if (key.up) {
			x = velocity;
			y = velocity;
		} else if (key.down) {
			x = velocity;
			y = velocity / -2;
		} else {
			x = velocity;
			y = 0.0f;
		}
	} else if (key.left) {
		if (key.up) {
			x = velocity * -1;
			y = velocity / 2;
		} else if (key.down) {
			x = velocity * -1;
			y = velocity / -2;
		} else {
			x = velocity * -1;
			y = 0.0f;
		}
	} else if (key.up) {
		x = 0.0f;
		y = velocity;
	} else if (key.down) {
		x = 0.0f;
		y = velocity * -1;
	}

	return Coordinates{ x, y };
}


#endif // !PLAYER_H
