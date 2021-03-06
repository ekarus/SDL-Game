#include "CEntity.h"
#include "CCollision.h"

std::vector<CEntity*> CEntity::entity_list;

void CEntity::OnUpdate( float time )
{
	animator.OnAnimate();
}

void CEntity::OnRender( SDL_Renderer* render )
{
	CTexture::setColor(tex,color);
	CTexture::onDraw(tex,render,animator.getCurrFrame(),animator.getFrameCount(),&getRect());
}

void CEntity::OnCleanUp()
{
	SDL_DestroyTexture(tex);
}

CEntity::CEntity():pos(0,0),size(20,20)
{
	tex=nullptr;
	isVisible=true;
}

CEntity::~CEntity()
{

}

bool CEntity::OnLoad( std::string file,SDL_Renderer* render,int frame_count )
{
	if((tex=CTexture::onLoad(render,file))!=nullptr)
	{
		animator.setFrameCount(frame_count);
		return true;
	}
	return false;
}

bool CEntity::OnLoad( std::string file,SDL_Renderer* render )
{
	if((tex=CTexture::onLoad(render,file))!=nullptr)
	{
		animator.setFrameCount(CTexture::getFrameCount(tex));
		return true;
	}
	return false;
}

Vector2d CEntity::getCenter() const
{
	Vector2d res;
	res.X(pos.X()+size.X()/2);
	res.Y(pos.Y()+size.Y()/2);
	return res;
}

bool CEntity::isCollide( CEntity* entity, float x, float y )
{
	Vector2d c_c=entity->getCenter()-Vector2d(x+size.x/2,y+size.y/2);
	float s_s=entity->getSize().X()*0.5+getSize().X()*0.5;
	return c_c.getLenght()-s_s<=0;
}

bool CEntity::postValid( float newX, float newY )
{
	bool res=true;
	res=checkMapCollide(this,newX,newY);
	for (int i = 0; i < entity_list.size(); i++)
	{
		if(checkEntityCollide(entity_list[i],newX,newY)==false)
		{
			res=false;
		}
	}
	return res;
}

bool CEntity::checkEntityCollide( CEntity* entity, float x,float y )
{
	if(entity!=this &&  entity!=nullptr && entity->live && isCollide(entity,x,y))
	{
		CCollision c;
		c.entityA=this;
		c.entityB=entity;
		CCollision::collision_list.push_back(c);
		return false;
	}
	return true;
}

bool CEntity::OnCollision( CEntity* entity )
{
	return true;
}

void CEntity::OnRestart()
{
	pos=Vector2d(0,0);
	size=Vector2d(0,0);
	live=true;
}

void CEntity::OnEntityNear(CEntity* entity)
{

}

bool CEntity::checkMapCollide(CEntity* entity, float x,float y )
{
	bool res=true;
	int w=800,h=600;
	if(x+size.x>w)
	{
		entity->setX(w-entity->getSize().x);
		res=false;
	}
	else if(x<0)
	{
		entity->setX(0);
		res=false;
	}
	if(y+size.y>h)
	{
		entity->setY(h-entity->getSize().y);
		res=false;
	}
	else if(y<0)
	{
		entity->setY(0);
		res=false;
	}
	return res;
}

