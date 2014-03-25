/*Copyright (C) 2013 Real Numbers

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "sdl_input_manager.h"
#include <SDL2/SDL.h>

#include "game.h"

namespace CastleKeep
{
	SDLInputManager::SDLInputManager(Game *game, Window *window):InputManager(game,window)
	{
	}

	SDLInputManager::~SDLInputManager()
	{

	}
	void SDLInputManager::processInput()
	{
		KeyEvent key_event;
		MouseButtonEvent button_event;
		MouseMotionEvent motion_event;
		MouseWheelEvent wheel_event;
		
		while(SDL_PollEvent(&_event)) {
			switch(_event.type) {
				case SDL_QUIT:
					if(!notifyQuitEventListener()) {
						_game->stop();
					}
					break;

				case SDL_KEYDOWN:
					key_event.type=EventType::KEY_PRESS;
					key_event.key=(KeyCode)_event.key.keysym.sym;
					notifyKeyEventListeners(key_event);
					break;

				case SDL_KEYUP:
					key_event.type=EventType::KEY_RELEASE;
					key_event.key=(KeyCode)_event.key.keysym.sym;
					notifyKeyEventListeners(key_event);
					break;

				case SDL_MOUSEBUTTONDOWN:
					button_event.type=EventType::MOUSE_BUTTON_PRESS;
					button_event.pos.x=_event.button.x;
					button_event.pos.y=_event.button.y;
					switch(_event.button.button) {
						case SDL_BUTTON_LEFT:
							button_event.button=MouseButton::LEFT;	
							break;
						case SDL_BUTTON_RIGHT:
							button_event.button=MouseButton::RIGHT;
							break;
						default:
							button_event.button=MouseButton::MIDDLE;
							break;
					}
					notifyMouseButtonEventListeners(button_event);
					break;

				case SDL_MOUSEBUTTONUP:
					button_event.type=EventType::MOUSE_BUTTON_RELEASE;
					button_event.pos.x=_event.button.x;
					button_event.pos.y=_event.button.y;
					switch(_event.button.button) {
						case SDL_BUTTON_LEFT:
							button_event.button=MouseButton::LEFT;	
							break;
						case SDL_BUTTON_RIGHT:
							button_event.button=MouseButton::RIGHT;
							break;
						default:
							button_event.button=MouseButton::MIDDLE;
							break;
					}
					notifyMouseButtonEventListeners(button_event);
					break;

				case SDL_MOUSEMOTION:
					motion_event.type=EventType::MOUSE_MOTION;
					motion_event.pos.x=_event.motion.x;
					motion_event.pos.y=_event.motion.y;
					motion_event.relative_pos.x=_event.motion.xrel;
					motion_event.relative_pos.y=_event.motion.yrel;

					if(_event.motion.state&SDL_BUTTON_LMASK) {
						motion_event.button_state.left=true;
					} else {
						motion_event.button_state.left=false;
					}

					if(_event.motion.state&SDL_BUTTON_MMASK) {
						motion_event.button_state.middle=true;
					} else {
						motion_event.button_state.middle=false;
					}

					if(_event.motion.state&SDL_BUTTON_RMASK) {
						motion_event.button_state.right=true;
					} else {
						motion_event.button_state.right=false;
					}
					notifyMouseMotionEventListeners(motion_event);
					break;

				case SDL_MOUSEWHEEL:
					wheel_event.type=EventType::MOUSE_WHEEL;
					wheel_event.amount=_event.wheel.y;
					notifyMouseWheelEventListeners(wheel_event);
					break;
			}
		}

	}
}
