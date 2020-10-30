#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <GLFW/glfw3.h>

#include "display.h"
#include "camera.h"

typedef struct GameState {
    Display* display;

    Camera* camera;
} GameState;

GameState *initGameState();

#endif
