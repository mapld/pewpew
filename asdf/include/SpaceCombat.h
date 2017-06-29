#pragma once
#include "Collision.h"
#include "Spawner.h"
#include "Transform.h"

class SpaceCombat
{
public:

  SpaceCombat(){}
  SpaceCombat(EntityManager* e, Transform* t, ShapeSystem* s, Collision* c){
    _entityManager = e; _transformSystem = t; _shapeSystem = s; _collisionSystem = c;
  }

  float bulletSpeed = 40.0f;
  void spawnBullet(float x, float y);

private:
  Transform* _transformSystem;
  EntityManager* _entityManager;
  ShapeSystem* _shapeSystem;
  Collision* _collisionSystem;
};
