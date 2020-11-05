#ifndef ECS_H
#define ECS_H

#include "components.h"

#define COMPONENT_ARRAY_SIZE 1024

typedef struct Ecs {
    int             entity_count;

    WorldPos      **cmps_world_pos;
    int             cmps_world_pos_count;
    int             cmps_world_pos_lastid;
    WorldPitchYaw **cmps_world_pitch_yaw;
    int             cmps_world_pitch_yaw_count;
    int             cmps_world_pitch_yaw_lastid;
    RenderCube    **cmps_render_cube;
    int             cmps_render_cube_count;
    int             cmps_render_cube_lastid;
} Ecs;

void ecs_init(Ecs **ecs);
void ecs_add_world_pos(Ecs *ecs, WorldPos *world_pos);
WorldPos *ecs_get_world_pos(Ecs *ecs, int eid);
void ecs_add_world_pitch_yaw(Ecs *ecs, WorldPitchYaw *world_pitch_yaw);
void ecs_add_render_cube(Ecs *ecs, RenderCube *render_cube);

#endif
