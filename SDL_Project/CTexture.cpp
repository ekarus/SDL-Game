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

void CTexture::onDraw( SDL_Texture* tex,SDL_Renderer* render,int x,int y,int w,int h )
{
	SDL_Rect rect;
	rect.x=x;
	rect.y=y;
	rect.w=w;
	rect.h=h;
	onDraw(tex,render,&rect);
}

void CTexture::onDraw( SDL_Texture* tex,SDL_Renderer* render,int currFrame,int frameCount,SDL_Rect* dst_rect )
{
	SDL_Rect rect;
	SDL_QueryTexture(tex,NULL,NULL,&rect.w,&rect.h);
	if(frameCount==0)frameCount=1;
	int slide_width=rect.w/frameCount;
	rect.x=slide_width*currFrame;
	rect.y=0;
	rect.w=slide_width;
	onDraw(tex,render,&rect,dst_rect);
}

void CTexture::setColor( SDL_Texture* tex,Colors color )
{
	switch(color)
	{
	case red:SDL_SetTextureColorMod(tex,255,0,0);break;
	case black:SDL_SetTextureColorMod(tex,0,0,0);break;
	case green:SDL_SetTextureColorMod(tex,0,255,0);break;
	case blue:SDL_SetTextureColorMod(tex,0,0,255);break;
	case white:SDL_SetTextureColorMod(tex,255,255,255);break;
	case gray:SDL_SetTextureColorMod(tex,100,100,100);break;
	case orange:SDL_SetTextureColorMod(tex,100,100,0);break;
	default:SDL_SetTextureColorMod(tex,255,255,255);;
	}
}

int CTexture::getFrameCount( SDL_Texture* tex )
{
	int w,h;
	SDL_QueryTexture(tex,NULL,NULL,&w,&h);
	return w/h;
}