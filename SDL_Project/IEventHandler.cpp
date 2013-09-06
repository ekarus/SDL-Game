#include "IEventHandler.h"

void IEventHandler::onEvent( SDL_Event* Event )
{
	switch(Event->type) {
	case SDL_WINDOWEVENT: {
		switch (Event->window.event) {

		case SDL_WINDOWEVENT_RESIZED:
			OnResize(Event->window.data1,Event->window.data2);
			break;
		}
						  }


	case SDL_KEYDOWN: {
		OnKeyDown(Event->key.keysym);
		break;
					  }

	case SDL_KEYUP: {
		OnKeyUp(Event->key.keysym);
		break;
					}

	case SDL_MOUSEMOTION: {
		OnMouseMove(Event->motion.x,Event->motion.y,Event->motion.xrel,Event->motion.yrel,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
		break;
						  }

	case SDL_MOUSEBUTTONDOWN: {
		switch(Event->button.button) {
		case SDL_BUTTON_LEFT: {
			OnLButtonDown(Event->button.x,Event->button.y);
			break;
							  }
		case SDL_BUTTON_RIGHT: {
			OnRButtonDown(Event->button.x,Event->button.y);
			break;
							   }
		case SDL_BUTTON_MIDDLE: {
			OnMButtonDown(Event->button.x,Event->button.y);
			break;
								}
		}
		break;
							  }

	case SDL_MOUSEBUTTONUP:    {
		switch(Event->button.button) {
		case SDL_BUTTON_LEFT: {
			OnLButtonUp(Event->button.x,Event->button.y);
			break;
							  }
		case SDL_BUTTON_RIGHT: {
			OnRButtonUp(Event->button.x,Event->button.y);
			break;
							   }
		case SDL_BUTTON_MIDDLE: {
			OnMButtonUp(Event->button.x,Event->button.y);
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
		OnUser(Event->user.type,Event->user.code,Event->user.data1,Event->user.data2);
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
