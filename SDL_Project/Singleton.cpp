#include "Singleton.h"

SDL_Window* Singleton<SDL_Window>::Instance()
{
	if(window_)
	{
		return window_;
	}
	else
	{
		return window_ = Create("SDL GAME",400,400);
	}
}

SDL_Window* Singleton<SDL_Window>::Instance( const std::string& title, size_t width, size_t height )
{
	if(window_)
	{
		return window_;
	}
	else
	{
		return window_ = Create(title,width,height);
	}
}

SDL_Window* Singleton<SDL_Window>::Create( const std::string& title, size_t width, size_t height )
{
	SDL_Window* window = SDL_CreateWindow(title.c_str(), 100, 100, width, height, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
	if (window == nullptr)
	{
		throw std::exception("SDL_CreateWindow Fails");
	}
	return window;
}

void Singleton<SDL_Window>::Delete()
{
	if(window_)
	{
		SDL_DestroyWindow(window_);
		window_ = nullptr;
	}
}

SDL_Renderer* Singleton<SDL_Renderer>::Instance()
{
	if(renderer_)
	{
		return renderer_;
	}
	else
	{
		return renderer_ = Create();
	}
}

void Singleton<SDL_Renderer>::Delete()
{
	if(renderer_)
	{
		SDL_DestroyRenderer(renderer_);
		renderer_ = nullptr;
	}
}

SDL_Renderer* Singleton<SDL_Renderer>::Create()
{
	SDL_Renderer* render=SDL_CreateRenderer(Singleton<SDL_Window>::Instance(), -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if(render==nullptr)
	{
		throw std::exception("SDL_CreateRenderer Fails");
	}
	return render;
}

SDL_Window* Singleton<SDL_Window>::window_ = nullptr;

SDL_Renderer* Singleton<SDL_Renderer>::renderer_ = nullptr;