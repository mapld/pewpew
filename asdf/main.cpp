#include <SDL.h>
#include <assert.h>

#include "GraphicsSettings.h"
#include "World.h"

// Sets up initial world entities
void initWorld(World* world)
{
	Entity e = world->entityManager.createEntity();
	assert(world->entityManager.alive(e));
	world->shapeSystem.addComponent(e, { 100,50,50,50 }, world->graphicsSettings.defaultSquareColor);
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
		window = SDL_CreateWindow("ASDF", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gSettings.screenWidth, gSettings.screenHeight, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Failed to create window. SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			// Create the world and all its systems. 
			World* world = new World(window,gSettings);

			// Add initial entities to the world
			initWorld(world);

			// Put loop here
			world->Draw();

			SDL_Delay(4000);

			// Free everything 
			delete world;
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}