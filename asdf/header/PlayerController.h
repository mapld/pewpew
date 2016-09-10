#pragma once
#include "InputHandler.h"
#include "Transform.h"

class PlayerController
{
public:
  PlayerController(){};
  PlayerController(Transform* t){ transformSystem = t; curEntity = e;}

  // Set player

  // Takes input and does things
  void pollInput(const InputHandler&);


private:
  Transform* transformSystem;
  Entity curEntity;
  double moveSpeed = 0.1;
};
