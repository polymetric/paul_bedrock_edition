set(
	SOURCES_LIST
	main.c
	gameState.c
	draw.c
	input.c
	display.c
	camera.c
)

if(MINGW AND NOT CMAKE_BUILD_TYPE MATCHES Debug)
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
