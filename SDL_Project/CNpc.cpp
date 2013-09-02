#include "CNpc.h"

CNpc::CNpc()
{
	live=true;
	speed=250;
	maxVel=Vector2d(100,100);
}

CNpc::~CNpc()
{

}

void CNpc::OnUpdate( float time )
{
	if (live)
	{
		if(goal!=nullptr)
		{
			//vel=(goal->getCenter()-getCenter()).normalize()*speed;
			acc=(goal->getCenter()-getCenter()).normalize()*speed;
		}
		else
		{
			//stopMove();
		}
		CMoveObject::OnUpdate(time);
	}
}

void CNpc::OnRender( SDL_Renderer* render )
{
	if(live)
	{
		CMoveObject::OnRender(render);
		CTexture::setColor(tex,color);
		if(goal!=nullptr)
		CTexture::onDraw(tex,render,goal->getPos().x-2,goal->getPos().y-2,goal->getSize().x+4,goal->getSize().y+4);
	}
}

bool CNpc::OnLoad( std::string file,SDL_Renderer* render )
{
	return CMoveObject::OnLoad(file,render);
}

bool CNpc::OnLoad( SDL_Renderer* render )
{
	return CMoveObject::OnLoad("../Res/circle_a.png",render);
}

void CNpc::OnCleanUp()
{
	CMoveObject::OnCleanUp();
}

bool CNpc::OnCollision( CEntity* entity )
{
	return CMoveObject::OnCollision(entity);
	/*if(entity->getSize().getLenght()<=size.getLenght())
	{
	if(entity->getColor()!=color)
	{
	eat(entity);
	}
	return false;
	}
	return true;*/
}

void CNpc::OnRestart()
{
	goal=nullptr;
}

void CNpc::OnEntityNear( CEntity* entity )
{
	CMoveObject::OnEntityNear(entity);
	if(entity->getColor()!=color)
	{
		Vector2d dist=entity->getCenter()-getCenter();
		if(entity->getSize().getLenght()>=size.getLenght())
		{
			if(dist.getLenght()<entity->getSize().getLenght()*4)
				onDanger(entity->getCenter());
		}
		else
		{
			if(dist.getLenght()<size.getLenght()*8 && 
				(goal==nullptr || goal->getSize().getLenght()<entity->getSize().getLenght()))
			{
				setGoal(entity);
			}
		}
	}
}
