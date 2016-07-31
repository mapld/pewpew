#pragma once
#include "Entity.h"
#include <vector>
#include <unordered_map>
#include <SDL.h>
#include "GraphicsSettings.h"
#include "EntityManager.h"	

// System for primitive shape components. Rendered using the basic SDL rendering
class ShapeSystem
{
public:
	struct Shape 
	{
		SDL_Rect rect;
		SDL_Color color;
	};

	struct Data
	{
		std::vector<SDL_Rect> rects;
		std::vector<SDL_Color> colors;
		std::vector<Entity> entities;
		unsigned n = 0;
	};

	ShapeSystem() {}
	ShapeSystem(SDL_Renderer* renderer) { _renderer = renderer; }

	void draw();
	Data* getData();
	void addComponent(Entity, SDL_Rect = { 0,0,0,0 }, SDL_Color = { 0, 0 , 0, 0 });
	void destroyComponent(Entity);
	Shape getComponent(Entity);

	void cleanUp(const EntityManager&);

private:
	Data _data;
	std::unordered_map<Entity, unsigned> _map;
	SDL_Renderer* _renderer;
};