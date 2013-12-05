#include "CRender.h"
#include "CWindow.h"


Renderer::Renderer()
{
	SDL_Renderer* renderer_ = SDL_CreateRenderer(Window::Instance()->Get(), -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

	if(renderer_ == nullptr)
	{
		throw std::exception("SDL_CreateRenderer Fails");
	}
}

Renderer::~Renderer()
{
	if(renderer_)
	{
		SDL_DestroyRenderer(renderer_);
		renderer_ = nullptr;
	}
}
