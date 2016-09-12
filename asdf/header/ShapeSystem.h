#pragma once
#include "Entity.h"
#include <vector>
#include <unordered_map>
#include <SDL.h>
#include "GraphicsSettings.h"
#include "EntityManager.h"
#include "Transform.h"

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
    std::vector<SDL_Rect> tRects;
		std::vector<SDL_Color> colors;
		std::vector<Entity> entities;
		unsigned n = 0;
	};

	ShapeSystem() {}
	ShapeSystem(SDL_Renderer* renderer, GraphicsSettings* graphicsSettings) { _renderer = renderer; _graphicsSettings = graphicsSettings;}

  void updatePositions(Transform&);
  void draw();
  void add(Entity, SDL_Rect = { 0,0,0,0 }, SDL_Color = { 0, 0 , 0, 0 });
	void destroy(Entity);
	Shape getComponent(Entity);

	void cleanUp(const EntityManager&);

private:
	Data _data;
	std::unordered_map<Entity, unsigned> _map;
	SDL_Renderer* _renderer;
  GraphicsSettings* _graphicsSettings;
};
