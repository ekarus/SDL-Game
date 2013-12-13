#pragma once

#include "Allocator.h"
#include "CRender.h"
#include <SDL_image.h>
#include <assert.h>

template<typename Texture>
class TextureCreator
{
public:
	static Texture* Create(const std::string& file_path)
	{
		if(Texture::RawTexturePtr raw_texture = IMG_LoadTexture(RendererSingleton::Instance()->Get(),file_path.c_str()))
		{
			int w,h;
			SDL_QueryTexture(raw_texture, NULL, NULL, &w, &h);

			return new Texture(file_path, raw_texture, w, h);
		}
		else
			return nullptr;
	}
};

template<typename Texture>
class TextureDeleter
{
public:
	static void Delete(Texture* texture)
	{
		assert(texture->GetRaw() != nullptr);

		SDL_DestroyTexture(texture->GetRaw());

		if(texture)
		{
			delete texture;
			texture = nullptr;
		}
	}
};