#include "CGameMenu.h"


bool CGameMenu::OnInit()
{
	app=CApp::getInstance();
	bg=CTexture::onLoad(app->getRender(),"../Res/menu.bmp");
	return true;
}

void CGameMenu::OnUpdate( float time )
{

}

void CGameMenu::OnRender()
{
	SDL_RenderClear(app->getRender());
	CTexture::onDraw(bg,app->getRender(),0,0,app->getScrWidth(),app->getScrHeight());
	SDL_RenderPresent(app->getRender());
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

}

void CGameMenu::OnKeyDown( SDL_Keysym key )
{
	if(key.scancode==SDL_SCANCODE_ESCAPE)
	{
		app->PopState();
	}
}

CGameMenu CGameMenu::inst;
