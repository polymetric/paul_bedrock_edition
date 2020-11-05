#ifndef COMPONENTS_H
#define COMPONENTS_H

typedef struct WorldPos {
    int eid;
    float x, y, z;
    float vel_x, vel_y, vel_z;
} WorldPos;

WorldPos *cmp_create_world_pos(int eid);

typedef struct WorldPitchYaw {
    int eid;
    float pitch, yaw;
} WorldPitchYaw;

WorldPitchYaw *cmp_create_world_pitch_yaw(int eid);

typedef struct RenderCube {
    int eid;
} RenderCube;

RenderCube *cmp_create_render_cube(int eid);

// typedef struct Camera {
//     int eid;
//     float fov_v;
//     float z_near;
//     float z_far;
// } Camera;

// Camera *cmp_create_camera(int eid);

#endif
