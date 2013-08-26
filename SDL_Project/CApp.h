#pragma once
#include <SDL.h>
#include <string>

class CApp
{
public:
	CApp();
	int onExecute();
	bool onInit();
	void onEvent(SDL_Event& event);
	void onUpdate();
	void onRender();
	void onCleanUp();
	void logError(std::ostream& os,std::string msg);

	bool isRun(){return run;}
	void Run(bool val){run=val;}
private:
	bool run;
	int SCREEEN_WIDTH;
	int SCREEN_HEIGHT;
	SDL_Window* win;
	SDL_Renderer* render;
	SDL_Texture* tex;
};