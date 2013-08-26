#include <SDL.h>
#include <SDL_image.h>
#include <string>

class CTexture
{
public:
	static SDL_Texture* onLoad(SDL_Renderer* render, std::string file);
	static void onDraw(SDL_Texture* tex,SDL_Renderer* render,SDL_Rect* rect);
	static void onDraw(SDL_Texture* tex,SDL_Renderer* render,int x,int y);
};