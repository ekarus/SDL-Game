#include "CApp.h"
#include <iostream>
#include "CSurface.h"
#include "CTexture.h"
using namespace std;

CApp::CApp():run(true)
{
	tex=nullptr;
	win=nullptr;
	render=nullptr;
	SCREEEN_WIDTH=800;
	SCREEN_HEIGHT=600;
}

int CApp::onExecute()
{
	if(onInit()==false)
	{
		logError(cout,"onInit");
		return -1;
	}
	SDL_Event event;
	while(isRun())
	{
		while(SDL_PollEvent(&event))
		{
			onEvent(event);
		}
		onUpdate();
		onRender();
	}
	onCleanUp();
	return 0;
}

bool CApp::onInit()
{
	if(SDL_Init(SDL_INIT_EVERYTHING)== -1)
	{
		logError(cout,"SDL_Init");
		return false;
	}
	win=SDL_CreateWindow("SDL_Project",100,100,SCREEEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
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

	tex=CTexture::onLoad(render,"../Res/player.tga");
	if(tex==nullptr)
	{
		logError(cout,"CTexture::onLoad");
		return false;
	}
	return true;
}

void CApp::onEvent( SDL_Event& event )
{
	switch (event.type)
	{
	case SDL_QUIT: Run(false);break;
	case SDL_MOUSEBUTTONDOWN: ;break;
	case SDL_KEYDOWN: ;break;
	default:
		break;
	}
}

void CApp::onUpdate()
{

}

void CApp::onRender()
{
	SDL_RenderClear(render);
	CTexture::onDraw(tex,render,0,0);
	SDL_RenderPresent(render);
}

void CApp::onCleanUp()
{
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

void CApp::logError( std::ostream& os,std::string msg )
{
	os<<"["<<msg<<"] : "<<SDL_GetError()<<endl;
}
