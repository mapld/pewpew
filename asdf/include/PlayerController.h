#pragma once
#include "InputHandler.h"
#include "Transform.h"

class PlayerController
{
public:
  PlayerController(){};
  PlayerController(Transform* t){ transformSystem = t; moveSpeed = 50.0f;}

  // Set player entity

  // Takes input and does things
  void update(InputHandler&, Uint32 deltaTime);

  void setEntity(Entity e);


private:
  Transform* transformSystem;
  Entity curEntity;
  float moveSpeed;
};
