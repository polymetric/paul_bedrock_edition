#include <GLFW/glfw3.h>

#include "input.h"
#include "gameState.h"

// called ONCE whenever a key is pressed
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	GameState *gameState = (GameState*) glfwGetWindowUserPointer(window);

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

// called every tick
// for keys that need to be held down
void tickInput(GameState *gameState, GLFWwindow *window) {
	
}
