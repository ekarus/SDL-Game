#pragma once
#include "IEventHandler.h"
#include "CEntity.h"
#include <SDL.h>
#include <string>
#include "IGameState.h"
#include <vector>

class CApp: public IEventHandler
{
public:

	static CApp* getInstance(){return &inst;}
	virtual ~CApp();

	virtual int onExecute();
	
	bool isRun(){return run;}
	void Run(bool val){run=val;}

	int getScrWidth() const { return SCREEN_WIDTH; }
	int getScrHeight() const { return SCREEN_HEIGHT; }
	SDL_Renderer* getRender() const { return render; }
	SDL_Window* getWindow() const { return win; }

	void PushState(IGameState* state);
	void PopState();
	void ChangeState(IGameState* state);

	virtual void OnRender();
	virtual void OnExit();
	virtual bool OnInit();
	virtual void OnEvent(SDL_Event* event);
	virtual void OnUpdate(float time);
	virtual void OnCleanUp();

	void logError(std::ostream& os,std::string msg);

private:

	IGameState* state;
	bool run;
	static CApp inst;
	CApp();

	std::vector<IGameState*> states;

protected:

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	SDL_Window* win;
	SDL_Renderer* render;

	
	
	


	

	virtual void OnResize( int w,int h );

};