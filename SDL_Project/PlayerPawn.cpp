#include "PlayerPawn.h"
#include "AnimatedTextureManager.h"

PlayerPawn::PlayerPawn()
{
}

PlayerPawn::~PlayerPawn()
{
}

void PlayerPawn::OnUpdate( Game::FrameTime time)
{
	Pawn::OnUpdate(time);
}

void PlayerPawn::OnRender()
{
	Pawn::OnRender();
}

bool PlayerPawn::OnInit()
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

void PlayerPawn::OnCleanUp()
{
	Pawn::OnCleanUp();
}

void PlayerPawn::OnRestart()
{
	Pawn::OnRestart();
}