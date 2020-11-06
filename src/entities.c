#include <stdlib.h>
#include "ecs.h"
#include "components.h"
#include "paul_math.h"

// for use in this file only
int create_entity_id(Ecs *ecs) {
    int eid;

    eid = ecs->entity_count;
    ecs->entity_count += 1;
    return eid;
}

int create_spinsquare(Ecs *ecs) {
    int eid;
    WorldPos *pos;
    WorldPitchYaw *rot;

    eid = create_entity_id(ecs);
    ecs_add_world_pos(ecs, cmp_create_world_pos(eid));
    ecs_add_world_pitch_yaw(ecs, cmp_create_world_pitch_yaw(eid));
    ecs_add_render_cube(ecs, cmp_create_render_cube(eid));
    pos = ecs_get_world_pos(ecs, eid);
    rot = ecs_get_world_pitch_yaw(ecs, eid);

    // pos->x = rand_float() % 200.0 - 100.0;
    // pos->y = rand_float() % 200.0 - 100.0;
    // pos->z = rand_float() % 200.0 - 100.0;
    // float vel_max = .05;
    // rot->vel_pitch = rand_float() * vel_max - vel_max/2;
    // rot->vel_yaw = rand_float() * vel_max - vel_max/2;
    // rot->pitch = rand_float() * 360.0;
    // rot->yaw = rand_float() * 360.0;
    return eid;
}
