/**
	Created by: Wes Ferreira 2020-01-05
*/

#pragma once
#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
	void allowMovements(Entity::EnabledKey* key);
	void draw();

public:
	Entity();
	~Entity();

private:

};

Entity::Entity() {
}

Entity::~Entity() {
}

#endif // !ENTITY_H

