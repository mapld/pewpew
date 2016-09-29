#include "../header/World.h"

void World::update(Uint32 deltaTime)
{
  spawnerSystem.update(deltaTime);

  transformSystem.update(deltaTime);

  playerController.update(inputHandler, deltaTime);
  shapeSystem.updatePositions(transformSystem);
  collisionSystem.updateCollisions(deltaTime);

  transformSystem.gc(entityManager);
  shapeSystem.cleanUp(entityManager);
}

void World::draw()
{
	SDL_Color bgColor = graphicsSettings.backgroundColor;
	SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
	SDL_RenderClear(renderer);

	shapeSystem.draw();

	SDL_RenderPresent(renderer);
}

