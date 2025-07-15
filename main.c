#include "raylib.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_PARTICLES 1000


typedef struct {
    Vector2 position;
    Vector2 velocity;
    Color color;
    bool active;
} Particle;

int ran_pos(int min, int max){
	return random() % (max - min + 1) + min;
}

void draw_particles(Particle *particles){
	//ClearBackground(BLACK);
	for (int i = 0; i < MAX_PARTICLES; i++) {
		if (particles[i].active){
                	DrawPixel((int)particles[i].position.x, (int)particles[i].position.y, particles[i].color);
		}
	}
}
int main(){
	const int x = 1000;
	const int y = 1000;
	const int speed =150;
	const int prox = 200;
	int c=0;

	srandom(time(NULL));
	Particle particles[MAX_PARTICLES] = {0};


	for (int i = 0; i < MAX_PARTICLES; i++) {
        particles[i].position = (Vector2){ ran_pos(0, x), ran_pos( 0, y )};
        particles[i].velocity = (Vector2){ GetRandomValue(-10, 10) / 10.0f, GetRandomValue(-10, 10) / 10.0f };
        particles[i].color = (Color){ GetRandomValue(100,255), GetRandomValue(100,255), GetRandomValue(100,255), 255 };
        particles[i].active = true;
    }

	InitWindow(x, y, "hellow world");
	SetTargetFPS(150);

	while (!WindowShouldClose()){
		c++;

		//funky_particle_logic
		for(int i =0; i<MAX_PARTICLES; i++){ //changing x/y position of particles based on mouse
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && abs ((particles[i].position.x - GetMouseX()))<prox && abs(particles[i].position.y - GetMouseY()) < prox ){
				particles[i].position.x =particles[i].position.x + (GetMouseX() - particles[i].position.x)/speed;
				particles[i].position.y =particles[i].position.y + (GetMouseY() - particles[i].position.y)/speed;
			}
			     if ((particles[i].position.x + particles[i].velocity.x) >= x){ particles[i].velocity.x = ran_pos(-10, 0) /10.0f;} //border on >x
			     if ((particles[i].position.x + particles[i].velocity.x) <= 0){ particles[i].velocity.x = ran_pos(0, -10) /10.0f;} //border on x<
			     if ((particles[i].position.y + particles[i].velocity.y) >= y){ particles[i].velocity.y = ran_pos(-10, 0) /10.0f;} //border on ^y
			     if ((particles[i].position.y + particles[i].velocity.y) <= 0){ particles[i].velocity.y = ran_pos(0, -10) /10.0f;} //border on other y
			//changing x/y position of particles based on velocity
			particles[i].position.x = particles[i].position.x + particles[i].velocity.x;
			particles[i].position.y = particles[i].position.y + particles[i].velocity.y;
		}

		BeginDrawing();
		if(c%10==0){ClearBackground(BLACK);}
		draw_particles(particles);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
