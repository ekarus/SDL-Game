#pragma once
#include "Pawn.h"
#include "Factory.h"
#include <vector>
#include "AnimatedTexture.h"

class PlayerPawn : public Pawn
{
public:
	PlayerPawn();
	virtual ~PlayerPawn();

	virtual void OnUpdate(Game::FrameTime) override;
	virtual void OnRender() override;
	virtual bool OnInit() override;
	virtual void OnCleanUp() override;
	virtual void OnRestart() override;
};
