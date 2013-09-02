#include "CMoveObject.h"
#include <iostream>

void CMoveObject::OnUpdate( float time )
{
	CEntity::OnUpdate(time);
	Vector2d newPos=pos+vel*time;
	{
		if (postValid(newPos.x,pos.y))
		{
			pos.x=newPos.x;
		}
		else
		{
			//vel.x=0;
		}
		if (postValid(pos.x,newPos.y))
		{
			pos.y=newPos.y;
		}
		else
		{
			//vel.y=0;
		}
	}
	//pos=pos+vel*time;
	if(vel<maxVel)
	{
		vel=vel+acc*time;
	}
	else if(vel>maxVel)
	{
		vel.x=vel.normalize().x*maxVel.x;
		vel.y=vel.normalize().y*maxVel.y;
	}
}

CMoveObject::CMoveObject():vel(0,0),acc(0,0),speed(0),maxVel(150,150)
{
}

CMoveObject::~CMoveObject()
{

}

void CMoveObject::onMove( Vector2d dir )
{
	acc=(dir-getCenter()).normalize()*speed;
}

void CMoveObject::stopMove()
{
	if(vel.getLenght()>10)
	{
		acc=vel*(-0.5);
	}
	else
	{
		acc=Vector2d(0,0);
		vel=Vector2d(0,0);
	}
}

bool CMoveObject::eat( CEntity* entity )
{
	if(entity->isLive())
	{
		entity->setLive(false);
		this->size=this->size+entity->getSize()*0.5; 
		return true;
	}
	return false;
}

bool CMoveObject::OnCollision( CEntity* entity )
{
	CEntity::OnCollision(entity);
	if(entity->getSize().getLenght()<=size.getLenght() && entity->getColor()!=color)
	{
		eat(entity);
		return false;
	}
	return true;
}

void CMoveObject::onDanger( Vector2d point )
{
	acc=(getCenter()-point).normalize()*speed;
}

void CMoveObject::OnRestart()
{
	CEntity::OnRestart();
	vel=Vector2d(0,0);
	acc=Vector2d(0,0);
}

void CMoveObject::OnEntityNear(CEntity* entity)
{
	CEntity::OnEntityNear(entity);
}
