#include "CApp.h"
#include <iostream>
#include "CSurface.h"
#include "CTexture.h"
#include "CFPS.h"
#include "CCollision.h"
#include "CIntroScreen.h"
#include "CGameMenu.h"
#include "CWindow.h"
#include "CRender.h"
#include <exception>
#include "CLogger.h"
#include "StringHelper.h"
#include "EventManager.h"
using namespace std;

namespace Detail
{
	CApp::CApp()
	{
		is_run_ = false;
		SCREEN_WIDTH = 600;
		SCREEN_HEIGHT = 600;
	}

	CApp::~CApp()
	{
	}

	int CApp::onExecute()
	{
		if(OnInit()==false)
		{
			LOG_ERROR("Could't start application");
			return -1;
		}
		is_run_ = true;
		SDL_Event event;
		FPS::ObjectPtr fps = FPS::Instance();

		while(isRun())
		{
			Events::EventManager::Instance()->Update();
			/*while(SDL_PollEvent(&event))
			{
				OnEvent(&event);
			}*/
			fps->onUpdate();
			OnUpdate(fps->getSpeedFactor());
			WindowSingleton::Instance()->SetTitle(StringHelper::String::ToString(fps->getFPS()));
			OnRender();
		}

		OnCleanUp();
		return 0;
	}

	bool CApp::OnInit()
	{
		Logger::Instance()->setOutput(LogOutput::COUT | LogOutput::FILE);

		if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
		{
			LOG_ERROR("Could't init SDL");
			return false;
		}
		if (WindowSingleton::Instance("SDL - Life Game", SCREEN_WIDTH, SCREEN_HEIGHT)->Get() != nullptr)
		{
			LOG_INFO("Window created");

			WindowSingleton::Instance()->SetIcon("..\\Res\\target.png");
		}
		else
		{
			LOG_ERROR("Could not create window");
			assert(false);
			return false;
		}
		if (RendererSingleton::Instance()->Get() != nullptr)
		{
			LOG_INFO("Render created");
		}
		else
		{
			LOG_ERROR("Could not create renderer");
			assert(false);
			return false;
		}
		PushState(IntroScreen::Instance());
		return true;
	}

	void CApp::OnEvent( SDL_Event* event )
	{
		IEventHandler::onEvent(event);
		/*if (!states.empty())
		{
			states.back()->onEvent(event);
		}*/
	}

	void CApp::OnUpdate( float time )
	{
		if (!states.empty())
		{
			states.back()->OnUpdate(FPS::Instance()->getSpeedFactor());
		}
	}

	void CApp::OnRender()
	{
		SDL_RenderClear(RendererSingleton::Instance()->Get());

		if (!states.empty())
		{
			states.back()->OnRender();
		}

		SDL_RenderPresent(RendererSingleton::Instance()->Get());
	}

	void CApp::OnCleanUp()
	{
		while ( !states.empty() ) {
			states.back()->OnCleanUp();
			states.pop_back();
		}

		RendererSingleton::Delete();
		WindowSingleton::Delete();

		SDL_Quit();
	}

	void CApp::OnExit()
	{
		is_run_ = false;
		LOG_INFO("Exit app (is_run = " << is_run_ << ")");
	}

	void CApp::OnResize( int w,int h )
	{
		cout<<"OnResize "<<w<<" "<<h<<endl;
		SCREEN_WIDTH=w;
		SCREEN_HEIGHT=h;
	}

	void CApp::PushState( IGameState* state )
	{
		if(!states.empty())
		{
			states.back()->OnPause();
		}
		states.push_back(state);
		state->OnInit();

		LOG_INFO("PushState states.size = " << states.size());
	}

	void CApp::PopState()
	{
		if(!states.empty())
		{
			IGameState* state;
			state = states.back();
			state->OnCleanUp();
			states.pop_back();
			//delete state;

			if(!states.empty())
			{
				states.back()->OnResume();
			}

			LOG_INFO("PopState states.size = " << states.size());
		}
	}

	void CApp::ChangeState( IGameState* state )
	{
		if(!states.empty())
		{
			IGameState* state;
			state = states.back();
			state->OnCleanUp();
			states.pop_back();
			//delete state;
		}
		states.push_back(state);
		state->OnInit();

		LOG_INFO("ChangeState states.size = " << states.size());
	}
}