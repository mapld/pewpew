#pragma once
#include <vector>
#include <glm/vec3.hpp>
#include "Entity.h" 
#include "EntityManager.h"

class Transform
{
public:
	struct Data
	{
		std::vector<glm::vec3> positions;
	};

	Transform() {}
	void add(Entity, glm::vec3 pos = glm::vec3(0,0,0));
	void destroy(Entity);

	glm::vec3 getPosition(Entity);
	void setPosition(Entity, glm::vec3);

	// garbage collector that will slowly destroy components of destroyed entities
	void gc(const EntityManager&);

	Data _data;
};