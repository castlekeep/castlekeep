# - Locate SDL2 library
# This module defines
#  SDL2_LIBRARY, the name of the library to link against
#  SDL2_FOUND, if false, do not try to link to SDL
#  SDL2_INCLUDE_DIR, where to find SDL.h
#  SDL2_VERSION_STRING, human-readable string containing the version of SDL
#
# This module responds to the the flag:
#  SDL2_BUILDING_LIBRARY
#    If this is defined, then no SDL_main will be linked in because
#    only applications need main().
#    Otherwise, it is assumed you are building an application and this
#    module will attempt to locate and set the the proper link flags
#    as part of the returned SDL2_LIBRARY variable.
#
# Don't forget to include SDLmain.h and SDLmain.m your project for the
# OS X framework based version. (Other versions link to -lSDLmain which
# this module will try to find on your behalf.) Also for OS X, this
# module will automatically add the -framework Cocoa on your behalf.
#
#
# Additional Note: If you see an empty SDL2_LIBRARY_TEMP in your configuration
# and no SDL_LIBRARY, it means CMake did not find your SDL2 library
# (SDL2.dll, libsdl2.so, SDL2.framework, etc).
# Set SDL_LIBRARY_TEMP to point to your SDL library, and configure again.
# Similarly, if you see an empty SDL2MAIN_LIBRARY, you should set this value
# as appropriate. These values are used to generate the final SDL2_LIBRARY
# variable, but when these values are unset, SDL2_LIBRARY does not get created.
#
#
# $SDL2DIR is an environment variable that would
# correspond to the ./configure --prefix=$SDL2DIR
# used in building SDL.
# l.e.galup  9-20-02
#
# Modified by Eric Wing.
# Added code to assist with automated building by using environmental variables
# and providing a more controlled/consistent search behavior.
# Added new modifications to recognize OS X frameworks and
# additional Unix paths (FreeBSD, etc).
# Also corrected the header search path to follow "proper" SDL guidelines.
# Added a search for SDLmain which is needed by some platforms.
# Added a search for threads which is needed by some platforms.
# Added needed compile switches for MinGW.
#
# On OSX, this will prefer the Framework version (if found) over others.
# People will have to manually change the cache values of
# SDL_LIBRARY to override this selection or set the CMake environment
# CMAKE_INCLUDE_PATH to modify the search paths.

#=============================================================================
# Copyright 2003-2009 Kitware, Inc.
# Copyright 2012 Benjamin Eikel
# Copyright 2013 David Leiter

# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)


set(SDL2_SEARCH_PATH
	~/Library/Frameworks
	/Library/Frameworks
	/usr/local
	/usr
	/sw # Fink
	/opt/local # DarwinPorts
	/opt/csw # Blastwave
	/opt
)

find_path(SDL2_INCLUDE_DIR SDL2/SDL.h
	HINTS
		ENV SDL2DIR
	PATH_SUFFIXES include
	PATH ${SDL2_SEARCH_PATH}
)

find_library(SDL2_LIBRARY_TEMP
	NAMES SDL2
	HINTS
		ENV SDL2DIR
	PATH_SUFFIXES lib
	PATH ${SDL2_SEARCH_PATH}
)

if(NOT SDL2_BUILDING_LIBRARY)
	if(WIN32)
		find_library(SDL2MAIN_LIBRARY
				NAMES SDL2main
				HINTS
					ENV SDL2DIR
				PATH_SUFFIXES lib
				PATH ${SDL2_SEARCH_PATH}
		)


	endif()
endif()

# SDL2 may require threads on your system.
# The Apple build may not need an explicit flag because one of the
# frameworks may already provide it.
# But for non-OSX systems, I will use the CMake Threads package.
if(NOT APPLE)
	find_package(Threads)
endif()

# MinGW needs an additional library, mwindows
# It's total link flags should look like -lmingw32 -lSDL2main -lSDL2 -lmwindows
# (Actually on second look, I think it only needs one of the m* libraries.)
if(MINGW)
	set(MINGW32_LIBRARY mingw32)
endif()

# For OS X, SDL uses Cocoa as a backend so it must link to Cocoa.
# CMake doesn't display the -framework Cocoa string in the UI even
# though it actually is there if I modify a pre-used variable.
# I think it has something to do with the CACHE STRING.
# So I use a temporary variable until the end so I can set the
# "real" variable in one-shot.
if(APPLE)
	set(SDL2_LIBRARY_TEMP ${SDL2_LIBRARY_TEMP} "-framework Cocoa")
endif()

# For threads, as mentioned Apple doesn't need this.
# In fact, there seems to be a problem if I used the Threads package
# and try using this line, so I'm just skipping it entirely for OS X.
if(NOT APPLE)
   set(SDL2_LIBRARY_TEMP ${SDL2_LIBRARY_TEMP} ${CMAKE_THREAD_LIBS_INIT})
endif()

if(WIN32)
	set(SDL2_LIBRARY_TEMP ${SDL2MAIN_LIBRARY} ${SDL2_LIBRARY_TEMP})
endif()

# For MinGW library
if(MINGW)
	set(SDL2_LIBRARY_TEMP ${MINGW32_LIBRARY} ${SDL2_LIBRARY_TEMP})
endif()

# Set the final string here so the GUI reflects the final state.
set(SDL2_LIBRARY ${SDL2_LIBRARY_TEMP} CACHE STRING "Where the SDL2 Library can be found")
# Set the temp variable to INTERNAL so it is not seen in the CMake GUI
set(SDL2_LIBRARY_TEMP "${SDL_LIBRARY_TEMP}" CACHE INTERNAL "")
set(SDL2MAIN_LIBRARY "${SDLMAIN_LIBRARY}" CACHE INTERNAL "")

include(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2 REQUIRED_VARS SDL2_LIBRARY SDL2_INCLUDE_DIR
				VERSION_VAR SDL2_VERSION_STRING)
