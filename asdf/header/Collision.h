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
    std::vector<glm::vec3> sizes;
  };

  void addBoxCollider(glm::vec3 size, glm::vec3 offset = glm::vec3(0,0,0));
  void updateCollisions(Uint32 deltaTime){};

private:
  Transform* _transformSystem;
};
