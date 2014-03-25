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
