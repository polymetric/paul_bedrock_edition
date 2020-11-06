#include <stdlib.h>

#include "display.h"

#include "gameState.h"

GameState *initGameState() {
    return (GameState*) malloc(sizeof(GameState));
}
