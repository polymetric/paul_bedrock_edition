#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <GLFW/glfw3.h>

#include "display.h"
#include "camera.h"
#include "ecs.h"

typedef enum GameMode {
    GAMEMODE_MAIN_MENU,
    GAMEMODE_INGAME,
    GAMEMODE_INGAME_PAUSED
} GameMode;

typedef struct GameState {
    Display *display;
    Camera *camera;
    Ecs *ecs;
    GameMode mode;
} GameState;

GameState *initGameState();

#endif
