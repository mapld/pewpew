#include "../include/SpaceCombat.h"

void SpaceCombat::spawnBullet(float x, float y){
  Entity e = _entityManager->createEntity();

	assert(_entityManager->alive(e));
  _transformSystem->add(e,glm::vec3(x,y,0.0));
  _shapeSystem->add(e, { 0,0, 1, 1}, {0,10,20,30});
  _collisionSystem->addBoxCollider(e, glm::vec3(1.0,1.0,0));
  _transformSystem->setVelocity(e, bulletSpeed * glm::normalize(glm::vec3(0.0f, -1.0f, 0.0f)));
}
