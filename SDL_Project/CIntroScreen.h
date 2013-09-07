#pragma once
#include "IGameState.h"
#include "SDL.h"
#include "CTexture.h"
#include "CApp.h"

class CIntroScreen: public IGameState
{
public:

	virtual bool OnInit();

	virtual void OnUpdate( float time );

	virtual void OnRender();

	virtual void OnCleanUp();

	virtual void OnPause();

	virtual void OnResume();

	static CIntroScreen* getInstance(){return &inst;}


protected:

	CIntroScreen();

private:

	static CIntroScreen inst;
	CApp* app;
	SDL_Texture* bg;

	virtual void OnKeyDown( SDL_Keysym key );

};