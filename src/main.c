// stdlib includes
#include <stdlib.h>
#include <stdio.h>

// gl includes
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// local includes
#include "draw.h"
#include "camera.h"

// parameters
#define WINDOW_DEFAULT_WIDTH    800
#define WINDOW_DEFAULT_HEIGHT   600

// called whenever a key is pressed
// we use camelcase even though it's terrible,
// because all the GL stuff uses it :/
void keyCallback(
	GLFWwindow* window,
	int key,
	int scancode,
	int action,
	int mods
) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

int main(int argc, char** argv) {
	glfwInit();
		
	// gl version 2.1 core
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
	
	// create window and check for errors
	GLFWwindow* window = glfwCreateWindow(
		WINDOW_DEFAULT_WIDTH,		// width
		WINDOW_DEFAULT_HEIGHT,		// height
		"Bruh",						// title
		NULL,						// monitor
		NULL						//
	);
	if (window == NULL) {
		printf("cant create window oof\n");
		glfwTerminate();
		exit(-1);
	}
	
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, &keyCallback);
	
	// // load GLAD and check for errors
	// if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
	// 	printf("can't init GLAD\n");
	// 	exit(-1);
	// }

	// load GLEW and check for errors
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		fprintf(stderr, "wops big glew error: %s\n", glewGetErrorString(err));
	}
	printf("loaded GLEW %s\n", glewGetString(GLEW_VERSION));

	// TEMPORARY camera
	Camera* camera = initCamera(0.0f, 0.0f, 5.0f);

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
		glPopMatrix();
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
		
		// check/call events and swap buffers at the end of the frame
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	return 0;
}
