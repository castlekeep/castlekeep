#Copyright (C) 2013 Real Numbers 
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

if(CMAKE_SOURCE_DIR EQUAL CMAKE_BINARY_DIR)
	message(FATAL_ERROR "Builds within the source directory are not allowed!")
endif()

cmake_minimum_required (VERSION 2.6)

project (castlekeep)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, 
		options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if(UNIX OR MINGW)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()

if(WIN32)
	
	set(WINDOWS_LIBRARY_PATH ${CMAKE_SOURCE_DIR}/windows)

	set(CMAKE_PREFIX_PATH ${WINDOWS_LIBRARY_PATH}/include)

	if(MSVC)
		
		set(CMAKE_WIN32_EXECUTABLE ON)	

		set(CMAKE_LIBRARY_PATH ${WINDOWS_LIBRARY_PATH}/lib/SDL2/msvc)

		set(SDL2_DLL ${WINDOWS_LIBRARY_PATH}/lib/SDL2/msvc/SDL2.dll
			CACHE STRING "SDL2 dll file")
	elseif(MINGW)

		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")

		set(CMAKE_LIBRARY_PATH ${WINDOWS_LIBRARY_PATH}/lib/SDL2/mingw)

		set(SDL2_DLL ${WINDOWS_LIBRARY_PATH}/lib/SDL2/mingw/SDL2.dll
			CACHE STRING "SDL2 dll file")
	endif()

	set(DLLS ${SDL2_DLL})
	set(PLATFORM_SPECIFIC_LIBRARIES "")

else()
	set(PLATFORM_SPECIFIC_LIBRARIES m)
endif()

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
set(LIBRARIES ${SDL2_LIBRARY} ${PLATFORM_SPECIFIC_LIBRARIES})

add_subdirectory(src)
