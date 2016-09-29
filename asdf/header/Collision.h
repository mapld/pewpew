#include "Transform.h"
#include <glm/vec3.hpp>

class Collision
{
public:
  Collision(){};
  Collision(Transform* transformSystem){ _transformSystem = transformSystem; };

  void addBoxCollider(glm::vec3 size, glm::vec3 offset = glm::vec3(0,0,0));
  void updateCollisions(Uint32 deltaTime){};

private:
  Transform* _transformSystem;
};
