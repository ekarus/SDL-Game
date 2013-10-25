#pragma once
#include "IGameState.h"
#include "CApp.h"
#include "Singleton.h"
#include "CTextureManager.h"

class CGameMenu: public IGameState, public Singleton<CGameMenu>
{
public:

	virtual bool OnInit();

	virtual void OnUpdate( float time );

	virtual void OnRender();

	virtual void OnCleanUp();

	virtual void OnPause();

	virtual void OnResume();

protected:

	CGameMenu();

	virtual ~CGameMenu();

	virtual void OnKeyDown( SDL_Keysym key );

private:
	friend class Singleton<CGameMenu>;

	CApp* app;
	TextureSharedPtr bg;
};