#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

enum Colors{ green, blue,gray,orange,red,dark_gray,white,black};

class CTexture
{
public:
	
	static SDL_Texture* onLoad(SDL_Renderer* render, std::string file);
	static void onDraw(SDL_Texture* tex,SDL_Renderer* render,SDL_Rect* rect);
	static void onDraw(SDL_Texture* tex,SDL_Renderer* render,int x,int y);
	static void onDraw(SDL_Texture* tex,SDL_Renderer* render,int x,int y,int w,int h);
	static void onDraw(SDL_Texture* tex,SDL_Renderer* render,SDL_Rect* src_rect,SDL_Rect* dst_rect);
	static void onDraw(SDL_Texture* tex,SDL_Renderer* render,int part,int all,SDL_Rect* dst_rect);
	static int getFrameCount(SDL_Texture* tex);
	static void setColor(SDL_Texture* tex,Colors color);
};