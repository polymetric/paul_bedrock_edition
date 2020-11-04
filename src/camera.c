#include <stdlib.h>

#include "camera.h"

Camera *initCamera(float x, float y, float z) {
    Camera *camera = (Camera*) malloc(sizeof(Camera));
    camera->x = x;
    camera->y = y;
    camera->z = z;
    camera->pitch = 0.0f;
    camera->yaw = 0.0f;
    return camera;
}
