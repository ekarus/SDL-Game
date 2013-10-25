#include "CIntroScreen.h"
#include <iostream>
#include "CGameMenu.h"
#include "CGame.h"

bool CIntroScreen::OnInit()
{
	app=CApp::Instance();
	if(back_ground_ = CTextureManager::Instance()->LoadTexturePtr("../Res/intro.png"))
	{
		return true;
	}
	else
	{
		app->logError(cerr,"CIntroScreen::OnInit");
		return false;
	}
}

void CIntroScreen::OnUpdate( float time )
{
}

void CIntroScreen::OnRender()
{
	back_ground_->Draw(0,0,app->getScrWidth(),app->getScrHeight());
}

void CIntroScreen::OnCleanUp()
{
	Delete();
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
		app->ChangeState(CGame::Instance());
	}
	if(key.scancode==SDL_SCANCODE_ESCAPE)
	{
		app->OnExit();
	}
}

CIntroScreen::CIntroScreen()
{
}

CIntroScreen::~CIntroScreen()
{
	std::cout<<"~CIntroScreen()"<<std::endl;
}