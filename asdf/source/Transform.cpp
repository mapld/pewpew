#include "../header/Transform.h"

void Transform::add(Entity e, glm::vec3 pos)
{
    _data.entities.push_back(e); 
    _data.positions.push_back(pos);
    //todo: map
}
