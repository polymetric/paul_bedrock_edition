#ifndef CAMERA_H
#define CAMERA_H

typedef struct Camera {
    float x, y, z;
    float pitch, yaw;
    float vFov, zNear, zFar;
} Camera;

Camera *initCamera(float x, float y, float z);

#endif
