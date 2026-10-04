#ifndef ACCRETION
#define ACCRETION

#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define WIDTH 1920
#define HEIGHT 1080
#define TERMINAL_GREEN (Color){1, 22, 5, 255}
#define NUM_PARTICLES 100
#define CAM_POS (Vector3){100,100,100}
#define CAM_TARG (Vector3){0,0,0}
#define CAM_UP (Vector3){0,0,1}
#define CAM_FOV 90
#define CAM_PRO CAMERA_PERSPECTIVE
#define RANDOM_METRIC 50 //initial diffusion
#define PARTICLE_MASS_CONST 20
#define PARTICLE_RAD 0.3
#define FRAME_RATE 60
#define ELAPSED_TIME_INITIALIZER 99999999
#define INF 9999999999
#define NINF -999999999
#define CENTRAL_MASS 80

typedef struct particle{
	Vector3 position;
	Vector3 velo;
	Vector3 accel;
	double mass;
}PARTICLE;

void cam_init(Camera3D* cam);
void particles_init(PARTICLE particles[NUM_PARTICLES]);

#endif
