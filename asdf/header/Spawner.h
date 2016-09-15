#include "Transform.h"
#include "ShapeSystem.h"

class Spawner
{
public:
  Spawner() {}
  Spawner(EntityManager* entityManager, Transform* transformSystem, ShapeSystem* shapeSystem, GraphicsSettings* graphicsSettings): _entityManager(entityManager), _transformSystem(transformSystem), _shapeSystem(shapeSystem), _graphicsSettings(graphicsSettings) {};

  void start()
  {
    curTime = 0;
    spawnInterval = 500;
    started = true;
  };
  void update(Uint32 deltaTime);
  void spawnSquare();
  Entity createSquare(float,float,SDL_Color);


private:
  EntityManager* _entityManager;
  Transform* _transformSystem;
  ShapeSystem* _shapeSystem;
  GraphicsSettings* _graphicsSettings;
  Uint32 curTime;
  Uint32 spawnInterval;
  bool started = false;
};
