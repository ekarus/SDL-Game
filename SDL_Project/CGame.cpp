#include "CGame.h"
#include <stdlib.h>
#include <iostream>


CGame::CGame() 
{
	pause=false;
	mouse_press=false;
	fail=false;
	live_obj=0;
	obj_count=0;
	obj_incr=5;
	player=nullptr;
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
		int s=5+rand()%20;
		e->OnRestart();
		e->setSize(Vector2d(s,s));
		e->setPos(Vector2d(rand()%(SCREEN_WIDTH-s),rand()%(SCREEN_HEIGHT-s)));
		e->setColor(Colors(rand()%4));
	}
	//player->OnRestart();
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
	CApp::OnInit();
	player=new CPlayer();
	player->OnLoad("../Res/circle_a.png",render);
	CEntity::entity_list.push_back(player);
	AddNPC(3);
	pause=false;
	GameObject::load_image(render);
	Restart();
	return true;

}

void CGame::OnUpdate(float time)
{
	CApp::OnUpdate(time);
	if(!pause)
	{
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
}

void CGame::OnRender()
{
	SDL_RenderClear(render);
	CApp::OnRender();
	SDL_RenderPresent(render);
}

void CGame::OnCleanUp()
{
	CApp::OnCleanUp();
}

void CGame::OnLButtonDown( int mX, int mY )
{
	mouse_press=true;
}

void CGame::OnLButtonUp( int mX, int mY )
{
	mouse_press=false;
}

void CGame::OnRButtonDown( int mX, int mY )
{
//	objects.push_back(GameObject());
//	objects.back().setPos(Vector2d(mX,SCREEN_HEIGHT-mY));
}

void CGame::OnKeyDown( SDL_Keysym key )
{
	CApp::OnKeyDown(key);
	if(key.sym=='r')
	{
		Restart();
	}
	if(key.sym=='q')
	{
		//objects[0].runBoost();
	}
	if(key.sym=='p')
	{
		if(pause)
			pause=false;
		else
			pause=true;
	}
	if(key.sym=='w')
	{
		//objects[0].setVelocity(Vector2d(0,-1).normalize()*objects[0].getSpeed());
		player->onMove(Vector2d(0,-1));
	}
	if(key.sym=='s')
	{
		//objects[0].setVelocity(Vector2d(0,1).normalize()*objects[0].getSpeed());
		player->onMove(Vector2d(0,1));
	}
	if(key.sym=='a')
	{
		//objects[0].setVelocity(Vector2d(-1,0).normalize()*objects[0].getSpeed());
		player->onMove(Vector2d(-1,0));
	}
	if(key.sym=='d')
	{
		//objects[0].setVelocity(Vector2d(1,0).normalize()*objects[0].getSpeed());
		player->onMove(Vector2d(1,0));
	}
}

void CGame::OnMouseMove( int x, int y, int relX, int relY, bool Left,bool Right,bool Middle )
{
	if (Left)
	{
		/*Vector2d v=Vector2d(x,y)-objects[0].getCenter();
		objects[0].setVelocity(v.normalize()*objects[0].getSpeed());*/
		player->setGoalPoint(Vector2d(x,y));
		//player->onMove(Vector2d(x,y));
	}
	else
	{
		//player->stopMove();
	}
}

void CGame::AddNPC( int count )
{
	obj_count+=count;
	for(int i=0;i<count;i++)
	{
		CMoveObject* e=new CNpc();
		e->OnLoad("../Res/circle_a.png",render);
		CEntity::entity_list.push_back(e);
		npcs.push_back(e);
	}
}


