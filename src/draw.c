#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "draw.h"

void drawQuad(float size) {
    glBegin(GL_QUADS);
        glVertex3f(-size, -size,  0.0f);
        glVertex3f( size, -size,  0.0f);
        glVertex3f( size,  size,  0.0f);
        glVertex3f(-size,  size,  0.0f);
    glEnd();
}

void drawQuadCentered(float size) {
    size /= 2;
    glBegin(GL_QUADS);
        glVertex3f(-size, -size,  0.0f);
        glVertex3f( size, -size,  0.0f);
        glVertex3f( size,  size,  0.0f);
        glVertex3f(-size,  size,  0.0f);
    glEnd();
}

void drawCube(float width, float height, float depth) {
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

        // face Xb
        glVertex3f(0,     0,      depth);
        glVertex3f(width, 0,      depth);
        glVertex3f(width, height, depth);
        glVertex3f(0,     height, depth);

        // face Zb
        glVertex3f(width, 0,      depth);
        glVertex3f(width, 0,      0    );
        glVertex3f(width, height, 0    );
        glVertex3f(width, height, depth);

        // face Ya
        glVertex3f(width, 0,      depth);
        glVertex3f(0,     0,      depth);
        glVertex3f(0,     0,      0    );
        glVertex3f(width, 0,      0    );

        // face Yb
        glVertex3f(width, height, 0    );
        glVertex3f(0,     height, 0    );
        glVertex3f(0,     height, depth);
        glVertex3f(width, height, depth);
    glEnd();
}

void drawCubeCentered(float width, float height, float depth) {
    width  /= 2;
    height /= 2;
    depth  /= 2;
    glBegin(GL_QUADS);
        // face Xa
     // glVertex3f(width, height, depth);
        glNormal3f( 0,      0,      -1    );
        glVertex3f( width,  height, -depth);
        glVertex3f(-width,  height, -depth);
        glVertex3f(-width, -height, -depth);
        glVertex3f( width, -height, -depth);
   
        // face Za   
        glNormal3f(-1,      0,       0    );
        glVertex3f(-width,  height, -depth);
        glVertex3f(-width,  height,  depth);
        glVertex3f(-width, -height,  depth);
        glVertex3f(-width, -height, -depth);
   
        // face Xb   
        glNormal3f( 0,      0,       1    );
        glVertex3f(-width, -height,  depth);
        glVertex3f( width, -height,  depth);
        glVertex3f( width,  height,  depth);
        glVertex3f(-width,  height,  depth);
   
        // face Zb   
        glNormal3f( 1,      0,       0    );
        glVertex3f( width, -height,  depth);
        glVertex3f( width, -height, -depth);
        glVertex3f( width,  height, -depth);
        glVertex3f( width,  height,  depth);
   
        // face Ya   
        glNormal3f( 0,     -1,       0    );
        glVertex3f( width, -height,  depth);
        glVertex3f(-width, -height,  depth);
        glVertex3f(-width, -height, -depth);
        glVertex3f( width, -height, -depth);
   
        // face Yb   
        glNormal3f( 0,      1,       0    );
        glVertex3f( width,  height, -depth);
        glVertex3f(-width,  height, -depth);
        glVertex3f(-width,  height,  depth);
        glVertex3f( width,  height,  depth);
    glEnd();
    
}
