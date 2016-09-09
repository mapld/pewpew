#pragma once
#include <SDL.h>
#include "GraphicsSettings.h"
#include "EntityManager.h"
#include "ShapeSystem.h"
#include "Transform.h"
#include "InputHandler.h"

// Contains all of the systems for a game's world. This is game specific but could be reused for multiple levels of a game
class World
{
public:
	World(SDL_Window* w, GraphicsSettings gs)
	{
		window = w;
		graphicsSettings = gs;

    inputHandler = InputHandler();
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    transformSystem = Transform();
		shapeSystem = ShapeSystem(renderer);
	}

	void draw();

	void update();

  InputHandler inputHandler;
  Transform transformSystem;
	GraphicsSettings graphicsSettings;
	SDL_Window* window;
	SDL_Renderer* renderer;

	EntityManager entityManager;
	ShapeSystem shapeSystem;
};
