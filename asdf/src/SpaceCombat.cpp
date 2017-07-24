#include "../include/SpaceCombat.h"

void SpaceCombat::spawnBullet(float x, float y){
  Entity e = _entityManager->createEntity();

	assert(_entityManager->alive(e));
  _transformSystem->add(e,glm::vec3(x,y,0.0));
  _shapeSystem->add(e, { 0,0, 1, 1}, {0,10,20,30});
  _collisionSystem->addBoxCollider(e, glm::vec3(1.0,1.0,0));
  _transformSystem->setVelocity(e, bulletSpeed * glm::normalize(glm::vec3(0.0f, -1.0f, 0.0f)));

  _data.bullets.push_back(e);
}

void SpaceCombat::update(Uint32 deltaTime){
  for(int i = 0; i < _data.bullets.size(); i++)
    {
      Entity e = _data.bullets[i];
      Entity collidedWith = _collisionSystem->getCollision(e);
      if(collidedWith.id != 0){
        _entityManager->deleteEntity(collidedWith); // replace with damage instead of insta kill
        _entityManager->deleteEntity(e);
        _data.bullets[i] = _data.bullets[_data.bullets.size() - 1];
        _data.bullets.pop_back();
      }
    }
}
