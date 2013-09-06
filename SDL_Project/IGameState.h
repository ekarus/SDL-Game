#pragma once

#include "IEventHandler.h"

class IGameState: public IEventHandler
{
public:
	IGameState();
	virtual ~IGameState();

	virtual bool OnInit() = 0;

	virtual void OnUpdate(float time) = 0;

	virtual void OnRender() = 0;

	virtual void OnCleanUp() = 0;

	virtual void OnPause() = 0;

	virtual void OnResume() = 0;

private:

};
