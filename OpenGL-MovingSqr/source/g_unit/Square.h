/**
	Created by: Wes Ferreira 2021-05-24
*/

#pragma once
#ifndef SQUARE_H
#define SQUARE_H

class Square :public G::Unit {
public:
	static void create(float x, float y);
};

void Square::create(float x, float y) {
	auto sqr = createSqr(x, y);

	G::UNITS::add(sqr);
}


#endif // !SQUARE_H

