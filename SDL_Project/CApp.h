#pragma once
#include "CEvent.h"
#include "CEntity.h"
#include <SDL.h>
#include <string>

class CApp: public CEvent
{
public:
	CApp();
	virtual int onExecute();
	virtual bool OnInit();
	virtual void OnEvent(SDL_Event* event);
	virtual void OnUpdate(float time);
	virtual void OnRender();
	virtual void OnCleanUp();
	virtual void OnExit();

	virtual void logError(std::ostream& os,std::string msg);

	virtual void OnLButtonDown( int mX, int mY );
	virtual void OnRButtonDown( int mX, int mY );
	virtual void OnResize( int w,int h );
	virtual void OnKeyDown(SDL_Keysym key);
	virtual void OnMouseMove( int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle );

	bool isRun(){return run;}
	void Run(bool val){run=val;}

	int ScreenWidth() const { return SCREEN_WIDTH; }
	void ScreenWidth(int val) { SCREEN_WIDTH = val; }
	int ScreenHeight() const { return SCREEN_HEIGHT; }
	void ScreenHeight(int val) { SCREEN_HEIGHT = val; }

private:

	bool run;

protected:

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	SDL_Window* win;
	SDL_Renderer* render;

};