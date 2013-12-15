#include "NpcController.h"
#include "EnemyPawn.h"

void NpcController::OnCollide( Pawn::PawnPtr pawn )
{
	GetPawn()->StopMove();
}

void NpcController::OnRender()
{
	PawnController::OnRender();
}

void NpcController::OnUpdate( Game::FrameTime time )
{
	PawnController::OnUpdate(time);

	if(GetPawn()->getPos() < Geometry::Position(100,100))
		GetPawn()->SetAcceleration(Physics::Acceleration(10,10));
	else
		GetPawn()->StopMove();
	
}

Pawn::PawnPtr NpcController::CreatePawn()
{
	return EnemyPawn::EnemyPawnFactory::Create();
}

void NpcController::OnInit()
{
	PawnController::OnInit();
}
