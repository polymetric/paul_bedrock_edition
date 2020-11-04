#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "camera.h"
#include "display.h"

Camera *initCamera(float x, float y, float z) {
    Camera *camera = (Camera*) malloc(sizeof(Camera));
    camera->x = x;
    camera->y = y;
    camera->z = z;
    camera->pitch = 0.0;
    camera->yaw = 0.0;
    camera->vFov = 70.0;
    camera->zNear = 0.1;
    camera->zFar = 1000.0;
    return camera;
}

void setupCameraMatrices(Camera *camera, Display *display) {
    // setup projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
        camera->vFov,							// vertical FOV
        (float) display->width / (float) display->height,		// aspect ratio
        camera->zNear,				            // near clip plane
        camera->zFar				        	// far clip plane
    );

    // setup camera transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(camera->pitch, 1.0f, 0.0f, 0.0f);
    glRotatef(camera->yaw, 0.0f, 1.0f, 0.0f);
    glTranslatef(-camera->x, -camera->y, -camera->z);
}
