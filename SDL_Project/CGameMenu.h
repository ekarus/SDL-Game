#pragma once
#include "IGameState.h"
#include "SDL.h"
#include "CTexture.h"
#include "CApp.h"

class CGameMenu: public IGameState
{
public:

	virtual bool OnInit();

	virtual void OnUpdate( float time );

	virtual void OnRender();

	virtual void OnCleanUp();

	virtual void OnPause();

	virtual void OnResume();

	static CGameMenu* getInstance(){return &inst;}

protected:

	CGameMenu();

	virtual void OnKeyDown( SDL_Keysym key );

private:

	static CGameMenu inst;
	CApp* app;
	SDL_Texture* bg;

	

};