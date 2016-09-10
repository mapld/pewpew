#pragma once
#include "InputHandler.h"
#include "Transform.h"

class PlayerController
{
public:
  PlayerController(){};
  PlayerController(Transform* t){ transformSystem = t;}

  // Takes input and does things
  void pollInput(const InputHandler&);


private:
  Transform* transformSystem;
};
