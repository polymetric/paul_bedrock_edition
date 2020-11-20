#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <config.h>
#include "gameState.h"
#include "input.h"
#include "draw.h"
#include "camera.h"
#include "ecs.h"
#include "systems.h"
#include "entities.h"

int main(int argc, char **argv) {
	GameState *gameState; // root data structure, holds pretty much everything in the game
	GLFWwindow *window; // just an alias to a window struct ptr held by the gamestate
	Camera *camera; // alias to gameState->camera
	GLenum glError; // holds the last error 

	printf("%s v%s\n", PROJECT_NAME, PROJECT_VER);

	// TODO currently we have some struct initializers as functions that return
	// a pointer to the struct, and some that return void and take a **pointer
	// which is modified. the former is proobably better but either way
	// they should be unified
	gameState = initGameState();
    gameState->display = initDisplay();
	gameState->mode = GAMEMODE_INGAME_PAUSED;

	// makes `window` a shorthand for `gameState->display->window`
	window = gameState->display->window; 

	// initialize the key callback and give the callback a pointer to the game
	// state
	glfwSetKeyCallback(window, &keyCallback);
	glfwSetCursorEnterCallback(window, &cursor_enter_callback);
	glfwSetWindowUserPointer(window, gameState);

	// TEMPORARY camera
	gameState->camera = initCamera(0.0f, 0.0f, 0.0f);
	camera = gameState->camera;

	ecs_init(&gameState->ecs);

	// add test shit
	// int cube1 = create_spinsquare(gameState->ecs);
	// ecs_get_world_pos(gameState->ecs, cube1)->x = 0;
	// ecs_get_world_pos(gameState->ecs, cube1)->y = 0;
	// ecs_get_world_pos(gameState->ecs, cube1)->z = -2;
	// int cube2 = create_spinsquare(gameState->ecs);
	// ecs_get_world_pos(gameState->ecs, cube2)->x = 5;
	// ecs_get_world_pos(gameState->ecs, cube2)->y = 2;
	// ecs_get_world_pos(gameState->ecs, cube2)->z = -8;

	int i;
	float x, y, z;
	for (i = 0; i < 5; i++) {
		int eid;
		WorldPos *pos;
		WorldPitchYaw *rot;

		eid = create_spinsquare(gameState->ecs);
		pos = ecs_get_world_pos(gameState->ecs, eid);
		rot = ecs_get_world_pitch_yaw(gameState->ecs, eid);

		// pos->x = (float) i / 10;
		// pos->z = sin((float) i / 15) * 5;
		pos->x = i * 2;
		pos->z = i * 2;

		x = pos->x;
		y = pos->y;
		z = pos->z;
		printf("%12.3f %12.3f %12.3f\n", x, y, z);
	}
	
	// main loop
	while (!glfwWindowShouldClose(window)) {
		// TICK
		glfwPollEvents(); // this is where most of the input callbacks are
		                  // actually called from
		tickInput(gameState, window);
		
		if (gameState->mode == GAMEMODE_INGAME) {
			sys_world_pos_update(gameState->ecs);
			sys_world_pitch_yaw_update(gameState->ecs);
		}

		// DRAW
		display_update_size(gameState->display);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		setupCameraMatrices(camera, gameState->display);

		// temp lighting test
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_LIGHT0);
		float temp1[] = { .5, 1, .25, 0 };
		glLightfv(GL_LIGHT0, GL_POSITION, temp1);

		glEnable(GL_MULTISAMPLE);
		sys_render_cube_update(gameState->ecs);

		// gui render
		// glDisable(GL_DEPTH_TEST);
		// glDisable(GL_LIGHTING);
		// glMatrixMode(GL_PROJECTION);
		// glLoadIdentity();
		// int width = gameState->display->width;
		// int height = gameState->display->height;
		// glOrtho(0, width, height, 0, 1, -1);

		// glMatrixMode(GL_MODELVIEW);

		// glLoadIdentity();
		// glTranslatef(100.0f, 100.0f, 0.0f);
		// drawQuad(100);

		glfwSwapBuffers(window);

		glError = glGetError();
		if (glError != GL_NO_ERROR) {
			fprintf(stderr, "gl error: %s\n", gluErrorString(glError));
		}
	}

	return 0;
}
