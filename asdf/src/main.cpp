#include <SDL.h>
#include <assert.h>
#include <stdio.h>
#include <glm/vec3.hpp>

#include "../header/World.h"

Entity createSquare(World& world, double x, double y)
{
	Entity e = world.entityManager.createEntity();

	assert(world.entityManager.alive(e));
    world.transformSystem.add(e,glm::vec3(x,y,0.0));
	world.shapeSystem.add(e, { 0,0,50,50 }, world.graphicsSettings.defaultSquareColor);
	return e;
}

// Sets up initial world entities
void initWorld(World& world)
{
	Entity s1 = createSquare(world, 50, 50);
	assert(world.entityManager.alive(s1));

	Entity s2 = createSquare(world, 150, 50);
  std::string blah;

	world.entityManager.deleteEntity(s2);
	assert(!world.entityManager.alive(s2));

}

int main(int argc, char* args[])
{
	// Init graphics setings.
	GraphicsSettings gSettings;

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("PEWPEW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gSettings.screenWidth, gSettings.screenHeight, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Failed to create window. SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			// Create the world and all its systems.
			World* world = new World(window,gSettings);

			// Add initial entities to the world

			initWorld(*world);

      // Event handler
      SDL_Event e;

      bool quit = false;
      while(quit == false)
        {
          world->update();
          world->draw();
          while(SDL_PollEvent(&e) != 0)
            {
              if(e.type == SDL_QUIT)
                {
                  quit = true;
                }
              else if(e.type == SDL_KEYDOWN)
                {
                  switch(e.key.keysym.sym)
                    {
                    case SDLK_q:
                      quit = true;
                      break;
                    default:
						quit = false;
                      //world->inputHandler.handleKeyEvent(e.key);
                    }
                }
            }
        }

			// Free everything
			delete world;
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}