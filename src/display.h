#ifndef DISPLAY_H
#define DISPLAY_H

#include <GLFW/glfw3.h>

#define WINDOW_DEFAULT_WIDTH    1600
#define WINDOW_DEFAULT_HEIGHT   864

typedef struct Display {
    GLFWwindow* window;
    int width;
    int height;
} Display;

Display *initDisplay();
void display_update_size(Display *display);

#endif
