#ifndef COMPONENTS_H
#define COMPONENTS_H

typedef struct WorldPos {
    int eid;
    float x, y, z;
} WorldPos;

WorldPos *cmp_create_world_pos(int eid);

typedef struct WorldPitchYaw {
    int eid;
    float pitch, yaw;
} WorldPitchYaw;

WorldPitchYaw *cmp_create_world_pitch_yaw(int eid);

typedef struct Renderable {
    int eid;
} Renderable;

Renderable *cmp_create_renderable(int eid);

#endif
