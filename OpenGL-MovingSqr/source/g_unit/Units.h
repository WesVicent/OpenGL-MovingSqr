/**
	Created by: Wes Ferreira 2021-05-21
*/

#pragma once
#ifndef UNIT_H
#define UNIT_H

#include "GUnit.h"
#include "player/Player.h"

namespace G {

	const int UNIT_COUNT = 1;
	Unit* UNIT_POOL[G::UNIT_COUNT];

	class UNITS {
		public:
			static void prepare();
	};

	void UNITS::prepare() {
		G::UNIT_POOL[0] = new Player();
	}
}

#endif // !UNIT_H

