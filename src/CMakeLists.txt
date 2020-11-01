set(
	SOURCES_LIST
	main.c
	gameState.c
	draw.c
	input.c
	display.c
	camera.c
)

if(WIN32 AND NOT CMAKE_BUILD_TYPE MATCHES Debug)
	add_executable(
		${PROJECT_NAME}
		WIN32
		${SOURCES_LIST}
	)
else()
	add_executable(
		${PROJECT_NAME}
		${SOURCES_LIST}
	)
endif()

if(WIN32)
	# for some reason we need to put .a on mingw windows because otherwise it
	# links the dll even if it doesn't exist!?!
	target_link_libraries(paul PRIVATE glew32.a)
	target_link_libraries(paul PRIVATE opengl32)
	target_link_libraries(paul PRIVATE glu32)
	target_link_libraries(paul PRIVATE glfw3)
else()
	target_link_libraries(paul PRIVATE GLEW)
	target_link_libraries(paul PRIVATE GLU)
	target_link_libraries(paul PRIVATE GL)
	target_link_libraries(paul PRIVATE glfw3)
endif()

if(UNIX AND NOT APPLE)

endif(UNIX AND NOT APPLE)

include_directories("${PROJECT_SOURCE_DIR}/include")
