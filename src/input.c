#include <GLFW/glfw3.h>

#include "input.h"

// called whenever a key is pressed
// we use camelcase even though it's terrible,
// because all the GL stuff uses it :/
void keyCallback(
	GLFWwindow* window,
	int key,
	int scancode,
	int action,
	int mods
) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}