#ifndef CAMERA_H
#define CAMERA_H

typedef struct Camera {
    float x;
    float y;
    float z;
    float pitch;
    float yaw;
} Camera;

Camera* initCamera(float x, float y, float z);

#endif
