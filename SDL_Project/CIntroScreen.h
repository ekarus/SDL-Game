#pragma once
#include "IGameState.h"
#include "CApp.h"
#include "Singleton.h"
#include "CTextureManager.h"

class CIntroScreen: public IGameState, public Singleton<CIntroScreen>
{
public:
	virtual bool OnInit();

	virtual void OnUpdate( float time );

	virtual void OnRender();

	virtual void OnCleanUp();

	virtual void OnPause();

	virtual void OnResume();

protected:
	CIntroScreen();

	virtual ~CIntroScreen();

private:
	friend class Singleton<CIntroScreen>;

	CApp* app;
	TextureSharedPtr back_ground_;

	virtual void OnKeyDown( SDL_Keysym key );

};