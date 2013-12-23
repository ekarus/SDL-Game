#pragma once
#include "Pawn.h"
#include "EnemyPawn.h"
#include "PlayerPawn.h"
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>

class PawnFactory
{
public:
	virtual Pawn::PawnSharedPtr CreatePawn() = 0;
};

class EnemyFactory : public PawnFactory
{
public:
	virtual Pawn::PawnSharedPtr CreatePawn() override;
};

class PlayerFactory : public PawnFactory
{
public:
	virtual Pawn::PawnSharedPtr CreatePawn() override;
};