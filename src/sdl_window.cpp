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

#include "sdl_window.h"


namespace CastleKeep
{
	SDLWindow::SDLWindow(int width, int height, bool fullscreen):Window(width,height,fullscreen)
	{
		Uint32 flags=0;

		SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
		
		if(fullscreen==true) {
			flags|=SDL_WINDOW_FULLSCREEN;
		}
		_window=SDL_CreateWindow("CastleKeep",SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,width,height,flags);
	}

	SDLWindow::~SDLWindow()
	{
	}

	void* SDLWindow::getNativeWindow()
	{
		return (void*)_window;	
	}


}
