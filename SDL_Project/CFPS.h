#pragma once
#include "Singleton.h"

namespace Detail
{
	class CFPS
	{
	public:
		CFPS();
		virtual ~CFPS();

		void onUpdate();
		int getFPS(){return frameRate;};
		float getSpeedFactor(){return speedFactor;};

	private:

		int frameCount;
		int frameRate;
		float speedFactor;
		int oldTime;
		int lastTime;

	};
}

typedef Singleton<Detail::CFPS> FPS;