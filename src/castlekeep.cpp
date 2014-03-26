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

#include "castlekeep.h"
#include "window.h"

namespace CastleKeep
{

	CastleKeep::CastleKeep():Game(WindowBackend::SDL2,800,600,false)
	{
		_key_handler=new KeyHandler();
		_input_manager->addKeyEventListener(_key_handler);		
	}
	CastleKeep::~CastleKeep()
	{
	}

}
