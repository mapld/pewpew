#pragma once
#include <SDL.h>
#include "GraphicsSettings.h"
#include "EntityManager.h"
#include "ShapeSystem.h"

// Contains all of the systems for a game's world. This is game specific but could be reused for multiple levels of a game
class World
{
public:
	World(SDL_Window* w, GraphicsSettings gs)
	{
		window = w;
		graphicsSettings = gs;
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		shapeSystem = ShapeSystem(renderer);
	}

	void draw();

	void update();

	SDL_Window* window;
	GraphicsSettings graphicsSettings;
	SDL_Renderer* renderer;

	EntityManager entityManager;

	ShapeSystem shapeSystem;
};