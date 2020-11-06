#include <stdlib.h>
#include "components.h"

WorldPos *cmp_create_world_pos(int eid) {
    WorldPos *pos = (WorldPos*) malloc(sizeof(WorldPos));
    pos->eid = eid;
    pos->x = 0.0;
    pos->y = 0.0;
    pos->z = 0.0;
    pos->vel_x = 0.0;
    pos->vel_y = 0.0;
    pos->vel_z = 0.0;
    return pos;
}

WorldPitchYaw *cmp_create_world_pitch_yaw(int eid) {
    WorldPitchYaw *rot = (WorldPitchYaw*) malloc(sizeof(WorldPitchYaw));
    rot->eid = eid;
    rot->pitch = 0.0;
    rot->yaw = 0.0;
    rot->vel_pitch = 0.0;
    rot->vel_yaw = 0.0;
    return rot;
}

RenderCube *cmp_create_render_cube(int eid) {
    RenderCube *cube = (RenderCube*) malloc(sizeof(RenderCube));
    cube->eid = eid;
    cube->width = 1.0;
    cube->height = 1.0;
    cube->depth = 1.0;
    return cube;
}
