#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "draw.h"

void drawQuad(const float size) {
    glBegin(GL_QUADS);
        glVertex3f(-size, -size,  0.0f);
        glVertex3f( size, -size,  0.0f);
        glVertex3f( size,  size,  0.0f);
        glVertex3f(-size,  size,  0.0f);
    glEnd();
}

void drawCube(const float width, const float height, const float depth) {
    glBegin(GL_QUADS);
        // face Xa
     // glVertex3f(width, height, depth);
        glVertex3f(width, height, 0    );
        glVertex3f(0,     height, 0    );
        glVertex3f(0,     0,      0    );
        glVertex3f(width, 0,      0    );

        // face Za
        glVertex3f(0,     height, 0    );
        glVertex3f(0,     height, depth);
        glVertex3f(0,     0,      depth);
        glVertex3f(0,     0,      0    );
    glEnd();
}
