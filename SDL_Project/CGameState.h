#pragma once

class CGameState
{
public:
	CGameState();
	virtual ~CGameState();

	virtual bool OnInit() = 0;

	virtual void OnUpdate(float time) = 0;

	virtual void OnRender() = 0;

	virtual void OnCleanUp() = 0;

	virtual void OnPause() = 0;

	virtual void OnResume() = 0;

private:

};
