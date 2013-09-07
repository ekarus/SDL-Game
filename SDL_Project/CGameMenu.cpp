#include "CGameMenu.h"
#include "CGame.h"
#include <iostream>

bool CGameMenu::OnInit()
{
	app=CApp::getInstance();
	bg=CTexture::onLoad(app->getRender(),"../Res/menu.bmp");
	if(bg==nullptr)
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
	//SDL_RenderClear(app->getRender());
	CGame::getInstance()->OnRender();
	SDL_SetTextureAlphaMod(bg,10);
	CTexture::onDraw(bg,app->getRender(),50,50,app->getScrWidth()-100,app->getScrHeight()-100);
	//SDL_RenderPresent(app->getRender());
}

void CGameMenu::OnCleanUp()
{
	SDL_DestroyTexture(bg);
}

void CGameMenu::OnPause()
{

}

void CGameMenu::OnResume()
{

}

void CGameMenu::OnEvent( SDL_Event* event )
{
	IEventHandler::onEvent(event);
}

CGameMenu::CGameMenu()
{
	bg=nullptr;
}

void CGameMenu::OnKeyDown( SDL_Keysym key )
{
	if(key.scancode==SDL_SCANCODE_ESCAPE)
	{
		app->PopState();
	}
}

CGameMenu CGameMenu::inst;
