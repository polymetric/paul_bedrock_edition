#ifndef SYSTEMS_H
#define SYSTEMS_H

#include "ecs.h"
#include "components.h"

void sys_world_pos_update(Ecs *ecs);
void sys_world_pos_set(Ecs *ecs, int eid, float x, float y, float z);
void sys_renderable_update(Ecs *ecs);

#endif
