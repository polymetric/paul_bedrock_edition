#include <stdlib.h>

#include "display.h"

#include "gameState.h"

// parameters
#define WINDOW_DEFAULT_WIDTH    800
#define WINDOW_DEFAULT_HEIGHT   600

GameState *initGameState() {
    return (GameState*) malloc(sizeof(GameState));
}
