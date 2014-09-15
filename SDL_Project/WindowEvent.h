#pragma once

#include "Singleton.h"
#include <boost/signals2.hpp>
#include <SDL2/SDL.h>
#include "EventManager.h"

namespace Events
{
	namespace Detail
	{
		class WindowEvent
		{
		public:
			typedef boost::signals2::signal<void(int,int)> WindowResizeSignal;

			WindowEvent()
			{
				AttachEvents();
			}

			boost::signals2::connection AttachOnWindowResize(const WindowResizeSignal::slot_type& slot)
			{
				return window_resize_signal_.connect(slot);
			}

		private:
			void AttachEvents()
			{
				EventManager::Instance()->AttachOnEvent([=](const Event& event)
				{
					OnEvent(event);
				});
			}

			void OnEvent(const Event& event)
			{
				if(event.type == SDL_WINDOWEVENT)
				{
					if(event.window.event == SDL_WINDOWEVENT_RESIZED)
					{
						window_resize_signal_(event.window.data1,event.window.data2);
					}
				}
			}

			WindowResizeSignal window_resize_signal_;
		};
	}

	typedef Singleton<Detail::WindowEvent> Window;
}