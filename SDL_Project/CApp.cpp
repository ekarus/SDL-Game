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
using namespace std;

CApp::CApp()
{
	run=false;
	SCREEN_WIDTH=300;
	SCREEN_HEIGHT=300;
}

CApp::~CApp()
{
}

int CApp::onExecute()
{
	if(OnInit()==false)
	{
		logError(cout,"onInit");
		return -1;
	}
	run=true;
	SDL_Event event;
	CFPS* fps=CFPS::Instance();
	while(isRun())
	{
		while(SDL_PollEvent(&event))
		{
			OnEvent(&event);
		}
		fps->onUpdate();
		OnUpdate(fps->getSpeedFactor());
		OnRender();
	}
	OnCleanUp();
	return 0;
}

bool CApp::OnInit()
{
	if(SDL_Init(SDL_INIT_EVERYTHING)== -1)
	{
		logError(cout,"SDL_Init");
		return false;
	}
	try
	{
		Window::Instance("SDL - Life Game", SCREEN_WIDTH, SCREEN_HEIGHT);
		Renderer::Instance();
	}
	catch (std::exception& ex)
	{
		logError(cout,ex.what());
	}

	PushState(CIntroScreen::Instance());
	return true;
}

void CApp::OnEvent( SDL_Event* event )
{
	IEventHandler::onEvent(event);
	states.back()->onEvent(event);
}

void CApp::OnUpdate( float time )
{
	states.back()->OnUpdate(CFPS::Instance()->getSpeedFactor());
}

void CApp::OnRender()
{
	SDL_RenderClear(Renderer::Instance());

	states.back()->OnRender();

	SDL_RenderPresent(Renderer::Instance());
}

void CApp::OnCleanUp()
{
	while ( !states.empty() ) {
		states.back()->OnCleanUp();
		states.pop_back();
	}

	Renderer::Delete();
	Window::Delete();
	SDL_Quit();
}

void CApp::logError( std::ostream& os,std::string msg )
{
	os<<""<<msg<<" : "<<SDL_GetError()<<endl;
}

void CApp::OnExit()
{
	run=false;
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
}

void CApp::PopState()
{
	if(!states.empty())
	{
		states.back()->OnCleanUp();
		states.pop_back();
		if(!states.empty())
		{
			states.back()->OnResume();
		}
	}
}

void CApp::ChangeState( IGameState* state )
{
	if(!states.empty())
	{
		states.back()->OnCleanUp();
		states.pop_back();
	}
	states.push_back(state);
	state->OnInit();
}