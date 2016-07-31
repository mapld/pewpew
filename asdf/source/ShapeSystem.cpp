#include "../header/ShapeSystem.h"
#include <algorithm>

void ShapeSystem::addComponent(Entity e, SDL_Rect r, SDL_Color c)
{
	_data.n++;
	_data.rects.push_back(r);
	_data.colors.push_back(c);
	_data.entities.push_back(e);
	_map[e] = _data.colors.size() - 1;
}

void ShapeSystem::draw()
{
	std::vector<SDL_Rect>::const_iterator rit = _data.rects.begin();
	std::vector<SDL_Rect>::const_iterator rend = _data.rects.end();
	std::vector<SDL_Color>::const_iterator cit = _data.colors.begin();
	for (;rit != rend; rit++,cit++)
	{
		SDL_Color color = *cit;
		SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
		SDL_Rect rect = *rit;
		SDL_RenderFillRect(_renderer, &rect);
	}
}

ShapeSystem::Shape ShapeSystem::getComponent(Entity e)
{
	Shape shape;
	shape.rect = _data.rects[_map[e]];
	shape.color = _data.colors[_map[e]];
	return shape;
}


void ShapeSystem::destroyComponent(Entity e)
{
	unsigned i = _map[e];
	unsigned end = _data.n - 1;

	_data.rects[i] = _data.rects[end];
	_data.rects.pop_back();

	_data.colors[i] = _data.colors[end];
	_data.colors.pop_back();

	_data.entities[i] = _data.entities[end];
	_data.entities.pop_back();

	_data.n--;
}

ShapeSystem::Data* ShapeSystem::getData()
{
	return &_data;
}

void ShapeSystem::cleanUp(const EntityManager& em)
{
	// deletes the components based on whether they are alive. inneficient way to do things, should probably make entity manager supply a list of deleted entities for each frame
	// there's also the random garbage collection approach but that doesn't work for renderables like this because they need immediate deletion
	for (std::size_t i = 0; i < _data.n; i++)
	{
		Entity e = _data.entities[i];
		if (!em.alive(e))
		{
			destroyComponent(e);
		}
	}
}