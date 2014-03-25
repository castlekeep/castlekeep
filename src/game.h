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

#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "window.h"
#include "renderer.h"
#include "input_manager.h"

namespace CastleKeep
{

	class Game 
	{
	public:	

		Game(WindowBackend backend, int width, int height, bool fullscreen);

		virtual ~Game();

		int run();

		void stop();

	protected:

		virtual void update();

		virtual void draw();

		bool _run;
		Map *_map;
		Window *_window;
		InputManager *_input_manager;
		Renderer *_renderer;
	};

}

#endif
