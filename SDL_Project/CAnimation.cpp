#include "CAnimation.h"
#include <SDL.h>
void CAnimation::OnAnimate()
{
	if((old_time+frame_rate)<SDL_GetTicks())
	{
		old_time=SDL_GetTicks();
		curr_frame+=step;
		if(curr_frame>=frame_count)
		{
			curr_frame=0;
		}
	}
}

CAnimation::CAnimation()
{
	step=1;
	old_time=0;
	curr_frame=0;
	frame_count=0;
	frame_rate=100;
}

CAnimation::~CAnimation()
{

}
