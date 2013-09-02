#pragma once

#include "timer.h"
#include "CApp.h"
#include "CEntity.h"
#include "CPlayer.h"
#include "CNpc.h"
#include <stdlib.h>
#include <vector>

using namespace std;

class CGame: public CApp
{
public:
    CGame();
    ~CGame();
private:

	CPlayer* player;

	bool pause;
	bool mouse_press;
	bool fail;
	int live_obj;
	int obj_count;
	int obj_incr;
	vector<CMoveObject*> npcs;

	void Restart();
	void NextLevel();

	void AddNPC(int count);

	void ObjectsCheck();

	virtual bool OnInit();

	virtual void OnUpdate(float time);

	virtual void OnRender();

	virtual void OnCleanUp();

	virtual void OnLButtonDown( int mX, int mY );

	virtual void OnLButtonUp( int mX, int mY );

	virtual void OnRButtonDown( int mX, int mY );

	virtual void OnKeyDown(SDL_Keysym key);

	virtual void OnMouseMove( int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle );

};