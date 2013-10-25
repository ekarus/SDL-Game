#include "CNpc.h"

CNpc::CNpc()
{
	live=true;
	speed=500;
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

			//перепроверям подходит ли нам цель
			if(!goal->isLive() || goal->getSize().getLenght()>=size.getLenght())
			{
				goal=nullptr;
			}
			else
			{
				//если подходит то движемся к цели
				acc=(goal->getCenter()-getCenter()).normalize()*speed;
			}
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
		tex->setColor(color);
		if(goal!=nullptr)
		{
			target_tex->setColor(color);
			target_tex->Draw(goal->getPos().x-10,goal->getPos().y-10,goal->getSize().x+20,goal->getSize().y+20);
		}
	}
}

bool CNpc::OnLoad( std::string file,SDL_Renderer* render )
{
	if(!(target_tex=CTextureManager::Instance()->LoadTexturePtr("../Res/target.png")))
		return false;
	return CMoveObject::OnLoad(file,render);
}

void CNpc::OnCleanUp()
{
	CMoveObject::OnCleanUp();
}

bool CNpc::OnCollision( CEntity* entity )
{
	return CMoveObject::OnCollision(entity);
}

void CNpc::OnRestart()
{
	CMoveObject::OnRestart();
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

bool CNpc::onEat( CEntity* entity )
{
	goal=nullptr;
	return CMoveObject::onEat(entity);
}