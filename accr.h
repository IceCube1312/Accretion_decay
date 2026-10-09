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
#define NUM_PARTICLES 30000
#define CAM_POS (Vector3){50,50,50}
#define CAM_TARG (Vector3){0,0,0}
#define CAM_UP (Vector3){0,0,1}
#define CAM_FOV 90
#define CAM_PRO CAMERA_PERSPECTIVE
#define RANDOM_METRIC 50 //initial diffusion
#define PARTICLE_RAD 0.3
#define FRAME_RATE 60
#define ELAPSED_TIME_INITIALIZER 99999999
#define INF 9999
#define NINF -9999
#define CENTRAL_MASS 200000
#define MONTE_CARLO_FACTOR 10
#define RAD_FACTOR 5
#define NUM_TRAIL 2
#define SPIN_BIAS (Vector3){0,0,1}
#define SOFTENING_FACTOR 2000

typedef struct particle{
	Vector3 position;
	Vector3 velo;
	Vector3 accel;
	Vector3 trail[NUM_TRAIL];
	int trail_head;
}PARTICLE;

void cam_init(Camera3D* cam);
void particles_init(PARTICLE particles[NUM_PARTICLES]);
void updating_velo_accel_pos(PARTICLE particles[NUM_PARTICLES]);
void checking_collisions_monte_carlo(PARTICLE particles[NUM_PARTICLES]);
void draw_trails(PARTICLE particle);

#endif
