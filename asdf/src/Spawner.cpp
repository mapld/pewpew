#include "../include/Spawner.h"
#include "../include/Random.h"
#include <glm/glm.hpp>

void Spawner::update(Uint32 deltaTime)
{
  if(!started) return;
  curTime += deltaTime;

  // spawn new objects on a fixed interval
  if (curTime > spawnInterval)
    {
      spawnSquare();
      curTime -= spawnInterval;
    }
}

// Spawns a square with a random location and velocity
void Spawner::spawnSquare()
{
  using namespace alrm_random;

  float x = floatInRange(5.0f,50.0f);
  float y = floatInRange(5.0f,50.0f);

  float width = 4.0;
  float height = 4.0;
  Entity square = createRect(x,y,width,height,_graphicsSettings->defaultSquareColor);

  float speed = 5.0f;
  float vx = floatInRange(-1.0f,1.0f);
  float vy = floatInRange(-1.0f,1.0f);
  glm::vec3 velocity = speed * glm::normalize(glm::vec3(vx,vy,0.0f));
  _transformSystem->setVelocity(square, velocity);
}

Entity Spawner::createRect(float x, float y, float w, float h, SDL_Color color)
{
	Entity e = _entityManager->createEntity();

	assert(_entityManager->alive(e));
  _transformSystem->add(e,glm::vec3(x,y,0.0));
  _shapeSystem->add(e, { 0,0, (int)w,(int)h}, color);
  _collisionSystem->addBoxCollider(e, glm::vec3(w,h,0));
  return e;
}
