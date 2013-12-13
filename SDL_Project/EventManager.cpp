#include "EventManager.h"
#include <SDL.h>

namespace Events
{

	void Detail::EventManagerImpl::Update()
	{
		Event event;

		while(SDL_PollEvent(&event))
		{
			event_signal_(event);
		}
	}

	boost::signals2::connection Detail::EventManagerImpl::AttachOnEvent( const EventSignal::slot_type& slot )
	{
		return event_signal_.connect(slot);
	}

}