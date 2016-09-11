#pragma once
#include "InputHandler.h"
#include "Transform.h"

class PlayerController
{
public:
  PlayerController(){};
  PlayerController(Transform* t){ transformSystem = t; moveSpeed = 0.03f;}

  // Set player entity

  // Takes input and does things
  void update(InputHandler&);

  void setEntity(Entity e);


private:
  Transform* transformSystem;
  Entity curEntity;
  float moveSpeed;
};
