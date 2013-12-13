#pragma once

#include "CacheManager.h"
#include "AnimatedTextureAllocator.h"
#include "Singleton.h"

namespace Detail
{
	class AnimatedTextureManager : public CacheManager<AnimatedTexture, AnimatedTextureCreator, AnimatedTextureDeleter>
	{
	};
}

typedef Singleton<Detail::AnimatedTextureManager> AnimatedTextureManagerSingleton;