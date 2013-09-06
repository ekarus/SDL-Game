#include "CGame.h"
#include <stdlib.h>
#include <iostream>
#include "CGameMenu.h"
#include "CCollision.h"


CGame::CGame() 
{
	fail=false;
	live_obj=0;
	obj_count=0;
	obj_incr=5;
	player=nullptr;

	app=CApp::getInstance();
}


CGame::~CGame()
{

}



void CGame::ObjectsCheck( ) 
{
	for (int i = 0; i < npcs.size(); i++)
	{
		for(int j=0;j<npcs.size();j++)
		{
			if(i!=j)
			{
				if(npcs[i]->isLive() && npcs[j]->isLive())
				{
					npcs[i]->OnEntityNear(npcs[j]);
					npcs[j]->OnEntityNear(npcs[i]);
				}
			}
		}
		npcs[i]->OnEntityNear(player);
	}
	
}


void CGame::Restart()
{
	for(int i=0;i<CEntity::entity_list.size();i++)
	{
		CEntity* e=CEntity::entity_list[i];
		int s=8+rand()%20;
		e->OnRestart();
		e->setSize(Vector2d(s,s));
		e->setPos(Vector2d(rand()%(app->getScrWidth()-s),rand()%(app->getScrHeight()-s)));
		e->setColor(Colors(rand()%4));
	}
	player->setColor(red);
	player->setSize(Vector2d(15,15));
	player->setGoalPoint(player->getCenter());

}

void CGame::NextLevel()
{
	AddNPC(obj_incr);
	Restart();
}

bool CGame::OnInit()
{
	cout<<"GAME --- INIT"<<endl;
	player=new CPlayer();
	player->OnLoad("../Res/circle_a.png",app->getRender());
	CEntity::entity_list.push_back(player);
	srand(time(nullptr));
	AddNPC(3);
	Restart();
	return true;

}

void CGame::OnUpdate(float time)
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

		live_obj=0;

		for(int i=0;i<npcs.size();i++)
		{
			if(npcs[i]->isLive())
			{
				live_obj++;
			}
		}
		ObjectsCheck();
		if(player->isLive() && live_obj==0)
		{
			NextLevel();
		}
		if(player->isLive()==false)
		{
			Restart();
		}
}

void CGame::OnRender()
{
	for(int i=0;i<CEntity::entity_list.size();++i)
	{
		if(CEntity::entity_list[i]!=nullptr)
		{
			if(CEntity::entity_list[i]->getIsVisible())
			{
				CEntity::entity_list[i]->OnRender(app->getRender());
			}
		}
	}
	/*SDL_RenderClear(app->getRender());
	SDL_RenderPresent(app->getRender());*/
}

void CGame::OnCleanUp()
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
}

void CGame::OnLButtonDown( int mX, int mY )
{

}

void CGame::OnLButtonUp( int mX, int mY )
{

}

void CGame::OnRButtonDown( int mX, int mY )
{

}

void CGame::OnKeyDown( SDL_Keysym key )
{

	if(key.sym=='r')
	{
		Restart();
	}
	if(key.sym=='q')
	{
		player->setSize(player->getSize()*1.1f);
	}
	if(key.sym=='e')
	{
		player->setSize(player->getSize()*0.9f);
	}
	if(key.sym=='w')
	{
		player->onMove(Vector2d(0,-1));
	}
	if(key.sym=='s')
	{
		player->onMove(Vector2d(0,1));
	}
	if(key.sym=='a')
	{
		player->onMove(Vector2d(-1,0));
	}
	if(key.sym=='d')
	{
		player->onMove(Vector2d(1,0));
	}
	if(key.scancode==SDL_SCANCODE_ESCAPE)
	{
		app->PushState(CGameMenu::getInstance());
	}
}

void CGame::OnMouseMove( int x, int y, int relX, int relY, bool Left,bool Right,bool Middle )
{
	if (Left)
	{
		player->setGoalPoint(Vector2d(x,y));
	}
}

void CGame::AddNPC( int count )
{
	obj_count+=count;
	for(int i=0;i<count;i++)
	{
		CMoveObject* e=new CNpc();
		e->OnLoad("../Res/circle_a.png",app->getRender());
		CEntity::entity_list.push_back(e);
		npcs.push_back(e);
	}
}

void CGame::OnPause()
{
	cout<<"GAME --- PAUSE"<<endl;
}

void CGame::OnResume()
{
	cout<<"GAME --- RESUME"<<endl;
}

CGame CGame::inst;


