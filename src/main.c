#include <stdlib.h>
#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "gameState.h"
#include "draw.h"
#include "camera.h"

#define WINDOW_DEFAULT_WIDTH    800
#define WINDOW_DEFAULT_HEIGHT   600

int main(int argc, char **argv) {
	GameState *gameState = initGameState();
    gameState->display = initDisplay();
	GLFWwindow *window = gameState->display->window;

	// TEMPORARY camera
	gameState->camera = initCamera(0.0f, 0.0f, 5.0f);
	Camera *camera = gameState->camera;

	float thing1Rot = 0.0f;
	float thing2Rot = 0.0f;
	
	// main loop
	while (!glfwWindowShouldClose(window)) {
		// TICK
		thing1Rot += 1.0f;
		thing2Rot += 1.0f;

		// RENDER
		// clear screen
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// resize the gl viewport when the window is resized by the user
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		// setup projection matrix
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		// temp frustum variables
		// TODO move these to some sort of settings struct in the future
		GLdouble vFov = 70;
		int zNear = 1;
		int zFar = 1000;
		gluPerspective(
			vFov,									// vertical FOV
			(GLfloat) width / (GLfloat) height,		// aspect ratio
			(GLfloat) zNear,						// near clip plane
			(GLfloat) zFar							// far clip plane
		);

		// setup camera transformation
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef(camera->pitch, 1.0f, 0.0f, 0.0f);
		glRotatef(camera->yaw, 0.0f, 1.0f, 0.0f);
		glTranslatef(-camera->x, -camera->y, -camera->z);

		// actual rendering

		// quad a
		glPushMatrix();
		glRotatef(thing1Rot, 0.0f, 1.0f, 0.0f);
		drawQuad(1.0f);

		glPopMatrix();
		glPushMatrix();

		glTranslatef(-3, 0, 0);
		glRotatef(thing2Rot, 1.0f, 0.0f, 0.0f);
		drawQuad(1.0f);

		// gui render
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(0, width, height, 0, 1, -1);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(100.0f, 100.0f, 0.0f);
		drawQuad(100);
		glPopMatrix();

		// check/call events and swap buffers at the end of the frame
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	return 0;
}
