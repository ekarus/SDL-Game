#pragma once
#include "IEventHandler.h"
#include "CEntity.h"
#include <SDL.h>
#include <string>
#include "IGameState.h"
#include <vector>
#include "Singleton.h"
#include "CRender.h"
#include "CWindow.h"

class CApp: public IEventHandler, public Singleton<CApp>
{
public:

	virtual int onExecute();

	bool isRun(){return run;}

	int getScrWidth() const { return SCREEN_WIDTH; }
	int getScrHeight() const { return SCREEN_HEIGHT; }
	SDL_Renderer* getRender() const { return Renderer::Instance(); }
	SDL_Window* getWindow() const { return Window::Instance(); }

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
	friend class Singleton<CApp>;

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	IGameState* state;
	bool run;

	std::vector<IGameState*> states;

protected:
	CApp();
	virtual ~CApp();
	virtual void OnResize( int w,int h );

};

