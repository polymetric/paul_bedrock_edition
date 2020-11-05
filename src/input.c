#include <math.h>
#include <GLFW/glfw3.h>

#include "input.h"
#include "gameState.h"

// called whenever a key state is changed (pressed, released, etc.)
void keyCallback(GLFWwindow *window, const int key, const int scancode,
const int action, const int mods) {
	GameState *gameState = (GameState*) glfwGetWindowUserPointer(window);
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

void cursorCallback(GLFWwindow* window, double xpos, double ypos) {
	GameState *gameState;
	Camera *camera;
	Display *display;
	
	gameState = (GameState*) glfwGetWindowUserPointer(window);
	camera = gameState->camera;
	display = gameState->display;
	if (glfwRawMouseMotionSupported()) {
		glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
	}
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	camera->pitch = ypos * 0.15;
	camera->yaw = xpos * 0.15;

	// printf("cursor pos: %12f %12f\n", xpos, ypos);
}

// called unconditionally once every tick
// for keys that need to be held down
void tickInput(GameState *gameState, const GLFWwindow *window) {
	Camera *camera;

	camera = gameState->camera;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		// camera->x += sin(camera->yaw / (M_PI * 2)) * 0.1;
		// camera->z += cos(camera->yaw / (M_PI * 2)) * 0.1;
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
		// camera->x += sin(camera->yaw / (M_PI * 2)) * 0.1;
		// camera->z += cos(camera->yaw / (M_PI * 2)) * 0.1;
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
