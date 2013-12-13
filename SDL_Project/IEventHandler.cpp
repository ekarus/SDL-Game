#include "IEventHandler.h"

void IEventHandler::onEvent( EventPtr event )
{
	switch(event->type) {
	case SDL_WINDOWEVENT: {
		switch (event->window.event) {
		case SDL_WINDOWEVENT_RESIZED:
			OnResize(event->window.data1,event->window.data2);
			break;
		}
						  }

	case SDL_KEYDOWN: {
		OnKeyDown(event->key.keysym);
		break;
					  }

	case SDL_KEYUP: {
		OnKeyUp(event->key.keysym);
		break;
					}

	case SDL_MOUSEMOTION: {
		OnMouseMove(event->motion.x,event->motion.y,event->motion.xrel,event->motion.yrel,(event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
		break;
						  }

	case SDL_MOUSEBUTTONDOWN: {
		switch(event->button.button) {
		case SDL_BUTTON_LEFT: {
			OnLButtonDown(event->button.x,event->button.y);
			break;
							  }
		case SDL_BUTTON_RIGHT: {
			OnRButtonDown(event->button.x,event->button.y);
			break;
							   }
		case SDL_BUTTON_MIDDLE: {
			OnMButtonDown(event->button.x,event->button.y);
			break;
								}
		}
		break;
							  }

	case SDL_MOUSEBUTTONUP:    {
		switch(event->button.button) {
		case SDL_BUTTON_LEFT: {
			OnLButtonUp(event->button.x,event->button.y);
			break;
							  }
		case SDL_BUTTON_RIGHT: {
			OnRButtonUp(event->button.x,event->button.y);
			break;
							   }
		case SDL_BUTTON_MIDDLE: {
			OnMButtonUp(event->button.x,event->button.y);
			break;
								}
		}
		break;
							   }

	case SDL_QUIT: {
		OnExit();
		break;
				   }

	case SDL_SYSWMEVENT: {
		//Ignore
		break;
						 }

	default: {
		OnUser(event->user.type,event->user.code,event->user.data1,event->user.data2);
		break;
			 }
	}
}

void IEventHandler::OnInputFocus()
{
}

void IEventHandler::OnInputBlur()
{
}

void IEventHandler::OnKeyDown( SDL_Keysym key )
{
}

void IEventHandler::OnKeyUp( SDL_Keysym key )
{
}

void IEventHandler::OnMouseFocus()
{
}

void IEventHandler::OnMouseBlur()
{
}

void IEventHandler::OnMouseMove( int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle )
{
}

void IEventHandler::OnMouseWheel( bool Up, bool Down )
{
}

void IEventHandler::OnLButtonDown( int mX, int mY )
{
}

void IEventHandler::OnLButtonUp( int mX, int mY )
{
}

void IEventHandler::OnRButtonDown( int mX, int mY )
{
}

void IEventHandler::OnRButtonUp( int mX, int mY )
{
}

void IEventHandler::OnMButtonDown( int mX, int mY )
{
}

void IEventHandler::OnMButtonUp( int mX, int mY )
{
}

void IEventHandler::OnMinimize()
{
}

void IEventHandler::OnRestore()
{
}

void IEventHandler::OnResize( int w,int h )
{
}

void IEventHandler::OnExpose()
{
}

void IEventHandler::OnExit()
{
}

void IEventHandler::OnUser( Uint8 type, int code, void* data1, void* data2 )
{
}