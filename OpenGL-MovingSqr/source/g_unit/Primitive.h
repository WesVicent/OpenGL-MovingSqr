/**
	created by: Wes Ferreira 2021-05-27
*/

#pragma once
#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "Controllable.h"

namespace G {

	class Primitive {
	protected:

	public:
		static SqrData createSqr(float x, float y);

		virtual ~Primitive() {}; //TODO:

	private:
	};

	SqrData Primitive::createSqr(float x, float y) {
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

	std::array<G::Primitive*, G::UNIT_MAX_COUNT> UNIT_POOL;
	std::vector<SqrData> POOL;
	VertexData VERTICES[G::UNIT_MAX_COUNT * G::VERTEX_MAX_AMOUNT];
}

#endif // !PRIMITIVE_H

