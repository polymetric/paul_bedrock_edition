#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>

#include "gameState.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

void tickInput(GameState *gameState, GLFWwindow *window);

#endif
