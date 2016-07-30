#pragma once
#include "Entity.h"

// Keeps track of entities. 
// TODO: delete entity capability
class EntityManager
{
public:
	EntityManager(): entityCount(0) { };
	Entity createEntity() { entityCount++; return{ entityCount }; };
	bool alive(Entity e) { if (e.id <= entityCount) return true; else return false; };
private:
	unsigned entityCount;
};
