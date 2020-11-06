set(
	SOURCES_LIST
	main.c
	gameState.c
	draw.c
	input.c
	display.c
	camera.c
	ecs.c
	entities.c
	systems.c
	components.c
	paul_math.c
)

configure_file(config.h.in config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

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
	target_link_libraries(${PROJECT_NAME} PRIVATE glew32.a)
	target_link_libraries(${PROJECT_NAME} PRIVATE opengl32)
	target_link_libraries(${PROJECT_NAME} PRIVATE glu32)
	target_link_libraries(${PROJECT_NAME} PRIVATE glfw3)
else()
	target_link_libraries(${PROJECT_NAME} PRIVATE GLEW)
	target_link_libraries(${PROJECT_NAME} PRIVATE GLU)
	target_link_libraries(${PROJECT_NAME} PRIVATE GL)
	target_link_libraries(${PROJECT_NAME} PRIVATE glfw3)
endif()

if(UNIX AND NOT APPLE)

endif(UNIX AND NOT APPLE)

include_directories("${PROJECT_SOURCE_DIR}/include")
