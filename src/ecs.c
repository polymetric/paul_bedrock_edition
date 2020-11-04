#include <stdlib.h>
#include "components.h"
#include "ecs.h"

void ecs_init(Ecs **ecs) {
    *ecs = (Ecs*) malloc(sizeof(Ecs));
    (*ecs)->entity_count = 0;
    (*ecs)->cmps_world_pos = (WorldPos**) malloc(COMPONENT_ARRAY_SIZE * sizeof(size_t));
    (*ecs)->cmps_world_pos_count = 0;
    (*ecs)->cmps_world_pos_lastid = 0;
    (*ecs)->cmps_world_pitch_yaw = (WorldPitchYaw**) malloc(COMPONENT_ARRAY_SIZE * sizeof(size_t));
    (*ecs)->cmps_world_pitch_yaw_count = 0;
    (*ecs)->cmps_world_pitch_yaw_lastid = 0;
    (*ecs)->cmps_renderable = (Renderable**) malloc(COMPONENT_ARRAY_SIZE * sizeof(size_t));
    (*ecs)->cmps_renderable_count = 0;
    (*ecs)->cmps_renderable_lastid = 0;
}

void ecs_add_world_pos(Ecs *ecs, WorldPos *world_pos) {
    ecs->cmps_world_pos[ecs->cmps_world_pos_lastid] = world_pos;
    ecs->cmps_world_pos_lastid += 1;
    ecs->cmps_world_pos_count += 1;
}

WorldPos *ecs_get_world_pos(Ecs *ecs, int eid) {
    // TODO error checking
    return ecs->cmps_world_pos[eid];
}

void ecs_add_world_pitch_yaw(Ecs *ecs, WorldPitchYaw *world_pitch_yaw) {
    ecs->cmps_world_pitch_yaw[ecs->cmps_world_pitch_yaw_lastid] = world_pitch_yaw;
    ecs->cmps_world_pitch_yaw_lastid += 1;
    ecs->cmps_world_pitch_yaw_count += 1;
}

void ecs_add_renderable(Ecs *ecs, Renderable *renderable) {
    ecs->cmps_renderable[ecs->cmps_renderable_lastid] = renderable;
    ecs->cmps_renderable_lastid += 1;
    ecs->cmps_renderable_count += 1;
}
