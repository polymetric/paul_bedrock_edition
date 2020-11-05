#include <stdlib.h>
#include "ecs.h"
#include "components.h"

int create_entity_id(Ecs *ecs) {
    int eid;

    eid = ecs->entity_count;
    ecs->entity_count += 1;
    return eid;
}

int create_spinsquare(Ecs *ecs) {
    int eid;

    eid = create_entity_id(ecs);
    ecs_add_world_pos(ecs, cmp_create_world_pos(eid));
    ecs_add_world_pitch_yaw(ecs, cmp_create_world_pitch_yaw(eid));
    ecs_add_render_cube(ecs, cmp_create_render_cube(eid));
    return eid;
}
