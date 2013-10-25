#include "CGameMenu.h"
#include "CGame.h"
#include <iostream>

bool CGameMenu::OnInit()
{
	app = CApp::Instance();
	bg = CTextureManager::Instance()->LoadTexturePtr("../Res/menu.png");
	if(!bg)
	{
		app->logError(cerr,"CGameMenu::OnInit");
		return false;
	}
	return true;
}

void CGameMenu::OnUpdate( float time )
{

}

void CGameMenu::OnRender()
{
	CGame::Instance()->OnRender();
	bg->Draw(50,50,app->getScrWidth()-100,app->getScrHeight()-100);
}

void CGameMenu::OnCleanUp()
{
	Delete();
}

void CGameMenu::OnPause()
{

}

void CGameMenu::OnResume()
{

}

CGameMenu::CGameMenu()
{

}

void CGameMenu::OnKeyDown( SDL_Keysym key )
{
	if(key.scancode==SDL_SCANCODE_ESCAPE)
	{
		app->PopState();
	}
}

CGameMenu::~CGameMenu()
{
	std::cout<<"~CGameMenu()"<<std::endl;
}
