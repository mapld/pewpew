#include "../header/PlayerController.h"
#include <glm/glm.hpp>

void PlayerController::update(InputHandler& inputHandler)
{
  glm::vec3 movement = glm::vec3(0.0,0.0,0.0);
  if(inputHandler.isActionDown(A_RIGHT))
    {
      movement += glm::vec3(1.0,0.0,0.0);
    }
  if(inputHandler.isActionDown(A_LEFT))
    {
      movement += glm::vec3(-1.0,0.0,0.0);
    }
  if(inputHandler.isActionDown(A_DOWN))
    {
      movement += glm::vec3(0.0,1.0,0.0);
    }
  if(inputHandler.isActionDown(A_UP))
    {
      movement += glm::vec3(0.0,-1.0,0.0);
    }
  if (glm::length(movement) == 0)
  {
	  return;
  }
  movement = glm::normalize(movement);
  movement = moveSpeed * movement;
  transformSystem->setPosition(curEntity,transformSystem->getPosition(curEntity) + movement);
}

void PlayerController::setEntity(Entity e)
{
  curEntity = e;
}
