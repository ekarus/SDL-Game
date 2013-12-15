#pragma once

#include "Pawn.h"
#include "Factory.h"

class PawnController
{
public:

	typedef Factory<PawnController> PawnControllerFactory;
	typedef PawnControllerFactory::ObjectPtr PawnControllerPtr;

	PawnController()
	{
		
	}

	virtual void OnInit()
	{
		if(pawn_ = CreatePawn())
		{
			if(pawn_->OnInit())
			{
				/*pawn_->setPos(Geometry::Position(50,50));
				pawn_->setSize(Geometry::Size(50,50));*/

				Pawn::list_.push_back(pawn_);
			}
		}
	}

	virtual Pawn::PawnPtr CreatePawn() = 0;

	virtual ~PawnController()
	{
		Pawn::PawnsList::iterator element = std::find(Pawn::list_.begin(), Pawn::list_.end(), pawn_);
		if(element != Pawn::list_.end())
			Pawn::list_.erase(element);
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

	virtual void OnCollide(Pawn::PawnPtr pawn)
	{
		pawn_->setVisible(false);
	}

	virtual Pawn::PawnPtr GetPawn() const
	{
		return pawn_;
	}

private:
	Pawn::PawnPtr pawn_;
};