#include <stdlib.h>
#include <stdio.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "gameState.h"
#include "input.h"
#include "draw.h"
#include "camera.h"
#include "ecs.h"
#include "systems.h"
#include "entities.h"

#define WINDOW_DEFAULT_WIDTH    800
#define WINDOW_DEFAULT_HEIGHT   600

int main(int argc, char **argv) {
	GameState *gameState; // root data structure, holds pretty much everything in the game
	GLFWwindow *window; // just an alias to a window struct ptr held by the gamestate
	Camera *camera; // alias to gameState->camera
	GLenum glError; // holds the last error 

	// TODO currently we have some struct initializers as functions that return
	// a pointer to the struct, and some that return void and take a **pointer
	// which is modified. the former is proobably better but either way
	// they should be unified
	gameState = initGameState();
    gameState->display = initDisplay();

	// initialize the key callback and give the callback a pointer to the game
	// state
	glfwSetKeyCallback(gameState->display->window, &keyCallback);
	glfwSetWindowUserPointer(gameState->display->window, gameState);

	// makes `window` a shorthand for `gameState->display->window`
	window = gameState->display->window; 

	// TEMPORARY camera
	gameState->camera = initCamera(0.0f, 0.0f, 0.0f);
	camera = gameState->camera;

	ecs_init(&gameState->ecs);

	// add test shit
	int cube1 = create_spinsquare(gameState->ecs);
	ecs_get_world_pos(gameState->ecs, cube1)->x = 0;
	ecs_get_world_pos(gameState->ecs, cube1)->y = 0;
	ecs_get_world_pos(gameState->ecs, cube1)->z = -2;
	int cube2 = create_spinsquare(gameState->ecs);
	ecs_get_world_pos(gameState->ecs, cube2)->x = 5;
	ecs_get_world_pos(gameState->ecs, cube2)->y = 2;
	ecs_get_world_pos(gameState->ecs, cube2)->z = -8;
	
	// main loop
	while (!glfwWindowShouldClose(window)) {
		// TICK
		tickInput(gameState, window);
		sys_world_pos_update(gameState->ecs);
		sys_world_pitch_yaw_update(gameState->ecs);

		// DRAW
		display_update_size(gameState->display);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		// temp lighting test
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_COLOR_MATERIAL);

		float temp[] = { 5, 5, 5 };
		glLightfv(GL_LIGHT0, GL_POSITION, temp);

		setupCameraMatrices(camera, gameState->display);
		sys_renderable_update(gameState->ecs);

		// gui render
		// glMatrixMode(GL_PROJECTION);
		// glLoadIdentity();
		// glOrtho(0, width, height, 0, 1, -1);

		// glMatrixMode(GL_MODELVIEW);

		// glLoadIdentity();
		// glTranslatef(100.0f, 100.0f, 0.0f);
		// drawQuad(100);

		// check/call events and swap buffers at the end of the frame
		glfwPollEvents();
		glfwSwapBuffers(window);

		glError = glGetError();
		if (glError != GL_NO_ERROR) {
			fprintf(stderr, "gl error: %s\n", gluErrorString(glError));
		}
	}

	return 0;
}
