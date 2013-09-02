#include "GameObject.h"
#include "CTexture.h"

SDL_Texture* GameObject::image=nullptr;

void GameObject::Update( float time )
{
	if(isCan_move())
	{
		pos=pos+vel*time;
		vel=vel+acc*time;
	}
	if(boost_timer.isActive())
	{
		if(boost_timer.isEvent())
		{
			setSpeed(normal_speed);
			vel=vel.normalize()*speed;
		}
		else
		{
			if(size.getLenght()>5)
			{
				size=size-Vector2d(time*0.1,time*0.1);
			}
		}
	}
}

void GameObject::Draw(SDL_Renderer* render)
{
	if (live)
	{
		CTexture::setColor(image,color);
		CTexture::onDraw(image,render,pos.X(),pos.Y(),size.X(),size.Y());
	}
}

void GameObject::eat( GameObject& obj )
{
	size=size+obj.getSize();
	obj.kill();
	setGoal(0);
}

void GameObject::runBoost()
{
	boost_timer.setEventTime(Time::getCurrTimeSec()+1);
	boost_timer.Start();
	setSpeed(boost_speed);
	vel=vel.normalize()*speed;
}

Vector2d GameObject::getCenter() const
{
	Vector2d res;
	res.X(pos.X()+size.X()/2);
	res.Y(pos.Y()+size.Y()/2);
	return res;
}

void GameObject::load_image(SDL_Renderer* render)
{
	image=CTexture::onLoad(render,"../Res/circle.png");
}
