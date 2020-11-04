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

// called every tick
// for keys that need to be held down
void tickInput(GameState *gameState, const GLFWwindow *window) {
	
}
