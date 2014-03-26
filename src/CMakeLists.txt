#Copyright (C) 2014 Castlekeep
#
#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.
#
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with this program.  If not, see <http://www.gnu.org/licenses/>.

set(SOURCES main.cpp game.cpp window.cpp sdl_window.cpp renderer.cpp input_manager.cpp sdl_input_manager.cpp castlekeep.cpp)

add_executable(castlekeep ${SOURCES})
target_link_libraries(castlekeep ${LIBRARIES} )

if(WIN32)
	if(MSVC_IDE)
		set(LIBRARY_DESTINATION 
			${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration))

		add_custom_command(TARGET castlekeep POST_BUILD 
			COMMAND ${CMAKE_COMMAND} -E copy 
			${DLLS} ${LIBRARY_DESTINATION})
	else()
		set(LIBRARY_DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
		add_custom_command(TARGET castlekeep POST_BUILD 
			COMMAND ${CMAKE_COMMAND} -E copy 
			${DLLS} ${LIBRARY_DESTINATION})
	endif()
endif()

if(UNIX)
	install(TARGETS castlekeep RUNTIME DESTINATION bin)
endif()
