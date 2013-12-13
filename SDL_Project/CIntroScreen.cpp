#include "CIntroScreen.h"
#include <iostream>
#include "CGameMenu.h"
#include "CGame.h"
#include "KeyboardEvent.h"
#include "CWindow.h"

namespace Detail
{
	bool IntroScreenImpl::OnInit()
	{
		bool result = true;

		AttachOnEvents();

		app = AppSingleton::Instance();

		back_ground_ = TextureManagerSingleton::Instance()->Load("../Res/intro.png");

		if(back_ground_ == nullptr)
		{
			LOG_ERROR("Could't load intro screen texture");
			result = false;
		}

		return result;
	}

	void IntroScreenImpl::OnUpdate( float time )
	{
	}

	void IntroScreenImpl::OnRender()
	{
		WindowSingleton::ObjectPtr window = WindowSingleton::Instance();

		back_ground_->Draw(0, 0, window->GetWidth(), window->GetHeight());
	}

	void IntroScreenImpl::OnCleanUp()
	{
		IGameState::OnCleanUp();
	}

	void IntroScreenImpl::OnPause()
	{
		IGameState::OnPause();
	}

	void IntroScreenImpl::OnResume()
	{
		IGameState::OnResume();
	}

	IntroScreenImpl::IntroScreenImpl()
	{
	}

	IntroScreenImpl::~IntroScreenImpl()
	{
	}

	void IntroScreenImpl::AttachOnEvents()
	{
		/*boost::signals2::connection keyboard_connection = Events::Keyboard::Instance()->AttachOnKeyDown([=](const Events::Key& key)
		{
			if(key.scancode == SDL_SCANCODE_SPACE)
			{
				app->PushState(GameSingleton::Instance());
			}
			if(key.scancode == SDL_SCANCODE_ESCAPE)
			{
				app->OnExit();
			}
		});*/

		AddConnection(Events::Keyboard::Instance()->AttachOnKeyDown(
		[=](const Events::Key& key)
		{
			if(key.scancode == SDL_SCANCODE_SPACE)
			{
				app->ChangeState(GameSingleton::Instance());
			}
			if(key.scancode == SDL_SCANCODE_ESCAPE)
			{
				app->OnExit();
			}
		}));
	}
}