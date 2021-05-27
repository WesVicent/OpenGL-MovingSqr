/**
	Created by: Wes Ferreira 2021-05-21
*/

#pragma once
#ifndef UNIT_H
#define UNIT_H

#include "GUnit.h"
#include "player/Player.h"
//#include "Square.h"

namespace G {

	const int UNIT_MAX_COUNT = 1;
	const int VERTEX_MAX_AMOUNT = 4;
	
	int VERTICES_COUNT = 0;

	Unit* UNIT_POOL[G::UNIT_MAX_COUNT];

	std::vector<SqrData> POOL;
	VertexData VERTICES[G::UNIT_MAX_COUNT * G::VERTEX_MAX_AMOUNT];

	class UNITS {
		public:
			static void prepare();
			static void add(SqrData unit);
	};

	void UNITS::prepare() {
		//Square::create(0.0f, 0.0f);

		G::UNIT_POOL[0] = new Player();
	}

	void UNITS::add(SqrData unit) {
		G::POOL.push_back(unit);

		memcpy(G::VERTICES + G::VERTICES_COUNT, unit.vertices.data(), unit.size);

		G::VERTICES_COUNT = unit.vertices.size();
	}
}

#endif // !UNIT_H

