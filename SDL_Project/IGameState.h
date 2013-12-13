#pragma once

#include "SignalsManager.h"

//Состояние игры
class IGameState: public SignalsManager
{
public:
	typedef boost::signals2::signal<void(void)> PauseSignal;
	typedef boost::signals2::signal<void(void)> ResumeSignal;

	boost::signals2::connection AttachOnPause(const PauseSignal::slot_type& slot)
	{
		return pause_signal_.connect(slot);
	}

	boost::signals2::connection AttachOnResume(const ResumeSignal::slot_type& slot)
	{
		return resume_signal_.connect(slot);
	}

	IGameState()
	{
	}

	virtual ~IGameState()
	{
	}

	virtual bool OnInit() = 0;

	//************************************
	// Parameter: float time-врямя прошедшее после предыдущего апдейта в секундах
	//************************************
	virtual void OnUpdate(float time) = 0;

	virtual void OnRender() = 0;

	virtual void OnCleanUp()
	{
		SignalsManager::Disconnect();
	}

	virtual void OnPause()
	{
		SignalsManager::Block();

		pause_signal_();
	}

	virtual void OnResume()
	{
		SignalsManager::UnBlock();

		resume_signal_();
	}

protected:

	virtual void AttachOnEvents() = 0;

private:
	PauseSignal pause_signal_;
	ResumeSignal resume_signal_;
};
