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

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <map>
#include <forward_list>

#include "types.h"
#include "keycodes.h"

namespace CastleKeep
{
	class Window;
	class Game;
	enum class EventType
	{
		MOUSE_BUTTON_PRESS,
		MOUSE_BUTTON_RELEASE,
		MOUSE_MOTION,
		MOUSE_WHEEL,
		KEY_PRESS,
		KEY_RELEASE,
		QUIT,
	};

	enum class MouseButton { LEFT,MIDDLE,RIGHT };

	struct MouseButtonState
	{
		bool left;
		bool middle;
		bool right;	
	};

	class Event
	{
	public:
		EventType type;	
	};

	class MouseButtonEvent : public Event
	{
	public:
		MouseButton button;
		Pos pos;
	};

	class MouseMotionEvent : public Event
	{
	public:
		Pos pos;
		Pos relative_pos;
		MouseButtonState button_state;
	};
	
	class MouseWheelEvent : public Event
	{
	public:
		int amount;
	};

	class KeyEvent : public Event
	{
	public:
		KeyCode key;
	};
	
	class MouseButtonEventListener
	{
	public:
		virtual void onMouseButtonPress(const MouseButtonEvent &event)=0;
		virtual void onMouseButtonRelease(const MouseButtonEvent &event)=0;
	};
	
	class MouseMotionEventListener
	{
	public:
		virtual void onMouseMove(const MouseMotionEvent &event)=0;	
	};

	class MouseWheelEventListener
	{
	public:
		virtual void onMouseScroll(const MouseWheelEvent &event)=0;	
	};

	class KeyEventListener
	{
	public:
		virtual void onKeyPress(const KeyEvent &event)=0;
		virtual void onKeyRelease(const KeyEvent &event)=0;
	};

	class QuitEventListener
	{
	public:
		virtual void onQuit()=0;
	};

	class InputManager
	{
	public:
		InputManager(Game *game, Window *window);
		virtual ~InputManager();

		void addMouseButtonEventListener(MouseButtonEventListener *listener);

		void addMouseMotionEventListener(MouseMotionEventListener *listener);

		void addMouseWheelEventListener(MouseWheelEventListener *listener);

		void addKeyEventListener(KeyEventListener *listener);

		void addQuitEventListener(QuitEventListener *listener);

		bool getKeyState(KeyCode key);

		bool getMouseButtonState(MouseButton button);

		const Pos& getMousePosition();

		const MouseButtonState& getMouseButtonState();

		virtual void processInput();		

	protected:

		void notifyMouseButtonEventListeners(const MouseButtonEvent &event);

		void notifyMouseMotionEventListeners(const MouseMotionEvent &event);

		void notifyMouseWheelEventListeners(const MouseWheelEvent &event);

		void notifyKeyEventListeners(const KeyEvent &event);

		bool notifyQuitEventListener();

		MouseButtonState _mouse_state;
		Pos _mouse_position;
		std::map<KeyCode,bool> _key_state;	
		std::forward_list<MouseButtonEventListener*> _mouse_button_listeners;
		std::forward_list<MouseMotionEventListener*> _mouse_motion_listeners;
		std::forward_list<MouseWheelEventListener*> _mouse_wheel_listeners;
		std::forward_list<KeyEventListener*>  _key_listeners;
		QuitEventListener *_quit_listener;
		Game *_game;
		Window *_window;
	};
}
#endif
