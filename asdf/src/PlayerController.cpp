#include "InputHandler.h"

void PlayerController::pollInput(const InputHandler& inputHandler)
{
  if(inputHandler.isActionDown(A_RIGHT))
    {
        glm::vec3 movement = glm::vec3(0.0,moveSpeed,0.0);
        transformSystem.setPosition(curEntity,transformSystem.getPosition + movement);
    }
}
