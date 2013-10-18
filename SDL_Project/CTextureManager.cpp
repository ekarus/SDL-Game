#include "CTextureManager.h"
#include "CRender.h"
#include <SDL_image.h>
#include "SDL.h"
#include "CTexture.h"
#include <algorithm>

TextureId CTextureManager::LoadTexture( const std::string& file )
{
	Texture texture;
	auto texture_iterator=textures_by_path_.find(file);
	if(texture_iterator==textures_by_path_.end())
	{
		texture.tex=IMG_LoadTexture(Renderer::Instance(),file.c_str());
		if(texture.tex == nullptr)
		{
			return 0;
		}
		texture.file=file;
		texture.id=++last_id;

		SDL_QueryTexture(texture.tex,NULL,NULL,&texture.w,&texture.h);

		InsertTexture(texture);

		return last_id;
	}
	else
	{
		return texture_iterator->second.id;
	}
}

void CTextureManager::DeleteTexture( TextureId id )
{
	auto texture_iteretor= textures_by_id_.find(id);
	if(texture_iteretor != textures_by_id_.end())
	{
		SDL_DestroyTexture(texture_iteretor->second.tex);
		textures_by_path_.erase(textures_by_path_.find(texture_iteretor->second.file));
		textures_by_id_.erase(texture_iteretor);
	}
}

void CTextureManager::DrawTexture( TextureId id,int x,int y,int w,int h, int angle/*=0*/ )
{
	SDL_Rect rect;
	rect.x=x;
	rect.y=y;
	rect.w=w;
	rect.h=h;
	SDL_RenderCopy(Renderer::Instance(),textures_by_id_[id].tex,NULL,&rect);
}

void CTextureManager::DrawTexture( TextureId id,int x,int y,int w,int h, int x2,int y2, int w2,int h2 ,int angle/*=0*/ )
{
	SDL_Rect src_rect;
	src_rect.x=x;
	src_rect.y=y;
	src_rect.w=w;
	src_rect.h=h;
	SDL_Rect dest_rect;
	dest_rect.x=x2;
	dest_rect.y=y2;
	dest_rect.w=w2;
	dest_rect.h=h2;
	SDL_RenderCopy(Renderer::Instance(),textures_by_id_[id].tex,&src_rect,&dest_rect);
}

void CTextureManager::SetTextureColor(TextureId id, Uint8 r,Uint8 g, Uint8 b, Uint8 a )
{
	SDL_SetTextureColorMod(textures_by_id_[id].tex,r,g,b);
	SDL_SetTextureAlphaMod(textures_by_id_[id].tex,a);
}

void CTextureManager::SetTextureColor(TextureId id, Color::Enum color)
{
	auto texture_iteretor= textures_by_id_.find(id);
	if(texture_iteretor != textures_by_id_.end())
	{
		switch(color)
		{
		case red:SDL_SetTextureColorMod(texture_iteretor->second.tex,255,0,0);break;
		case black:SDL_SetTextureColorMod(texture_iteretor->second.tex,0,0,0);break;
		case green:SDL_SetTextureColorMod(texture_iteretor->second.tex,0,255,0);break;
		case blue:SDL_SetTextureColorMod(texture_iteretor->second.tex,0,0,255);break;
		case white:SDL_SetTextureColorMod(texture_iteretor->second.tex,255,255,255);break;
		case gray:SDL_SetTextureColorMod(texture_iteretor->second.tex,100,100,100);break;
		case orange:SDL_SetTextureColorMod(texture_iteretor->second.tex,100,100,0);break;
		default:SDL_SetTextureColorMod(texture_iteretor->second.tex,255,255,255);;
		}
		//SDL_SetTextureAlphaMod(textures_by_id_[id].tex,0);
	}
}

int CTextureManager::getTextureWidth( TextureId id )
{
	return textures_by_id_[id].w;
}

int CTextureManager::getTextureHeight( TextureId id )
{
	return textures_by_id_[id].h;
}

void CTextureManager::DeleteAllTexture()
{
	std::for_each(textures_by_id_.begin(),textures_by_id_.end(),[=](TexturesContainerByID::value_type pair)
	{
		DeleteTexture(pair.first);
	});
}

CTextureManager::CTextureManager():last_id(0)
{
}

CTextureManager::~CTextureManager()
{
	DeleteAllTexture();
}

void CTextureManager::InsertTexture( Texture& texture )
{
	textures_by_path_[texture.file]=texture;
	textures_by_id_[texture.id]=texture;
}