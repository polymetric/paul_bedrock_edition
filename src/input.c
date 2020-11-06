#include <math.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

#include "input.h"
#include "gameState.h"

// called whenever a key state is changed (pressed, released, etc.)
void keyCallback(GLFWwindow *window, const int key, const int scancode,
const int action, const int mods) {
	GameState *gameState;
	Camera *camera;

	gameState = (GameState*) glfwGetWindowUserPointer(window);
	camera = gameState->camera;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		// glfwSetWindowShouldClose(window, GLFW_TRUE);
		switch (gameState->mode) {
			case GAMEMODE_INGAME:
				gameState->mode = GAMEMODE_INGAME_PAUSED;
				break;
			case GAMEMODE_INGAME_PAUSED:
				gameState->mode = GAMEMODE_INGAME;
				break;
			default:
				break;
		}
	}
	if (key == GLFW_KEY_F && action == GLFW_PRESS) {
		float x, y, z, pitch, yaw;
		
		x = camera->x;
		y = camera->y;
		z = camera->z;
		pitch = camera->pitch;
		yaw = camera->yaw;
		printf("%12.3f %12.3f %12.3f %12.3f %12.3f\n", x, y, z, pitch, yaw);
	}
}

// temp global
// TODO move this to a state struct
int cursor_entered_this_tick = 0;

void cursor_enter_callback(GLFWwindow *window, int entered) {
	if (entered) { // cursor entered the window
		// cursor_entered_this_tick should get set to zero automatically after
		// it's used by tickInput
		cursor_entered_this_tick = 1;
	} else { // cursor left the window
		cursor_entered_this_tick = 0;
	}
}

// called unconditionally once every tick
// for keys that need to be held down
void tickInput(GameState *gameState, GLFWwindow *window) {
	Camera *camera;
	double mouse_x, mouse_y;

	camera = gameState->camera;

	// mouse movement
	if (gameState->mode == GAMEMODE_INGAME) {
		// if the cursor has just entered the frame this tick, don't process mouse
		// input, just set the position to zero.
		if (cursor_entered_this_tick) {
			printf("cursor entered\n");
			glfwSetCursorPos(window, 0, 0);
			cursor_entered_this_tick = 0;
		}
		if (!cursor_entered_this_tick && glfwGetWindowAttrib(window, GLFW_HOVERED)) {
			if (glfwRawMouseMotionSupported()) {
				glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
			}
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			glfwGetCursorPos(window, &mouse_x, &mouse_y);
			glfwSetCursorPos(window, 0, 0);
			camera->pitch += (mouse_y) * 0.15;
			camera->yaw += (mouse_x) * 0.15;
			if (camera->pitch > 90) {
				camera->pitch = 90;
			}
			if (camera->pitch < -90) {
				camera->pitch = -90;
			}
		}
	} else if (gameState->mode == GAMEMODE_INGAME_PAUSED) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	// keys
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		float yaw = camera->yaw - 90;
		camera->x += cos(yaw * M_PI / 180) * 0.1;
		camera->z += sin(yaw * M_PI / 180) * 0.1;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		float yaw = camera->yaw + 90;
		camera->x += cos(yaw * M_PI / 180) * 0.1;
		camera->z += sin(yaw * M_PI / 180) * 0.1;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		float yaw = camera->yaw - 180;
		camera->x += cos(yaw * M_PI / 180) * 0.1;
		camera->z += sin(yaw * M_PI / 180) * 0.1;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		float yaw = camera->yaw;
		camera->x += cos(yaw * M_PI / 180) * 0.1;
		camera->z += sin(yaw * M_PI / 180) * 0.1;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		camera->y += 0.1;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		camera->y -= 0.1;
	}
}
