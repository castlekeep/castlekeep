/**
 *	@section LICENSE
 *
 *	Copyright (C) 2014 Castlekeep
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *	@section DESCRIPTION
 *
 */



#include "input_manager.h"

namespace CastleKeep
{
	InputManager::InputManager(Game *game, Window *window): _game(game), _window(window) 
	{
			_mouse_state.left=false;
			_mouse_state.middle=false;
			_mouse_state.right=false; 
			_mouse_position.x=0;
			_mouse_position.y=0;
			_quit_listener=NULL;
	}

	InputManager::~InputManager()
	{

	}		

	void InputManager::addMouseButtonEventListener(MouseButtonEventListener *listener)
	{
		_mouse_button_listeners.push_front(listener);
	}

	void InputManager::addMouseMotionEventListener(MouseMotionEventListener *listener)
	{
		_mouse_motion_listeners.push_front(listener);
	}

	void InputManager::addMouseWheelEventListener(MouseWheelEventListener *listener)
	{
		_mouse_wheel_listeners.push_front(listener);	
	}

	void InputManager::addKeyEventListener(KeyEventListener *listener)
	{
		_key_listeners.push_front(listener);
	}

	void InputManager::addQuitEventListener(QuitEventListener *listener)
	{
		_quit_listener=listener;
	}

	bool InputManager::getKeyState(KeyCode key)
	{
		return true;
	}

	bool InputManager::getMouseButtonState(MouseButton button)
	{
		switch(button) {
			case MouseButton::LEFT:
				return _mouse_state.left;
			case MouseButton::RIGHT:
				return _mouse_state.right;
			default:
				return _mouse_state.middle;
		}
	}

	const MouseButtonState& InputManager::getMouseButtonState()
	{
		return _mouse_state;
	}

	const Pos& InputManager::getMousePosition()
	{
		return _mouse_position;
	}

	void InputManager::processInput()
	{

	}
	
	void InputManager::notifyMouseButtonEventListeners(const MouseButtonEvent &event)
	{
		if(_mouse_button_listeners.empty()) {
			return;
		}

		if(event.type==EventType::MOUSE_BUTTON_PRESS) {
			for(auto i=_mouse_button_listeners.begin();i!=_mouse_button_listeners.end();i++) {
				(*i)->onMouseButtonPress(event);
			}
		} else {
			for(auto i=_mouse_button_listeners.begin();i!=_mouse_button_listeners.end();i++) {
				(*i)->onMouseButtonRelease(event);
			}
		}
	}

	void InputManager::notifyMouseMotionEventListeners(const MouseMotionEvent &event)
	{
		if(_mouse_motion_listeners.empty()) {
			return;
		}

		for(auto i=_mouse_motion_listeners.begin();i!=_mouse_motion_listeners.end();i++) {
			(*i)->onMouseMove(event);
		}
	}

	void InputManager::notifyMouseWheelEventListeners(const MouseWheelEvent &event)
	{
		if(_mouse_wheel_listeners.empty()) {
			return;
		}

		for(auto i=_mouse_wheel_listeners.begin();i!=_mouse_wheel_listeners.end();i++) {
			(*i)->onMouseScroll(event);
		}
	}

	void InputManager::notifyKeyEventListeners(const KeyEvent &event)
	{
		if(_key_listeners.empty()) {
			return;
		}

		if(event.type==EventType::KEY_PRESS) {
			for(auto i=_key_listeners.begin();i!=_key_listeners.end();i++) {
				(*i)->onKeyPress(event);
			}
		} else {
			for(auto i=_key_listeners.begin();i!=_key_listeners.end();i++) {
				(*i)->onKeyRelease(event);
			}
		}
	}

	bool InputManager::notifyQuitEventListener()
	{
		if(_quit_listener==NULL) {
			return false;
		}
		_quit_listener->onQuit();
		return true;
	}	

}
