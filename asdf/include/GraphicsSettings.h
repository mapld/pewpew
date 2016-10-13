#ifndef SETTINGS_H
#define SETTINGS_H

#include <SDL.h> 

struct GraphicsSettings
{
	int screenWidth;
	int screenHeight;
	SDL_Color backgroundColor;
	SDL_Color defaultSquareColor;
  float scale;

	GraphicsSettings()
	{
		// defaults
		screenWidth = 1280;
		screenHeight = 720;
		backgroundColor = { 255,0,255,255 };
		defaultSquareColor = { 255,255,0,255 };
    scale = 10.0f;
	}
};
#endif
