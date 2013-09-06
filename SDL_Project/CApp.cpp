#include "CApp.h"
#include <iostream>
#include "CSurface.h"
#include "CTexture.h"
#include "CFPS.h"
#include "CCollision.h"
using namespace std;

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

	return true;
}

void CApp::OnEvent( SDL_Event* event )
{
	CEvent::onEvent(event);
}

void CApp::OnUpdate( float time )
{
	for(int i=0;i<CEntity::entity_list.size();++i)
	{
		if(CEntity::entity_list[i]!=nullptr)
		{
			CEntity::entity_list[i]->OnUpdate(time);
		}
	}
	for (int i = 0; i < CCollision::collision_list.size(); i++)
	{
		CEntity* A=CCollision::collision_list[i].entityA;
		CEntity* B=CCollision::collision_list[i].entityB;

		if(A==nullptr || B==nullptr)
			continue;
		else
		{
			if(A->OnCollision(B))
			{
				B->OnCollision(A);
			}
		}
	}
	CCollision::collision_list.clear();
}

void CApp::OnRender()
{
	for(int i=0;i<CEntity::entity_list.size();++i)
	{
		if(CEntity::entity_list[i]!=nullptr)
		{
			if(CEntity::entity_list[i]->getIsVisible())
			{
				CEntity::entity_list[i]->OnRender(render);
			}
		}
	}
}

void CApp::OnCleanUp()
{
	for(auto i=CEntity::entity_list.begin();i!=CEntity::entity_list.end();++i)
	{
		if(*i!=nullptr)
		{
			(*i)->OnCleanUp();
			delete *i;
		}
	}
	CEntity::entity_list.clear();
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
	SCREEN_WIDTH=w;
	SCREEN_HEIGHT=h;
}
