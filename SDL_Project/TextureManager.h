#pragma once

#include "CacheManager.h"
#include "TextureAllocator.h"
#include "Singleton.h"

namespace Detail
{
	class TextureManager : public CacheManager<Texture, TextureCreator, TextureDeleter>
	{
	};
}

typedef Singleton<Detail::TextureManager> TextureManagerSingleton;