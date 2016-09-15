#include "../header/Spawner.h"


void Spawner::update(Uint32 deltaTime)
{
  if(!started) return;

  curTime += deltaTime;

  if (curTime > spawnInterval)
    {
      spawnSquare();
      curTime -= spawnInterval;
    }
}

void Spawner::spawnSquare()
{
  float x = 20.0f;
  float y = 20.0f;
  createSquare(x,y,_graphicsSettings->defaultSquareColor);
}

Entity Spawner::createSquare(float x, float y, SDL_Color color)
{
	Entity e = _entityManager->createEntity();

	assert(_entityManager->alive(e));
  _transformSystem->add(e,glm::vec3(x,y,0.0));
  _shapeSystem->add(e, { 0,0,50,50 }, color);
  return e;
}
