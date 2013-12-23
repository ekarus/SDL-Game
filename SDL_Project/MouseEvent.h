#pragma once

#include "Singleton.h"
#include <boost/signals2.hpp>
#include <SDL.h>
#include "EventManager.h"

namespace Events
{
	namespace Detail
	{
		class MouseEvent
		{
		public:
			typedef boost::signals2::signal<void(int mX, int mY)> LeftButtonDownSignal;
			typedef boost::signals2::signal<void(int mX, int mY)> LeftButtonUpSignal;
			typedef boost::signals2::signal<void(int mX, int mY)> RightButtonDownSignal;
			typedef boost::signals2::signal<void(int mX, int mY)> RightButtonUpSignal;
			typedef boost::signals2::signal<void(int mX, int mY)> MiddleButtonDownSignal;
			typedef boost::signals2::signal<void(int mX, int mY)> MiddleButtonUpSignal;
			typedef boost::signals2::signal<void(void)> WheelUpSignal;
			typedef boost::signals2::signal<void(void)> WheelDownSignal;
			typedef boost::signals2::signal<void(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle)> MouseMoveSignal;

			MouseEvent()
			{
				AttachEvents();
			}

			boost::signals2::connection AttachOnLeftButtonDown(const LeftButtonDownSignal::slot_type& slot)
			{
				return left_key_down_signal_.connect(slot);
			}

			boost::signals2::connection AttachOnLeftButtonUp(const LeftButtonUpSignal::slot_type& slot)
			{
				return left_key_up_signal_.connect(slot);
			}

			boost::signals2::connection AttachOnMiddleButtonDown(const MiddleButtonDownSignal::slot_type& slot)
			{
				return middle_key_down_signal_.connect(slot);
			}

			boost::signals2::connection AttachOnMiddleButtonUp(const MiddleButtonUpSignal::slot_type& slot)
			{
				return middle_key_up_signal_.connect(slot);
			}

			boost::signals2::connection AttachOnRightButtonDown(const RightButtonDownSignal::slot_type& slot)
			{
				return right_key_down_signal_.connect(slot);
			}

			boost::signals2::connection AttachOnRightButtonUp(const RightButtonUpSignal::slot_type& slot)
			{
				return right_key_up_signal_.connect(slot);
			}

			boost::signals2::connection AttachOnWheelUp(const WheelUpSignal::slot_type& slot)
			{
				return wheel_up_signal_.connect(slot);
			}

			boost::signals2::connection AttachOnWheelDown(const WheelDownSignal::slot_type& slot)
			{
				return wheel_up_signal_.connect(slot);
			}

			boost::signals2::connection AttachOnMouseMove(const MouseMoveSignal::slot_type& slot)
			{
				return mouse_move_signal_.connect(slot);
			}

		private:
			void AttachEvents()
			{
				EventManager::Instance()->AttachOnEvent([=](const Event& event)
				{
					OnEvent(event);
				});
			}

			void OnEvent(const Event& event)
			{
				switch(event.type)
				{
				case SDL_MOUSEMOTION:
					{
						mouse_move_signal_(event.motion.x,event.motion.y,event.motion.xrel,event.motion.yrel,(event.motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(event.motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(event.motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
						break;
					}

				case SDL_MOUSEBUTTONDOWN:
					{
						switch(event.button.button)
						{
						case SDL_BUTTON_LEFT:
							{
								left_key_down_signal_(event.button.x,event.button.y);
								break;
							}
						case SDL_BUTTON_RIGHT:
							{
								right_key_down_signal_(event.button.x,event.button.y);
								break;
							}
						case SDL_BUTTON_MIDDLE:
							{
								middle_key_down_signal_(event.button.x,event.button.y);
								break;
							}
						}
						break;
					}

				case SDL_MOUSEBUTTONUP:
					{
						switch(event.button.button)
						{
						case SDL_BUTTON_LEFT:
							{
								left_key_up_signal_(event.button.x,event.button.y);
								break;
							}
						case SDL_BUTTON_RIGHT:
							{
								right_key_up_signal_(event.button.x,event.button.y);
								break;
							}
						case SDL_BUTTON_MIDDLE:
							{
								middle_key_up_signal_(event.button.x,event.button.y);
								break;
							}
						}
						break;
					}
				}
			}

			LeftButtonDownSignal left_key_down_signal_;
			LeftButtonUpSignal left_key_up_signal_;
			RightButtonDownSignal right_key_down_signal_;
			RightButtonUpSignal right_key_up_signal_;
			MiddleButtonDownSignal middle_key_down_signal_;
			MiddleButtonUpSignal middle_key_up_signal_;
			WheelUpSignal wheel_up_signal_;
			WheelDownSignal wheel_down_signal_;
			MouseMoveSignal mouse_move_signal_;
		};
	}

	typedef Singleton<Detail::MouseEvent> Mouse;
}