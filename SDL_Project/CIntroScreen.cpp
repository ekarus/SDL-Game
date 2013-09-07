#include "CIntroScreen.h"
#include <iostream>
#include "CGameMenu.h"
#include "CGame.h"

bool CIntroScreen::OnInit()
{
	app=CApp::getInstance();
	bg=CTexture::onLoad(app->getRender(),"../Res/intro.png");
	if(bg==nullptr)
	{
		app->logError(cerr,"CIntroScreen::OnInit");
		return false;
	}
	return true;
}

void CIntroScreen::OnUpdate( float time )
{
	
}

void CIntroScreen::OnRender()
{
	SDL_RenderClear(app->getRender());
	CTexture::onDraw(bg,app->getRender(),0,0,app->getScrWidth(),app->getScrHeight());
	SDL_RenderPresent(app->getRender());
}

void CIntroScreen::OnCleanUp()
{
	SDL_DestroyTexture(bg);
}

void CIntroScreen::OnPause()
{
}

void CIntroScreen::OnResume()
{
}

void CIntroScreen::OnKeyDown( SDL_Keysym key )
{
	if(key.scancode==SDL_SCANCODE_SPACE)
	{
		app->ChangeState(CGame::getInstance());
	}
	if(key.scancode==SDL_SCANCODE_ESCAPE)
	{
		app->OnExit();
	}
}

CIntroScreen::CIntroScreen()
{
	bg=nullptr;
}

CIntroScreen CIntroScreen::inst;
