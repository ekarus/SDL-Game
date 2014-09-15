#pragma once
#include "IEventHandler.h"
#include "CEntity.h"
#include <SDL2/SDL.h>
#include <string>
#include "IGameState.h"
#include <vector>
#include "Singleton.h"
#include "CRender.h"
#include "CWindow.h"

namespace Detail
{
	class CApp: public IEventHandler
	{
	public:

		CApp();
		virtual ~CApp();

		virtual int onExecute();

		bool isRun(){return is_run_;}

		int getScrWidth() const { return SCREEN_WIDTH; }
		int getScrHeight() const { return SCREEN_HEIGHT; }
		SDL_Renderer* getRender() const { return RendererSingleton::Instance()->Get(); }
		SDL_Window* getWindow() const { return WindowSingleton::Instance()->Get(); }

		void PushState(IGameState* state);
		void PopState();
		void ChangeState(IGameState* state);

		virtual void OnRender();
		virtual void OnExit();
		virtual bool OnInit();
		virtual void OnEvent(SDL_Event* event);
		virtual void OnUpdate(float time);
		virtual void OnCleanUp();

	private:
		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;

		IGameState* state;
		bool is_run_;

		std::vector<IGameState*> states;

	protected:
		virtual void OnResize( int w,int h );
	};
}

typedef Singleton<Detail::CApp> AppSingleton;
