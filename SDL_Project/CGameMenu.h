#pragma once
#include "IGameState.h"
#include "CApp.h"
#include "Singleton.h"
#include "TextureManager.h"

namespace Detail
{
	class CGameMenu: public IGameState
	{
	public:
		CGameMenu();

		virtual ~CGameMenu();

		virtual bool OnInit();

		virtual void OnUpdate( float time );

		virtual void OnRender();

		virtual void OnCleanUp();

		virtual void OnPause();

		virtual void OnResume();

	private:
		virtual void AttachOnEvents();

		CApp* app;
		TextureSharedPtr bg;
	};
}

typedef Singleton<Detail::CGameMenu> GameMenuSingleton;