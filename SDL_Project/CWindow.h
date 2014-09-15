#pragma once

#include <SDL2/SDL.h>
#include "Singleton.h"
#include <string>

namespace Detail
{
	class Window
	{
	public:

		Window();

		Window(const std::string& title, int width, int height);

		~Window();

		SDL_Window* Get();

		bool SetIcon(const std::string& icon_path);

		void SetTitle(const std::string& title);

		int GetWidth();

		int GetHeight();

	private:
		void AttachEvents();

		SDL_Window* window_;
	};
}

typedef Singleton<Detail::Window> WindowSingleton;
