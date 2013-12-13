#include "CSurface.h"
#include <SDL_image.h>

bool CSurface::onDraw( SDL_Surface* dest,SDL_Surface* src,int x,int y )
{
	SDL_Rect rect;
	rect.x=x;
	rect.y=y;
	return CSurface::onDraw(dest,src,&rect);
}

bool CSurface::onDraw( SDL_Surface* dest,SDL_Surface* src,SDL_Rect* rect )
{
	if(dest==nullptr || src==nullptr)
	{
		return false;
	}
	SDL_BlitSurface(src,NULL,dest,rect);
	return true;
}

SDL_Surface* CSurface::onLoad( std::string file )
{
	return IMG_Load(file.c_str());
}