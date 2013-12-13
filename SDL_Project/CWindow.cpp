#include "CWindow.h"
#include "CSurface.h"
#include "WindowEvent.h"
#include "CLogger.h"

Detail::Window::Window()
{
	window_ = SDL_CreateWindow("SDL_Window", 100, 100, 200, 200,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	AttachEvents();
}

Detail::Window::Window( const std::string& title, int width, int height )
{
	window_ = SDL_CreateWindow(title.c_str(), 100, 100, width, height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	AttachEvents();
}

Detail::Window::~Window()
{
	if(window_)
	{
		SDL_DestroyWindow(window_);
		window_ = nullptr;
	}
}

SDL_Window* Detail::Window::Get()
{
	return window_;
}

bool Detail::Window::SetIcon( const std::string& icon_path )
{
	SDL_Surface* surf = CSurface::onLoad(icon_path);

	if (surf)
	{
		SDL_SetWindowIcon(window_, surf);
		return true;
	}

	return false;
}

void Detail::Window::SetTitle( const std::string& title )
{
	SDL_SetWindowTitle(window_, title.c_str());
}

void Detail::Window::AttachEvents()
{
	Events::Window::Instance()->AttachOnWindowResize([](int w,int h)
	{
		LOG_INFO("Window w=" << w << " h=" << h);
	});
}

int Detail::Window::GetWidth()
{
	int width;
	SDL_GetWindowSize(window_, &width, NULL);

	return width;
}

int Detail::Window::GetHeight()
{
	int height;
	SDL_GetWindowSize(window_, NULL, &height);

	return height;
}
