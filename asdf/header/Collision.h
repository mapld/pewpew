#include "Transform.h"
#include <glm/vec3.hpp>
#include <vector>

class Collision
{
public:
  Collision(){};
  Collision(Transform* transformSystem){ _transformSystem = transformSystem; };

  struct Data
  {
    std::vector<Entity> entities;
    std::vector<glm::vec3> sizes;
    unsigned n = 0;
  };

  void addBoxCollider(Entity e,glm::vec3 size, glm::vec3 offset = glm::vec3(0,0,0))
  {
    assert(_map.find(e) == _map.end());
    _data.entities.push_back(e);
    _data.sizes.push_back(size);
    _data.n++;
    _map[e] = _data.n - 1;
  }
  void updateCollisions(Uint32 deltaTime)
  {
    // Starting with a dumb n^2 solution
    // TODO: buckets / grid
    // TODO: layers
    for(int index1 = 0; index1 < _data.n; index1++)
      {
        for(int index2 = 0; index2 < _data.n; index2++)
          {
            glm::vec3 size1 = _data.sizes[index1];
            glm::vec3 size2 = _data.sizes[index2];
          }
      }
  }

  // TODO: destruction / garbage collection

private:
  Transform* _transformSystem;
  Data _data;
  std::unordered_map<Entity,unsigned> _map;

};
