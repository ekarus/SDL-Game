#pragma once
#include "Pawn.h"
#include "Factory.h"
#include <vector>
#include "AnimatedTexture.h"

class EnemyPawn : public Pawn
{
public:

	typedef Factory<EnemyPawn> EnemyPawnFactory;
	typedef EnemyPawnFactory::ObjectPtr PawnPtr;

	EnemyPawn();
	virtual ~EnemyPawn();

	virtual void OnUpdate(Game::FrameTime) override;
	virtual void OnRender() override;
	virtual bool OnInit() override;
	virtual void OnCleanUp() override;
	virtual void OnRestart() override;

};
