#include <stdlib.h>
#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "display.h"

#include "input.h"
#include "draw.h"
#include "camera.h"

#define WINDOW_DEFAULT_WIDTH    800
#define WINDOW_DEFAULT_HEIGHT   600

Display *initDisplay() {
    Display *display = (Display*) malloc(sizeof(Display));
    
	glfwInit();
		
	// gl version 2.1 core
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
	
	// create window and check for errors
	display->window = glfwCreateWindow(
		WINDOW_DEFAULT_WIDTH,		// width
		WINDOW_DEFAULT_HEIGHT,		// height
		"Bruh",						// title
		NULL,						// monitor
		NULL						// share
	);
	if (display->window == NULL) {
		printf("cant create window oof\n");
		glfwTerminate();
		exit(-1);
	}
	
	glfwMakeContextCurrent(display->window);
	glfwSetKeyCallback(display->window, &keyCallback);
	
	// load GLEW and check for errors
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		fprintf(stderr, "wops big glew error: %s\n", glewGetErrorString(err));
	}
	printf("loaded GLEW %s\n", glewGetString(GLEW_VERSION));

	return display;
}