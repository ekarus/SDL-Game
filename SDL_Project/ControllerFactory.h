#pragma once
#include "PawnController.h"
#include "NpcController.h"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class ControllerFactory
{
public:
	virtual PawnController::ControllerSharedPtr CreateController(Pawn::PawnSharedPtr) = 0;
};

class NpcControllerFactory : public ControllerFactory
{
public:
	virtual PawnController::ControllerSharedPtr CreateController(Pawn::PawnSharedPtr pawn) override;
};