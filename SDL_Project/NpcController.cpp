#include "NpcController.h"
#include "EnemyPawn.h"
#include "PawnFactory.h"

void NpcController::OnCollide( Pawn::PawnSharedPtr pawn )
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