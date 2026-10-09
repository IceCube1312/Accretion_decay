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

 	        Vector3 r = particles[i].position;
		double rad = Vector3Length(r);
		double velo_mod = sqrt(CENTRAL_MASS / rad);
		Vector3 noise = Vector3Normalize((Vector3) {rand()-((RAND_MAX)/2),rand()-((RAND_MAX)/2),rand()-(RAND_MAX/2)});
		Vector3 random_vector = Vector3Add(noise, SPIN_BIAS );
		Vector3 velo_dir = Vector3CrossProduct(random_vector,r); //cross product of the position vector with any random vector will result in a vector perpendicular to position which suffices the condition for the particle's velocity
		velo_dir = Vector3Normalize(velo_dir);
		particles[i].velo = Vector3Scale(velo_dir,velo_mod);

		for(int j=0;j<NUM_TRAIL;j++){
			particles[i].trail[j] = particles[i].position;
		}
		particles[i].trail_head = 0;
	}
}

void updating_velo_accel_pos(PARTICLE particles[NUM_PARTICLES]){
	float dt = GetFrameTime();
	for(int i = 0; i < NUM_PARTICLES; i++){
		float dist = Vector3Length(particles[i].position);
		if (dist > 0.1f) { 
			Vector3 dir_to_center = Vector3Normalize(particles[i].position);
			dir_to_center = Vector3Scale(dir_to_center,-1);
			float accel_scalar = CENTRAL_MASS / (SOFTENING_FACTOR+(dist * dist));
			particles[i].accel = Vector3Scale(dir_to_center, accel_scalar);
			particles[i].velo = Vector3Add(particles[i].velo, Vector3Scale(particles[i].accel, dt));
		}
		particles[i].trail[particles[i].trail_head] = particles[i].position;
		particles[i].trail_head = (particles[i].trail_head+1)%NUM_TRAIL;
		
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

void draw_trails(PARTICLE particle){
        for(int j=0;j<NUM_TRAIL-1;j++){
                int current_index = (particle.trail_head -1 - j + NUM_TRAIL) % NUM_TRAIL;
                Vector3 current = particle.trail[current_index];
                int prev_index = (particle.trail_head - 2 - j + NUM_TRAIL) % NUM_TRAIL;
                Vector3 prev_point = particle.trail[prev_index];
                double ratio = j/(double)NUM_TRAIL;
                int G =  255 * (1-ratio);
                DrawLine3D(current,prev_point,WHITE);
	}
}
