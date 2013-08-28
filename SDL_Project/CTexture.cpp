#include "CTexture.h"

SDL_Texture* CTexture::onLoad(SDL_Renderer* render, std::string file )
{
	return IMG_LoadTexture(render,file.c_str());
}

void CTexture::onDraw(SDL_Texture* tex,SDL_Renderer* render,SDL_Rect* rect)
{
	SDL_RenderCopy(render,tex,NULL,rect);
}
void CTexture::onDraw(SDL_Texture* tex,SDL_Renderer* render,SDL_Rect* src_rect,SDL_Rect* dst_rect)
{
	SDL_RenderCopy(render,tex,src_rect,dst_rect);
}
void CTexture::onDraw(SDL_Texture* tex,SDL_Renderer* render,int x,int y)
{
	SDL_Rect rect;
	rect.x=x;
	rect.y=y;
	SDL_QueryTexture(tex,NULL,NULL,&rect.w,&rect.h);
	onDraw(tex,render,&rect);
}