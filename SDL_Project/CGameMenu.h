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

	virtual void OnEvent(SDL_Event* event);

	static CGameMenu* getInstance(){return &inst;}

private:
	CGameMenu();

	static CGameMenu inst;
	CApp* app;
	SDL_Texture* bg;

	virtual void OnKeyDown( SDL_Keysym key );

};