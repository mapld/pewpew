#include "../header/ShapeSystem.h"

void ShapeSystem::addComponent(Entity e, SDL_Rect r, SDL_Color c)
{
	_data.rects.push_back(r);
	_data.colors.push_back(c);
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

ShapeSystem::Data* ShapeSystem::getData()
{
	return &_data;
}