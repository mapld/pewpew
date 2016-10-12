#include "../header/World.h"

void World::update(Uint32 deltaTime)
{
  transformSystem.gc(entityManager);
  shapeSystem.cleanUp(entityManager);
  collisionSystem.cleanUp(entityManager);

  spawnerSystem.update(deltaTime);
  playerController.update(inputHandler, deltaTime);

  transformSystem.update(deltaTime);
  collisionSystem.updateCollisions(deltaTime);

  shapeSystem.updatePositions(transformSystem);

}

void World::draw()
{
	SDL_Color bgColor = graphicsSettings.backgroundColor;
	SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
	SDL_RenderClear(renderer);

	shapeSystem.draw();

	SDL_RenderPresent(renderer);
}

