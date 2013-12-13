#pragma once
#include "IGameState.h"
#include "CApp.h"
#include "Singleton.h"
#include "TextureManager.h"
#include <boost/signals2.hpp>

namespace Detail
{
	class IntroScreenImpl: public IGameState
	{
	public:
		IntroScreenImpl();

		virtual ~IntroScreenImpl();

		virtual bool OnInit();

		virtual void OnUpdate( float time );

		virtual void OnRender();

		virtual void OnCleanUp();

		virtual void OnPause();

		virtual void OnResume();

	private:

		virtual void AttachOnEvents();

		CApp* app;
		TextureSharedPtr back_ground_;
	};
}

typedef Singleton<Detail::IntroScreenImpl> IntroScreen;