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
		double velo_mod = sqrt(CENTRAL_MASS / rad);
		Vector3 randomVec = {rand(),rand(),rand()};
		Vector3 velo_dir = Vector3CrossProduct(randomVec,r); //cross product of the position vector with any random vector will result in a vector perpendicular to position which suffices the condition for the particle's velocity
		velo_dir = Vector3Normalize(velo_dir);
		particles[i].velo = Vector3Scale(velo_dir,velo_mod);
	}
}

void updating_velo_accel_pos(PARTICLE particles[NUM_PARTICLES]){
	float dt = GetFrameTime();
	for(int i = 0; i < NUM_PARTICLES; i++){
		float dist = Vector3Length(particles[i].position);
		if (dist > 0.1f) { 
			Vector3 dir_to_center = Vector3Scale(particles[i].position, -1.0f / dist);
			float accel_scalar = CENTRAL_MASS / (dist * dist);
			particles[i].accel = Vector3Scale(dir_to_center, accel_scalar);
			particles[i].velo = Vector3Add(particles[i].velo, Vector3Scale(particles[i].accel, dt));
		}
		particles[i].position = Vector3Add(particles[i].position, Vector3Scale(particles[i].velo, dt));
	}
}

void checking_collisions_monte_carlo(PARTICLE particles[NUM_PARTICLES]){
	for(int i=0;i<NUM_PARTICLES;i++){
		for(int j=0;j<MONTE_CARLO_FACTOR;j++){
			int k = rand() % NUM_PARTICLES;
			if (k==i){
				continue;
			}
			double particle_radius = PARTICLE_RAD;
			double dist = Vector3Distance(particles[i].position,particles[k].position);
			if(dist > RAD_FACTOR*(2*particle_radius)){
				continue;
			}
			Vector3 Avg_velo = Vector3Add(particles[i].velo,particles[k].velo);
			Avg_velo = Vector3Scale(Avg_velo,0.5);
			particles[i].velo = Avg_velo;
			particles[k].velo = Avg_velo;
		}
	}
}
