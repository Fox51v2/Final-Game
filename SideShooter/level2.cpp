#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "level2.h"
#include <iostream>
using namespace std;

level2::~level2()
{
	for (int i = 0; i < 5; i++){
		al_destroy_bitmap(image[i]);
	}
}
level2::level2(int HEIGHT, int WIDTH)
{
	image[0] = al_load_bitmap("xwing.png");						//level2 image array
	image[1] = al_load_bitmap("xwing1.png");
	image[2] = al_load_bitmap("xwing2.png");
	image[3] = al_load_bitmap("xwing3.png");
	image[4] = al_load_bitmap("xwing4.png");

	livesUsed = 0;
	killed = false;
	x = 64;
	y = HEIGHT / 1.2;
	lives = 5;												//initialize level2 values.
	speed = 7;
	boundx = al_get_bitmap_width(image[0]);
	boundy = al_get_bitmap_height(image[0]);
	score = 0;
}
void level2::Drawlevel2()
{
	if (livesUsed <= 4){
		al_draw_bitmap(image[livesUsed], x, y, 0);
	}
	else{
		killed = true;										//If none remain then ship/base is dead
	}
}
void level2::MoveUp()
{

}
void level2::MoveDown(int HEIGHT)
{

}
//If move left then draw rotated bitmap and adjust the bullet direction.
void level2::MoveLeft()
{
	x = x - 10;
	if (x <= 0){
		x = 0;
	}
}
//If move right then draw rotated bitmap and adjust the bullet direction.
void level2::MoveRight()
{
	x = x + 10;
	if (x >= 636){
		x = 636;
	}
}
