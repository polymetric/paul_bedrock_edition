#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>

#include "gameState.h"

void keyCallback(GLFWwindow* window, const int key, const int scancode, const int action, const int mods);
void cursorCallback(GLFWwindow* window, double xpos, double ypos);
void tickInput(GameState *gameState, const GLFWwindow *window);

#endif
