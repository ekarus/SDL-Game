#pragma once

#include <SDL2/SDL.h>
#include "Singleton.h"
#include "CWindow.h"

namespace Detail
{
	class Renderer
	{
	public:
		Renderer();

		~Renderer();

		SDL_Renderer* Get();

	private:
		SDL_Renderer* renderer_;
	};
}

typedef Singleton<Detail::Renderer> RendererSingleton;
