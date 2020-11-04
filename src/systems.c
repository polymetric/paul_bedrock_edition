#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "ecs.h"
#include "components.h"
#include "systems.h"
#include "draw.h"

void sys_world_pos_update(Ecs *ecs) {
    int i;
    WorldPos *pos;

    for (i = 0; i < ecs->cmps_world_pos_count; i++) {
        pos = ecs->cmps_world_pos[i];
    }
}

void sys_world_pitch_yaw_update(Ecs *ecs) {
    int i;
    WorldPitchYaw *rot;

    for (i = 0; i < ecs->cmps_world_pitch_yaw_count; i++) {
        rot = ecs->cmps_world_pitch_yaw[i];
        rot->yaw += 1;
        rot->pitch += .2;
    }
}

void sys_renderable_update(Ecs *ecs) {
    int i;
    WorldPos *pos;
    WorldPitchYaw *rot;

    // setup gl state
    // this still assumes we've just loaded the camera matrix.
    glMatrixMode(GL_MODELVIEW);

    for (i = 0; i < ecs->cmps_renderable_count; i++) {
        pos = ecs->cmps_world_pos[i];
        rot = ecs->cmps_world_pitch_yaw[i];
        
		glPushMatrix();
        glTranslatef(pos->x, pos->y, pos->z);
        glRotatef(rot->pitch, 1, 0, 0);
        glRotatef(rot->yaw, 0, 1, 0);
		drawCubeCentered(1, 1, 1);
		glPopMatrix();
    }
}
