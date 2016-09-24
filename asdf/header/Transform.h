#pragma once
#include <vector>
#include <unordered_map>
#include <glm/vec3.hpp>
#include <SDL.h>
#include "Entity.h"
#include "EntityManager.h"

class Transform
{
public:
	struct Data
	{
		std::vector<glm::vec3> positions;
		std::vector<glm::vec3> velocities;
    std::vector<Entity> entities;
    unsigned n = 0;
	};

	Transform() {}

	void add(Entity, glm::vec3 pos = glm::vec3(0,0,0), glm::vec3 vel = glm::vec3(0,0,0));
	void destroy(Entity);

	glm::vec3 getPosition(Entity);
	void setPosition(Entity, glm::vec3);

	glm::vec3 getVelocity(Entity);
	void setVelocity(Entity, glm::vec3);

  void update(Uint32 deltaTime);

	// garbage collector that will slowly destroy components of destroyed entities
	void gc(const EntityManager&);

private:
	Data _data;
    std::unordered_map<Entity,unsigned> _map;
    unsigned gcn;

};
