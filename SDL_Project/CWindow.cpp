#include "CWindow.h"

Window::Window(const std::string& title, int width, int height)
{
	SDL_Window* window_ = SDL_CreateWindow(title.c_str(), 100, 100, width, height, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

	if (window_ == nullptr)
	{
		throw std::exception("SDL_CreateWindow Fails");
	}
}

Window::Window()
{
	SDL_Window* window_ = SDL_CreateWindow("SDL_Window", 100, 100, 400, 400, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

	if (window_ == nullptr)
	{
		throw std::exception("SDL_CreateWindow Fails");
	}
}

Window::~Window()
{
	if(window_)
	{
		SDL_DestroyWindow(window_);
		window_ = nullptr;
	}
}
