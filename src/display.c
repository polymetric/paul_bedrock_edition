#include <stdlib.h>
#include <stdio.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "display.h"

#include "camera.h"

Display *initDisplay() {
    Display *display = (Display*) malloc(sizeof(Display));
    
	glfwInit();
		
	// gl version 2.1
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

	// TODO move this to a settings struct
	glfwWindowHint(GLFW_SAMPLES, 8);
	
	// create window and check for errors
	display->window = glfwCreateWindow(
		WINDOW_DEFAULT_WIDTH,		// width
		WINDOW_DEFAULT_HEIGHT,		// height
		"Bruh",						// title
		NULL,						// monitor
		NULL						// share
	);
	if (display->window == NULL) {
		fprintf(stderr, "cant create window oof\n");
		glfwTerminate();
		exit(-1);
	}
	
	glfwMakeContextCurrent(display->window);
	
	// load GLEW and check for errors
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		fprintf(stderr, "wops big glew error: %s\n", glewGetErrorString(err));
	}
	fprintf(stderr, "loaded GLEW %s\n", glewGetString(GLEW_VERSION));

	return display;
}

// resize the gl viewport when the window is resized by the user
void display_update_size(Display *display) {
	glfwGetFramebufferSize(display->window, &display->width, &display->height);
	glViewport(0, 0, display->width, display->height);
}