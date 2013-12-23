#include "PawnFactory.h"

Pawn::PawnSharedPtr EnemyFactory::CreatePawn()
{
	return boost::make_shared<EnemyPawn>();
}

Pawn::PawnSharedPtr PlayerFactory::CreatePawn()
{
	return boost::make_shared<PlayerPawn>();
}