#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>

#include "gameState.h"

void keyCallback(GLFWwindow* window, const int key, const int scancode, const int action, const int mods);
void cursor_enter_callback(GLFWwindow *window, int entered);
void tickInput(GameState *gameState, GLFWwindow *window);

#endif
