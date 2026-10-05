#include "accr.h"

int main(int argc, char** argv){
	
	int height = HEIGHT;
	int width = WIDTH;

	InitWindow(width,height,"WORK PLEASE");
	assert(IsWindowReady());
	SetTargetFPS(FRAME_RATE);

	Camera3D cam;
	cam_init(&cam);

	PARTICLE particles[NUM_PARTICLES];
	particles_init(particles);

	double elapsed_time = ELAPSED_TIME_INITIALIZER;
	double frame_time = 1/FRAME_RATE;

	while(!WindowShouldClose()){
		if(elapsed_time>=frame_time){
			UpdateCamera(&cam, CAMERA_THIRD_PERSON);
			BeginDrawing();
			ClearBackground(TERMINAL_GREEN);
			BeginMode3D(cam);
			DrawLine3D((Vector3){0,0,INF},(Vector3){0,0,NINF},GREEN);
			DrawLine3D((Vector3){0,INF,0},(Vector3){0,NINF,0},BLUE);
			DrawLine3D((Vector3){INF,0,0},(Vector3){NINF,0,0},RED);
			updating_velo_accel_pos(particles);
              		checking_collisions_monte_carlo(particles);
			for(int i=0;i<NUM_PARTICLES;i++){
				DrawPoint3D(particles[i].position, WHITE);
				draw_trails(particles[i]);
			}

			EndMode3D();
			EndDrawing();
		}
		elapsed_time = GetFrameTime();
	}

	return 0;
}
