#include "PawnController.h"

class NpcController: public PawnController
{
public:
	typedef Factory<NpcController> NpcControllerFactory;
	typedef NpcControllerFactory::ObjectPtr NpcControllerPtr;

	virtual void OnUpdate( Game::FrameTime time ) override;

	virtual void OnRender() override;

	virtual void OnCollide( Pawn::PawnPtr pawn ) override;

	virtual void OnInit() override;

	virtual Pawn::PawnPtr CreatePawn() override;
};