#include "../include/PlayerController.h"
#include <glm/glm.hpp>

void PlayerController::shoot(){
  printf("Shooting\n");
  glm::vec3 playerPosition = transformSystem->getPosition(curEntity);
  glm::vec3 bulletPosition = playerPosition + glm::vec3(0.0,-4.0,0.0);
  combatSystem->spawnBullet(bulletPosition.x, bulletPosition.y);
}

void PlayerController::update(InputHandler& inputHandler, Uint32 deltaTime)
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
  if (glm::length(movement) != 0)
  {
    movement = glm::normalize(movement);
    movement = moveSpeed * movement;
  }
  transformSystem->setVelocity(curEntity,movement);

  if(lastShotTimer < shotCooldown){
    lastShotTimer += deltaTime;
  }
  else if(inputHandler.isActionDown(A_SHOOT)){
    shoot();
    lastShotTimer = 0;
  }
}

void PlayerController::setEntity(Entity e)
{
  curEntity = e;
}

