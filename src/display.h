#ifndef DISPLAY_H
#define DISPLAY_H

#include <GLFW/glfw3.h>

typedef struct Display {
    GLFWwindow* window;
    int width;
    int height;
} Display;

Display *initDisplay();

#endif
