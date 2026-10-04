#include "accr.h"

void cam_init(Camera3D* cam){
	cam->position = CAM_POS;
	cam->target = CAM_TARG;
	cam->up = CAM_UP;
	cam->fovy = CAM_FOV;
	cam->projection = CAM_PRO;
}

void particles_init(PARTICLE particles[NUM_PARTICLES]){
	for(int i=0;i<NUM_PARTICLES;i++){
		double x = (rand() % (2* RANDOM_METRIC))-RANDOM_METRIC;
		double y = (rand() % (2* RANDOM_METRIC))-RANDOM_METRIC;
		double z = (rand() % (2* RANDOM_METRIC))-RANDOM_METRIC;
		particles[i].position=(Vector3){x,y,z};
		particles[i].accel = Vector3Zero();
		particles[i].mass = PARTICLE_MASS_CONST;

		Vector3 r = Vector3Subtract(particles[i].position,Vector3Zero());
		double rad = Vector3Length(r);
		double velo_mod = sqrt(CENTRAL_MASS / r);


	}
}

void updating_velo_accel_pos{


