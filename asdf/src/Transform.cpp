#include "../header/Transform.h"
#include <stdio.h>

void Transform::add(Entity e, glm::vec3 pos, glm::vec3 vel)
{
  assert(_map.find(e) == _map.end());
    _data.entities.push_back(e);
    _data.positions.push_back(pos);
    _data.velocities.push_back(vel);
    _data.n++;
    _map[e] = _data.n - 1;
}

void Transform::destroy(Entity e)
{
    assert(_map.find(e) != _map.end());
    unsigned i = _map[e];
    unsigned end = _data.n - 1;

    _data.entities[i] = _data.entities[end];
    _data.entities.pop_back();

    _data.positions[i] = _data.positions[end];
    _data.positions.pop_back();

    _data.velocities[i] = _data.velocities[end];
    _data.velocities.pop_back();

    _data.n--;

	if (i < _data.n)
	{
		_map[_data.entities[i]] = i;
	}

	_map.erase(e);
}

glm::vec3 Transform::getPosition(Entity e)
{
  printf("Getting position of entity %d \n", e);
  assert(_map.find(e) != _map.end());
  unsigned i = _map[e];
  return _data.positions[i];
}

void Transform::setPosition(Entity e, glm::vec3 v)
{
  assert(_map.find(e) != _map.end());
  unsigned i = _map[e];
  _data.positions[i] = v;
}

glm::vec3 Transform::getVelocity(Entity e)
{
  assert(_map.find(e) != _map.end());
  unsigned i = _map[e];
  return _data.velocities[i];
}

void Transform::setVelocity(Entity e, glm::vec3 v)
{
  assert(_map.find(e) != _map.end());
  unsigned i = _map[e];
  _data.velocities[i] = v;
}

void Transform::gc(const EntityManager& em)
{
  unsigned num_check = 5;

  // todo: change this to use randomness?
  if ( gcn > _data.n) gcn = 0;

	if (gcn + num_check >= _data.n)
	{
		num_check = _data.n - gcn;
	}

    for (unsigned i = 0; i < num_check; i++)
    {
        Entity e = _data.entities[gcn];
        if (!em.alive(e))
        {
            destroy(e);
            num_check--;
        }
        gcn++;
    }
}

void Transform::update(Uint32 deltaTime)
{
  float t = static_cast<float>(deltaTime) / 1000.0f;
  for(unsigned i = 0; i < _data.n;i++)
    {
      _data.positions[i] += t * _data.velocities[i];
    }
}

