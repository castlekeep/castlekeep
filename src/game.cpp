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


#include "game.h"
#include "sdl_window.h"
#include "sdl_input_manager.h"

namespace CastleKeep
{

	Game::Game(WindowBackend backend, int width, int height, bool fullscreen)
	{
		switch(backend) {
			case WindowBackend::SDL2:
				_window=new SDLWindow(width,height,fullscreen);
				_input_manager=new SDLInputManager(this,_window);
			break;
		}	
	}
	
	Game::~Game()
	{
	}

	int Game::run()
	{
		_run=true;
		while(_run) {
			_input_manager->processInput(); 
			update();
			draw();
		}
		return 0;
	}

	void Game::stop()
	{
		_run=false;	
	}

	void Game::update()
	{
	}

	void Game::draw()
	{
	}

}
