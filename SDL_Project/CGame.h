#pragma once

#include "timer.h"
#include "CApp.h"
#include "CEntity.h"
#include "CPlayer.h"
#include "CNpc.h"
#include "IGameState.h"
#include <stdlib.h>
#include <vector>
#include "Singleton.h"
#include <boost/signals2.hpp>

namespace Detail
{
	using namespace std;

	class CGame: public IGameState
	{
	public:

		CGame();

		virtual ~CGame();

		virtual bool OnInit();

		virtual void OnUpdate(float time);

		virtual void OnRender();

		virtual void OnCleanUp();

		virtual void OnPause();

		virtual void OnResume();

		virtual void Restart();

		virtual void NextLevel();

	private:
		virtual void AttachOnEvents();

		virtual void OnKeyDown(SDL_Keysym key);

		virtual void OnMouseMove( int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle );

		void AddNPC(int count);

		void ObjectsCheck();

		CApp* app;
		CPlayer* player;
		vector<CMoveObject*> npcs;

		bool fail;
		int live_obj;
		int obj_count;
		int obj_incr;

		//boost::signals2::connection keyboard_connection_;
		//boost::signals2::connection mouse_connection_;
	};
}

typedef Singleton<Detail::CGame> GameSingleton;