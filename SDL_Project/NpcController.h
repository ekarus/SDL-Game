#include "PawnController.h"

class NpcController: public PawnController
{
public:

	NpcController(Pawn::PawnSharedPtr pawn): PawnController(pawn)
	{
	}

	virtual void OnUpdate( Game::FrameTime time ) override;

	virtual void OnRender() override;

	virtual void OnCollide( Pawn::PawnSharedPtr pawn ) override;
};