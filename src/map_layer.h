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

#ifndef MAP_LAYER_H
#define MAP_LAYER_H

#include "map_cell.h"

namespace CastleKeep 
{
	class Map;

	class MapLayer
	{
	public:
		MapLayer(Map* _map,const char* name);
		virtual ~MapLayer();
	private:
		const char* _layer_name;
		MapCell *_cells;
		Map *_map;
	};

}

#endif
