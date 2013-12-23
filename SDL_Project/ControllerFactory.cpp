#include "ControllerFactory.h"

PawnController::ControllerSharedPtr NpcControllerFactory::CreateController( Pawn::PawnSharedPtr pawn )
{
	return boost::make_shared<NpcController>(pawn);
}