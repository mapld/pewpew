#include "../header/Transform.h"

void Transform::add(Entity e, glm::vec3 pos)
{
    _data.entities.push_back(e); 
    _data.positions.push_back(pos);
    _data.n++;
    _map[e] = _data.n - 1;
}

void Transform::destroy(Entity e)
{
    assert(_map.find(e) != _map.end());
    unsigned i = _map[e];
    unsigned end = _data.n - 1; 
     
    _data.positions[i] = _data.positions[end];
    _data.positions.pop_back();

    _data.entities[i] = _data.entities[end];
    _data.entities.pop_back();
    
    _data.n--;
}

glm::vec3 Transform::getPosition(Entity e)
{
    assert(_map.find(e) != _map.end());
    unsigned i = _map[e];
    return _data.positions[i];      
}

void Transform::setPosition(Entity e, glm::vec3 v)
{
    assert(_map.find(e) != _map.end());
    unsigned i = _map[e];
}

void Transform::gc(const EntityManager& em)
{
    unsigned num_check = 5;
    // todo: change this to random?
    if ( gcn > _data.n) gcn = 0;
    if ( gcn + num_check > _data.n) num_check = _data.n - gcn;

    for (unsigned i = 0; i < num_check; i++)
    {
        Entity e = _data.entities[gcn];
        if (!em.alive(e))
        {
            destroy(e);
        }
        gcn++; 
    }
}

