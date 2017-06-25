#include "../include/SpaceCombat.h"

void SpaceCombat::spawnBullet(float x, float y){
  Entity shot = _spawnSystem->createRect(x, y, 1.0f, 1.0f, {10,20,30,40});
  glm::vec3 velocity = bulletSpeed * glm::normalize(glm::vec3(0.0f, -1.0f, 0.0f));
  _transformSystem->setVelocity(shot, velocity);
}
