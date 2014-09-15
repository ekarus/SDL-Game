#include "EnemyPawn.h"
#include "AnimatedTextureManager.h"

EnemyPawn::EnemyPawn()
{
}

EnemyPawn::~EnemyPawn()
{
}

void EnemyPawn::OnUpdate( Game::FrameTime time)
{
	Pawn::OnUpdate(time);
}

void EnemyPawn::OnRender()
{
	Pawn::OnRender();
}

bool EnemyPawn::OnInit()
{
	Pawn::OnInit();

	if(texture_ = AnimatedTextureManagerSingleton::Instance()->Load("../Res/circle_a.png"))
	{
		texture_->getAnimator().setFrameCount(4);
		texture_->getAnimator().setStep(1);
		return true;
	}
	else
	{
		LOG_ERROR("Could not load texture");
	}

	return texture_ != nullptr;
}

void EnemyPawn::OnCleanUp()
{
	Pawn::OnCleanUp();
}

void EnemyPawn::OnRestart()
{
	Pawn::OnRestart();
}