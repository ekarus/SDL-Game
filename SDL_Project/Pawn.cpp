#include "Pawn.h"
#include "AnimatedTextureManager.h"
#include "CLogger.h"
#include <iostream>

Pawn::Pawn():is_live_(true), color_(Color::white), speed_value_(100), velocity_(0,0), acceleration_(0,0), max_velocity_(100,100)
{
	//list_.push_back(this);
}

Pawn::~Pawn()
{
	/*PawnsList::iterator element = std::find(list_.begin(),list_.end(),this);
	if(element != list_.end())
		list_.erase(element);*/
}

bool Pawn::OnInit()
{
	if(texture_ = AnimatedTextureManagerSingleton::Instance()->Load("../Res/menu.png"))
	{
		texture_->getAnimator().setFrameCount(1);
		texture_->getAnimator().setStep(0);
		return true;
	}
	else
	{
		LOG_ERROR("Could not load texture");
	}

	return texture_ != nullptr;
}

void Pawn::OnUpdate(Game::FrameTime time)
{
	//Geometry::Position new_position = position_ + velocity_ * time;

	position_ = GetNextPosition(time);

	Physics::Velocity new_velocity = velocity_ + acceleration_ * time;

	if (new_velocity < max_velocity_)
	{
		velocity_ = new_velocity;
	}
	else
	{
		velocity_ = max_velocity_;
	}
}

void Pawn::OnRender()
{
	texture_->setColor(color_);
	texture_->Draw(getRect());
}

void Pawn::OnCleanUp()
{
}

void Pawn::OnRestart()
{
	velocity_ = Physics::Velocity(0,0);
	acceleration_ = Physics::Acceleration(0,0);
}

void Pawn::StopMove()
{
	if(velocity_.getLenght() > 10)
	{
		acceleration_ = velocity_ * (-0.5);
	}
	else
	{
		acceleration_ = Physics::Acceleration(0,0);
		velocity_ = Physics::Velocity(0,0);
	}
}

Geometry::Position Pawn::GetNextPosition(Game::FrameTime time)
{
	Geometry::Position new_position = position_ + velocity_ * time;

	return new_position;
}

//Pawn::PawnsList Pawn::list_;