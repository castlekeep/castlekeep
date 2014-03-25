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

#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

#include <SDL2/SDL.h>

#include "window.h"

namespace CastleKeep
{
	class SDLWindow : public Window 
	{
	public:

		SDLWindow(int width, int height, bool fullscreen);

		virtual ~SDLWindow();

		void* getNativeWindow();

	protected:
		SDL_Event _event;
		SDL_Window *_window;
	};

}

#endif
