#pragma once

#include "Pawn.h"
#include "Factory.h"
#include "PawnFactory.h"
#include <boost/shared_ptr.hpp>

class PawnController
{
public:
	typedef boost::shared_ptr<PawnController> ControllerSharedPtr;

	PawnController(Pawn::PawnSharedPtr pawn):pawn_(pawn)
	{
	}

/*
	virtual void OnInit()
	{
		if(pawn_ = CreatePawn())
		{
			if(pawn_->OnInit())
			{
				/ *pawn_->setPos(Geometry::Position(50,50));
				pawn_->setSize(Geometry::Size(50,50));* /

				//Pawn::list_.push_back(pawn_);
			}
		}
	}

	virtual Pawn::PawnSharedPtr CreatePawn() = 0;
*/

	/*virtual ~PawnController()
	{
		/ *Pawn::PawnsList::iterator element = std::find(Pawn::list_.begin(), Pawn::list_.end(), pawn_);
		if(element != Pawn::list_.end())
			Pawn::list_.erase(element);* /
	}*/

	virtual ~PawnController()
	{
	}

	virtual void OnUpdate(Game::FrameTime time)
	{
		pawn_->OnUpdate(time);
	}

	virtual void OnRender()
	{
		if(pawn_->IsVisible())
			pawn_->OnRender();
	}

	virtual void OnCollide(Pawn::PawnSharedPtr pawn)
	{
		pawn_->setVisible(false);
	}

	virtual Pawn::PawnSharedPtr GetPawn() const
	{
		return pawn_;
	}

	virtual void SetPawn(Pawn::PawnSharedPtr pawn)
	{
		pawn_ = pawn;
	}

private:
	Pawn::PawnSharedPtr pawn_;
};