#include "Transform.h"
#include "ShapeSystem.h"

class Spawner
{
public:
  Spawner() {}
  Spawner(Transform* transformSystem, ShapeSystem* shapeSystem): _transformSystem(transformSystem), _shapeSystem(shapeSystem) {};

  void start();
  void update(Uint32 deltaTime);

private:
  Transform* _transformSystem;
  ShapeSystem* _shapeSystem;
};
