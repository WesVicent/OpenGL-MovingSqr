/**
	Re-created by: Wes Ferreira 2021-05-21
*/

#pragma once
#ifndef G_UNIT_H
#define G_UNIT_H

namespace G {
	class Unit {
	protected:

	public:
		static SqrData createSqr(float x, float y);
		void virtual allowMovements(MainWindow::EnabledKeys key) = 0;
		void virtual draw() = 0;

		virtual ~Unit() {}; //TODO:

	private:
		unsigned int VAO, VBO, IBO;

		void processShaders();
		void processBuffers();

	};

	//void Unit::processBuffers() {
	//	glGenVertexArrays(1, &this->VAO);
	//	glBindVertexArray(this->VAO);

	//	glGenBuffers(1, &this->VBO);
	//	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	//	glBufferData(GL_ARRAY_BUFFER, sizeof(G::VERTICES), G::VERTICES, GL_STATIC_DRAW);

	//	glEnableVertexAttribArray(0);
	//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)0);

	//	glEnableVertexAttribArray(1);
	//	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)sizeof(glm::vec3));

	//	glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbinding VBO

	//	glGenBuffers(1, &this->IBO);
	//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->IBO);
	//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indices), this->indices, GL_STATIC_DRAW);

	//	glBindVertexArray(0); // Unbinding VAO
	//}

	//void Unit::processShaders() {
	//	const char* vertexShaderSource = File::Handler::read(Path::shaders + "player.vert");
	//	const char* fragmentShaderSource = File::Handler::read(Path::shaders + "player.frag");

	//	GLuint vertexShader, fragmentShader;
	//	GLint success;

	//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	//	glCompileShader(vertexShader);

	//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//	glCompileShader(fragmentShader);

	//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	//	// Linking shaders.
	//	this->programShader = glCreateProgram();
	//	glAttachShader(this->programShader, vertexShader);
	//	glAttachShader(this->programShader, fragmentShader);
	//	glLinkProgram(this->programShader);

	//	glGetProgramiv(this->programShader, GL_LINK_STATUS, &success);

	//	// Cleaning shaders.
	//	glDeleteShader(vertexShader);
	//	glDeleteShader(fragmentShader);
	//}

	SqrData Unit::createSqr(float x, float y) {
		VertexData v0, v1, v2, v3;
		float size = 0.05f;

		v0.position = glm::vec3{ x, y, 0.0f };
		v0.color = glm::vec4{ 0.019f, 0.588f, 1.0f, 1.0f };

		v1.position = glm::vec3{ x + size, y, 0.0f };
		v1.color = glm::vec4{ 0.019f, 0.588f, 1.0f, 1.0f };

		v2.position = glm::vec3{ x + size, y + size, 0.0f };
		v2.color = glm::vec4{ 0.019f, 0.588f, 1.0f, 1.0f };

		v3.position = glm::vec3{ x, y + size, 0.0f };
		v3.color = glm::vec4{ 0.019f, 0.588f, 1.0f, 1.0f };

		return { v0, v1, v2, v3 };
	}
}

#endif // !G_UNIT_H

