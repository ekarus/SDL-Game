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

	x=0;y=0;
}

int CApp::onExecute()
{
	if(OnInit()==false)
	{
		logError(cout,"onInit");
		return -1;
	}
	SDL_Event event;
	while(isRun())
	{
		while(SDL_PollEvent(&event))
		{
			OnEvent(&event);
		}
		OnUpdate();
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

void CApp::OnEvent( SDL_Event* event )
{
	CEvent::onEvent(event);
}

void CApp::OnUpdate()
{

}

void CApp::OnRender()
{
	SDL_RenderClear(render);
	CTexture::onDraw(tex,render,x,y);
	SDL_RenderPresent(render);
}

void CApp::OnCleanUp()
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

void CApp::OnExit()
{
	Run(false);
}

void CApp::OnKeyDown( SDL_Keysym key )
{
	cout<<"OnKeyDown "<<key.sym<<" "<<key.mod<<" "<<key.scancode<<endl;
	if(key.scancode==SDL_Scancode::SDL_SCANCODE_ESCAPE)
		OnExit();
}

void CApp::OnMouseMove( int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle )
{
	//cout<<mX<<" "<<mY<<" ; "<<relX<<" "<<relY<<" ; "<<Left<<Right<<Middle<<endl;
	x=mX;
	y=mY;
}

void CApp::OnLButtonDown( int mX, int mY )
{
	cout<<"OnLButtonDown "<<mX<<" "<<mY<<endl;
}

void CApp::OnRButtonDown( int mX, int mY )
{
	cout<<"OnRButtonDown "<<mX<<" "<<mY<<endl;
}

void CApp::OnResize( int w,int h )
{
	cout<<"OnResize "<<w<<" "<<h<<endl;
}
