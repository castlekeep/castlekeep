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

#ifndef MAP_CELL_H
#define MAP_CELL_H

namespace CastleKeep
{
	enum MapCellType 
	{
		GRASS,
		DIRT,
		DESERT,
		RIVER,
		LAKE,
		SEA,
		WALL
	};
	
	struct MapCell
	{
		MapCellType type;
		bool walkable;
		int tile;
		int height;
		int building;
		int building_part;
	};
}

#endif