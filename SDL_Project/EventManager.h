#pragma once

#include "Singleton.h"
#include <boost/signals2.hpp>
#include <SDL2/SDL.h>

namespace Events
{
	typedef SDL_Event Event;
	typedef Event* EventPtr;

	namespace Detail
	{
		class EventManagerImpl
		{
		public:
			typedef boost::signals2::signal<void(const Event& event)> EventSignal;

			boost::signals2::connection AttachOnEvent(const EventSignal::slot_type& slot);

			void Update();

		private:
			EventSignal event_signal_;
		};
	}

	typedef Singleton<Detail::EventManagerImpl> EventManager;
}