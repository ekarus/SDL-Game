#pragma once

#include <SDL.h>
#include <string>
#include "Singleton.h"

class Window : public Singleton<Window>
{
public:
	Window();

	Window(const std::string& title, int width, int height);

	~Window();

	SDL_Window* Get()
	{
		return window_;
	}

private:
	SDL_Window* window_;
};

