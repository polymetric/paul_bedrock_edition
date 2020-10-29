set(
	SOURCES_LIST
	main.c
	input/keyHandler.c
)

if(MINGW)
	add_executable(
		paul
		WIN32
		${SOURCES_LIST}
	)
else()
	add_executable(
		paul
		${SOURCES_LIST}
	)
endif()

if(MINGW)
	target_link_libraries(paul PRIVATE libglew32)
	target_link_libraries(paul PRIVATE opengl32)
	target_link_libraries(paul PRIVATE glu32)
	target_link_libraries(paul PRIVATE glfw3)
endif(MINGW)

if(UNIX AND NOT APPLE)

endif(UNIX AND NOT APPLE)

include_directories("${PROJECT_SOURCE_DIR}/include")
