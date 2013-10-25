#include "CTextureManager.h"
#include "CRender.h"
#include <SDL_image.h>
#include "SDL.h"
#include "CTexture.h"
#include <algorithm>
#include <iostream>
#include "CLogger.h"
#include <fstream>

void CTextureManager::DeleteAllTexture()
{
	std::for_each(textures_by_id_.begin(),textures_by_id_.end(),[=](TexturesContainerByID::value_type pair)
	{
		DeleteTexture(pair.first);
	});
}

void CTextureManager::DeleteTexture( TextureId id )
{
	LOG_INFO("Delete texture "<<id);
	auto texture_iteretor= textures_by_id_.find(id);
	if(texture_iteretor != textures_by_id_.end())
	{
		SDL_DestroyTexture(texture_iteretor->second);
		texture_iteretor->second=nullptr;
		textures_by_id_.erase(texture_iteretor);
		LOG_INFO("TextureCache size "<<textures_by_id_.size());
	}
}

CTextureManager::CTextureManager():last_id(0)
{
}

CTextureManager::~CTextureManager()
{
	DeleteAllTexture();
}

TextureSharedPtr CTextureManager::LoadTexturePtr( const std::string& file )
{
	auto texture_iterator = textures_.find(file);
	if(texture_iterator != textures_.end())
	{
		if(TextureSharedPtr texture_ptr = texture_iterator->second.lock())
		{
			LOG_INFO("Texture has already loaded. Filename = "<<file);
			return texture_ptr;
		}
		else
			LOG_INFO("Texture has been deleted, loading it again. Filename = "<<file);
	}

	SDL_Texture* tex = IMG_LoadTexture(Renderer::Instance(),file.c_str());

	int w,h;
	SDL_QueryTexture(tex,NULL,NULL,&w,&h);

	TextureSharedPtr texture_ptr = std::make_shared<Detail::Texture>(file, tex, ++last_id , w, h);

	if(texture_ptr->isValid())
	{
		textures_by_id_[last_id] = tex;
		textures_[file] = texture_ptr;
	}
	else
		LOG_ERROR("Cannot load texture. Filename = "<<file);

	return texture_ptr;
}

TextureSharedPtr CTextureManager::LoadAnimTexturePtr( const std::string& file )
{
	auto texture_iterator = textures_.find(file);
	if(texture_iterator != textures_.end())
	{
		if(TextureSharedPtr texture_ptr = texture_iterator->second.lock())
		{
			LOG_INFO("Texture has already loaded. Filename = "<<file);
			return texture_ptr;
		}
		else
			LOG_INFO("Texture has been deleted, loading it again. Filename = "<<file);
	}

	SDL_Texture* tex = IMG_LoadTexture(Renderer::Instance(),file.c_str());

	int w,h;
	SDL_QueryTexture(tex,NULL,NULL,&w,&h);

	TextureSharedPtr texture_ptr = std::make_shared<Detail::AnimatedTexture>(file, tex, ++last_id, w, h, 4,0);

	if(texture_ptr->isValid())
	{
		textures_by_id_[last_id] = tex;
		textures_[file] = texture_ptr;
	}
	else
		LOG_ERROR("Cannot load texture. Filename = "<<file);

	return texture_ptr;
}

bool CTextureManager::isAlreadyLoaded( const std::string& file )
{
	auto texture_iterator = textures_.find(file);
	if(texture_iterator != textures_.end())
	{
		if(TextureSharedPtr texture_ptr = texture_iterator->second.lock())
		{
			return true;
		}
	}
	return false;
}

void Detail::AnimatedTexture::Draw( int x,int y,int w,int h, int angle )
{
	animator.OnAnimate();
	Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	Draw(animator.getCurrFrame(),animator.getFrameCount(),&rect);
}

void Detail::AnimatedTexture::Draw( Rect dst_rect )
{
	Draw(animator.getCurrFrame(),animator.getFrameCount(),&dst_rect);
}

void Detail::AnimatedTexture::Draw( size_t currFrame, size_t frameCount,const Rect* dst_rect )
{
	Rect rect;
	rect.w = width_;
	rect.h = height_;
	if (frameCount == 0) frameCount=1;
	int slide_width=rect.w / frameCount;
	rect.x = slide_width * currFrame;
	rect.y = 0;
	rect.w = slide_width;
	Texture::Draw(&rect,dst_rect);
}

void Detail::Texture::Draw( int x,int y,int w,int h, int angle /*= 0 */ )
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_RenderCopy(Renderer::Instance(), tex_, NULL, &rect);
}

void Detail::Texture::Draw( Rect dst_rect )
{
	SDL_RenderCopy(Renderer::Instance(), tex_, NULL, &dst_rect);
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
	SDL_RenderCopy(Renderer::Instance(), tex_, &src_rect, &dest_rect);
}

void Detail::Texture::Draw( const Rect* src_rect,const Rect* dst_rect )
{
	SDL_RenderCopy(Renderer::Instance(),tex_,src_rect,dst_rect);
}

void Detail::Texture::setColor( Color::Enum color )
{
	color_ = color;

	switch(color)
	{
	case Color::red:SDL_SetTextureColorMod(tex_,255,0,0);break;
	case Color::black:SDL_SetTextureColorMod(tex_,0,0,0);break;
	case Color::green:SDL_SetTextureColorMod(tex_,0,255,0);break;
	case Color::blue:SDL_SetTextureColorMod(tex_,0,0,255);break;
	case Color::white:SDL_SetTextureColorMod(tex_,255,255,255);break;
	case Color::gray:SDL_SetTextureColorMod(tex_,100,100,100);break;
	case Color::orange:SDL_SetTextureColorMod(tex_,100,100,0);break;
	default:SDL_SetTextureColorMod(tex_,255,255,255);;
	}
}