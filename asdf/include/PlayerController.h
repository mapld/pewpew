#pragma once
#include "InputHandler.h"
#include "Transform.h"
#include "SpaceCombat.h"

class PlayerController
{
public:
  Uint32 shotCooldown = 300;
  float moveSpeed = 50.0f;

  PlayerController(){};
  PlayerController(Transform* t, SpaceCombat * s){ transformSystem = t; combatSystem = s;}

  void update(InputHandler&, Uint32 deltaTime);

  void setEntity(Entity e);

private:
  void shoot();

  Transform* transformSystem;
  SpaceCombat* combatSystem;
  Entity curEntity;
  Uint32 lastShotTimer;
};
