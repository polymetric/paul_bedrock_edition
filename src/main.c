#include <stdlib.h>
#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "input/keyHandler.h"

#define WINDOW_DEFAULT_WIDTH    800
#define WINDOW_DEFAULT_HEIGHT   600

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
	
	// main loop
	while (!glfwWindowShouldClose(window)) {
		// clear screen
		glClearColor(0, 0, 0, 1);
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

		glMatrixMode(GL_MODELVIEW);
		
		// actual rendering
		
		// check/call events and swap buffers at the end of the frame
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	return 0;
}
