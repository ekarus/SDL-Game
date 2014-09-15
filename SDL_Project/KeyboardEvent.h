#pragma once

#include "Singleton.h"
#include <boost/signals2.hpp>
#include <SDL2/SDL.h>
#include "EventManager.h"

namespace Events
{
	typedef SDL_Keysym Key;

	namespace Detail
	{
		class KeyboardEvent
		{
		public:
			typedef boost::signals2::signal<void(const Key& key)> KeyDownSignal;
			typedef boost::signals2::signal<void(const Key& key)> KeyUpSignal;

			KeyboardEvent()
			{
				AttachEvents();
			}

			boost::signals2::connection AttachOnKeyDown(const KeyDownSignal::slot_type& slot)
			{
				return key_down_signal_.connect(slot);
			}

			boost::signals2::connection AttachOnKeyUp(const KeyUpSignal::slot_type& slot)
			{
				return key_up_signal_.connect(slot);
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
				switch(event.type)
				{
				case SDL_KEYDOWN:
					{
						key_down_signal_(event.key.keysym);
						break;
					}

				case SDL_KEYUP:
					{
						key_up_signal_(event.key.keysym);
						break;
					}
				}
			}

			KeyDownSignal key_down_signal_;
			KeyUpSignal key_up_signal_;
		};
	}

	typedef Singleton<Detail::KeyboardEvent> Keyboard;
}