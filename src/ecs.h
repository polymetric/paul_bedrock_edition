#ifndef ECS_H
#define ECS_H

#include "components.h"

#define COMPONENT_ARRAY_SIZE 256

typedef struct Ecs {
    int             entity_count;

    WorldPos      **cmps_world_pos;
    int             cmps_world_pos_count;
    int             cmps_world_pos_lastid;
    WorldPitchYaw **cmps_world_pitch_yaw;
    int             cmps_world_pitch_yaw_count;
    int             cmps_world_pitch_yaw_lastid;
    Renderable    **cmps_renderable;
    int             cmps_renderable_count;
    int             cmps_renderable_lastid;
} Ecs;

void ecs_init(Ecs **ecs);
void ecs_add_world_pos(Ecs *ecs, WorldPos *world_pos);
WorldPos *ecs_get_world_pos(Ecs *ecs, int eid);
void ecs_add_world_pitch_yaw(Ecs *ecs, WorldPitchYaw *world_pitch_yaw);
void ecs_add_renderable(Ecs *ecs, Renderable *renderable);

#endif
