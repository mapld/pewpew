#pragma once
#include "Collision.h"
#include "Spawner.h"
#include "Transform.h"

class SpaceCombat
{
public:

  SpaceCombat(){}
  SpaceCombat(Spawner* s, Transform* t){_spawnSystem = s; _transformSystem = t;}

  float bulletSpeed = 40.0f;
  void spawnBullet(float x, float y);

private:
  Spawner* _spawnSystem;
  Transform* _transformSystem;
};
