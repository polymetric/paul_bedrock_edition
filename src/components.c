#include <stdlib.h>
#include "components.h"

WorldPos *cmp_create_world_pos(int eid) {
    WorldPos *world_pos = (WorldPos*) malloc(sizeof(WorldPos));
    world_pos->eid = eid;
    world_pos->x = 0.0;
    world_pos->y = 0.0;
    world_pos->z = 0.0;
    return world_pos;
}

WorldPitchYaw *cmp_create_world_pitch_yaw(int eid) {
    WorldPitchYaw *world_pitch_yaw = (WorldPitchYaw*) malloc(sizeof(WorldPitchYaw));
    world_pitch_yaw->eid = eid;
    world_pitch_yaw->pitch = 0;
    world_pitch_yaw->yaw = 0;
    return world_pitch_yaw;
}

RenderCube *cmp_create_render_cube(int eid) {
    RenderCube *render_cube = (RenderCube*) malloc(sizeof(RenderCube));
    render_cube->eid = eid;
    return render_cube;
}
