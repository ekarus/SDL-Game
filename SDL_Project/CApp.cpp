#include "CApp.h"
#include <iostream>
#include "CSurface.h"
#include "CTexture.h"
#include "CFPS.h"
#include "CCollision.h"
#include "CIntroScreen.h"
#include "CGameMenu.h"
using namespace std;

CApp CApp::inst;

CApp::CApp()
{
	run=false;
	win=nullptr;
	render=nullptr;
	SCREEN_WIDTH=800;
	SCREEN_HEIGHT=600;
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
	Run(true);
	SDL_Event event;
	CFPS* fps=CFPS::getInstance();
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
	win=SDL_CreateWindow("SDL_Project",100,100,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
	if(win==nullptr)
	{
		logError(cout,"SDL_CreateWindow");
		return false;
	}
	render=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if(render==nullptr)
	{
		logError(cout,"SDL_CreateRenderer");
		return false;
	}

	PushState(CIntroScreen::getInstance());
	return true;
}

void CApp::OnEvent( SDL_Event* event )
{
	IEventHandler::onEvent(event);
	states.back()->onEvent(event);
}

void CApp::OnUpdate( float time )
{

	states.back()->OnUpdate(CFPS::getInstance()->getSpeedFactor());
}

void CApp::OnRender()
{
	SDL_RenderClear(render);

	states.back()->OnRender();

	SDL_RenderPresent(render);
}

void CApp::OnCleanUp()
{

	while ( !states.empty() ) {
		states.back()->OnCleanUp();
		states.pop_back();
	}

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

void CApp::logError( std::ostream& os,std::string msg )
{
	os<<"["<<msg<<"] : "<<SDL_GetError()<<endl;
}

void CApp::OnExit()
{
	Run(false);
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


