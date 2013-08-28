#pragma once
#include "CEvent.h"
#include <SDL.h>
#include <string>

class CApp: public CEvent
{
public:
	CApp();
	int onExecute();
	bool OnInit();
	void OnEvent(SDL_Event* event);
	void OnUpdate();
	void OnRender();
	void OnCleanUp();
	void logError(std::ostream& os,std::string msg);

	void OnExit();
	void OnKeyDown(SDL_Keysym key);
	void OnMouseMove( int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle );

	bool isRun(){return run;}
	void Run(bool val){run=val;}

	virtual void OnLButtonDown( int mX, int mY );

	virtual void OnRButtonDown( int mX, int mY );

	virtual void OnResize( int w,int h );

private:
	bool run;
	int SCREEEN_WIDTH;
	int SCREEN_HEIGHT;
	SDL_Window* win;
	SDL_Renderer* render;
	SDL_Texture* tex;

	int x,y;
};