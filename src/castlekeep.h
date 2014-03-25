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

#ifndef CASTLE_KEEP_H
#define CASTLE_KEEP_H

#include <stdio.h>

#include "game.h"
#include "input_manager.h"

namespace CastleKeep
{
	class KeyHandler : public KeyEventListener
	{
	public:
		void onKeyPress(const KeyEvent &event)
		{
			switch(event.key) {
				case KeyCode::ARROW_UP:
					printf("Up\n");
					break;
				case KeyCode::ARROW_DOWN:
					printf("Down\n");
					break;
				case KeyCode::ARROW_LEFT:
					printf("Left\n");
					break;
				case KeyCode::ARROW_RIGHT:
					printf("Right\n");
					break;
				default:
					break;
			}
		}
		void onKeyRelease(const KeyEvent &event)
		{
		}
	};

	class CastleKeep : public Game 
	{
	public:	

		CastleKeep();

		virtual ~CastleKeep();

	protected:
		KeyHandler *_key_handler;
	};

}

#endif
