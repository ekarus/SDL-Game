#include "Texture.h"
#include "CRender.h"

void Detail::Texture::Draw( int x,int y,int w,int h, int angle /*= 0 */ )
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_RenderCopy(RendererSingleton::Instance()->Get(), tex_, NULL, &rect);
}

void Detail::Texture::Draw( Rect dst_rect )
{
	SDL_RenderCopy(RendererSingleton::Instance()->Get(), tex_, NULL, &dst_rect);
}

void Detail::Texture::Draw( int x,int y,int w,int h, int x2,int y2, int w2,int h2 ,int angle/*=0*/ )
{
	SDL_Rect src_rect;
	src_rect.x = x;
	src_rect.y = y;
	src_rect.w = w;
	src_rect.h = h;
	SDL_Rect dest_rect;
	dest_rect.x = x2;
	dest_rect.y = y2;
	dest_rect.w = w2;
	dest_rect.h = h2;
	SDL_RenderCopy(RendererSingleton::Instance()->Get(), tex_, &src_rect, &dest_rect);
}

void Detail::Texture::Draw( const Rect* src_rect,const Rect* dst_rect )
{
	SDL_RenderCopy(RendererSingleton::Instance()->Get(),tex_,src_rect,dst_rect);
}

void Detail::Texture::setColor( Color::Enum color )
{
	color_ = color;

	switch(color)
	{
	case Color::red : SDL_SetTextureColorMod(tex_,255,0,0);break;
	case Color::black : SDL_SetTextureColorMod(tex_,0,0,0);break;
	case Color::green : SDL_SetTextureColorMod(tex_,0,255,0);break;
	case Color::blue : SDL_SetTextureColorMod(tex_,0,0,255);break;
	case Color::white : SDL_SetTextureColorMod(tex_,255,255,255);break;
	case Color::gray : SDL_SetTextureColorMod(tex_,100,100,100);break;
	case Color::orange : SDL_SetTextureColorMod(tex_,100,100,0);break;
	default : SDL_SetTextureColorMod(tex_,255,255,255);;
	}
}