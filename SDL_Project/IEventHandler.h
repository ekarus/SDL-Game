#pragma once
#include <SDL.h>

class IEventHandler
{
public:

	typedef SDL_Event Event;
	typedef Event* EventPtr;

	void onEvent(EventPtr event);

	virtual void OnInputFocus();

	virtual void OnInputBlur();

	virtual void OnKeyDown(SDL_Keysym key);

	virtual void OnKeyUp(SDL_Keysym key);

	virtual void OnMouseFocus();

	virtual void OnMouseBlur();

	virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);

	virtual void OnMouseWheel(bool Up, bool Down);

	virtual void OnLButtonDown(int mX, int mY);

	virtual void OnLButtonUp(int mX, int mY);

	virtual void OnRButtonDown(int mX, int mY);

	virtual void OnRButtonUp(int mX, int mY);

	virtual void OnMButtonDown(int mX, int mY);

	virtual void OnMButtonUp(int mX, int mY);

	virtual void OnMinimize();

	virtual void OnRestore();

	virtual void OnResize(int w,int h);

	virtual void OnExpose();

	virtual void OnExit();

	virtual void OnUser(Uint8 type, int code, void* data1, void* data2);
};