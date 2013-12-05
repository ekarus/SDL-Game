#pragma once

#include <SDL.h>
#include "Singleton.h"

class Renderer : public Singleton<Renderer>
{
public:
	Renderer();

	~Renderer();

	SDL_Renderer* Get()
	{
		return renderer_;
	}

private:
	SDL_Renderer* renderer_;
};

