#include "CPlayer.h"
#include <iostream>
#include "TextureManager.h"
#include "CGame.h"

CPlayer::CPlayer()
{
	live = true;
	speed = 500;
	goalPoint = getCenter();
	hasGoal = false;
	maxVel = Vector2d(100,100);
}

CPlayer::~CPlayer()
{
}

void CPlayer::OnUpdate( float time )
{
	if (live)
	{
		if((goalPoint-getCenter()).getLenght()<size.x/2)
		{
			hasGoal=false;
		}
		if(hasGoal)
		{
			acc=(goalPoint-getCenter()).normalize()*speed;;
		}
		else
		{
			stopMove();
		}

		CMoveObject::OnUpdate(time);
	}
}

void CPlayer::OnRender( SDL_Renderer* render )
{
	if(live)
	{
		CMoveObject::OnRender(render);
		goal_texture->setColor(Color::white);
		if(hasGoal)
			goal_texture->Draw(goalPoint.x,goalPoint.y,10,10);
	}
}

bool CPlayer::OnLoad( std::string file,SDL_Renderer* render )
{
	goal_texture = TextureManagerSingleton::Instance()->Load(file);

	return CMoveObject::OnLoad(file,render);
}

void CPlayer::OnCleanUp()
{
	CMoveObject::OnCleanUp();
}

bool CPlayer::OnCollision( CEntity* entity )
{
	return CMoveObject::OnCollision(entity);
}

void CPlayer::onMove( Vector2d dir )
{
	Vector2d v;
	dir=dir.normalize();
	v.x=(getCenter().x+dir.x*size.x);
	v.y=(getCenter().y+dir.y*size.y);
	setGoalPoint(v);
	CMoveObject::onMove(dir);
}