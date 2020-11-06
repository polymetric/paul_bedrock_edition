#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "ecs.h"
#include "components.h"
#include "systems.h"
#include "draw.h"
#include <math.h>

void sys_world_pos_update(Ecs *ecs) {
    int i;
    WorldPos *pos;

    for (i = 0; i < ecs->cmps_world_pos_count; i++) {
        pos = ecs_get_world_pos(ecs, i);

        pos->x += pos->vel_x;
        pos->y += pos->vel_y;
        pos->z += pos->vel_z;
    }
}

void sys_world_pitch_yaw_update(Ecs *ecs) {
    int i;
    WorldPitchYaw *rot;

    for (i = 0; i < ecs->cmps_world_pitch_yaw_count; i++) {
        rot = ecs_get_world_pitch_yaw(ecs, i);
        
        rot->pitch += rot->vel_pitch;
        rot->yaw += rot->vel_yaw;
    }
}

void sys_render_cube_update(Ecs *ecs) {
    int i;
    WorldPos *pos;
    WorldPitchYaw *rot;
    RenderCube *cube;

    // setup gl state
    // this still assumes we've just loaded the camera matrix.
    glMatrixMode(GL_MODELVIEW);

    for (i = 0; i < ecs->cmps_render_cube_count; i++) {
        pos = ecs_get_world_pos(ecs, i);
        rot = ecs_get_world_pitch_yaw(ecs, i);
        cube = ecs_get_render_cube(ecs, i);
        
		glPushMatrix();
        glTranslatef(pos->x, pos->y, pos->z);
        glRotatef(rot->pitch, 1, 0, 0);
        glRotatef(rot->yaw, 0, 1, 0);
		drawCubeCentered(cube->width, cube->height, cube->depth);
		glPopMatrix();
    }
}
