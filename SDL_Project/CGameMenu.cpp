#include "CGameMenu.h"
#include "CGame.h"
#include <iostream>
#include "KeyboardEvent.h"

namespace Detail
{
	bool CGameMenu::OnInit()
	{
		AttachOnEvents();

		app = AppSingleton::Instance();
		bg = TextureManagerSingleton::Instance()->Load("../Res/menu.png");

		if(bg == nullptr)
		{
			LOG_ERROR("Could't load game menu texture");
			return false;
		}
		return true;
	}

	void CGameMenu::OnUpdate( float time )
	{
	}

	void CGameMenu::OnRender()
	{
		GameSingleton::Instance()->OnRender();
		bg->Draw(50,50,app->getScrWidth()-100,app->getScrHeight()-100);
	}

	void CGameMenu::OnCleanUp()
	{
		LOG_INFO("CleanUp");
		
		IGameState::OnCleanUp();
	}

	void CGameMenu::OnPause()
	{
		LOG_INFO("Pause");
		
		IGameState::OnPause();
	}

	void CGameMenu::OnResume()
	{
		LOG_INFO("Resume");
		
		IGameState::OnResume();
	}

	CGameMenu::CGameMenu()
	{
	}

	CGameMenu::~CGameMenu()
	{
	}

	void CGameMenu::AttachOnEvents()
	{
		/*boost::signals2::connection keyboard = Events::Keyboard::Instance()->AttachOnKeyDown([=](const Events::Key& key)
		{
			if(key.scancode == SDL_SCANCODE_ESCAPE)
			{
				app->PopState();
			}
		});
*/

		AddConnection(Events::Keyboard::Instance()->AttachOnKeyDown(
		[=](const Events::Key& key)
		{
			if (key.scancode == SDL_SCANCODE_ESCAPE)
			{
				app->PopState();
			}

			if (key.scancode == SDL_SCANCODE_SPACE)
			{
				app->OnExit();
			}
		}));
	}

}