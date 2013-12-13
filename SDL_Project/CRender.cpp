#include "CRender.h"

Detail::Renderer::Renderer()
{
	renderer_ = SDL_CreateRenderer(WindowSingleton::Instance()->Get(),
		-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Detail::Renderer::~Renderer()
{
	if (renderer_)
	{
		SDL_DestroyRenderer(renderer_);
		renderer_ = nullptr;
	}
}

SDL_Renderer* Detail::Renderer::Get()
{
	return renderer_;
}
