#pragma once
#include <SDL.h>
#include <string>

class CSurface
{
public:
	static SDL_Surface* onLoad(std::string file);
	static bool onDraw(SDL_Surface* dest,SDL_Surface* src,int x,int y);
	static bool onDraw(SDL_Surface* dest,SDL_Surface* src,SDL_Rect* rect);
};
