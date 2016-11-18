#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"
#include <iostream>
using namespace std;

player::~player()
{
	for (int i=0; i < 5; i++){
		al_destroy_bitmap(image[i]);
		al_destroy_bitmap(base[i]);
	}
}
player::player(int HEIGHT, int WIDTH)
{
	base[0] = al_load_bitmap("hothDamage.png");						//player base image array
	base[1] = al_load_bitmap("hothDamage0.png");
	base[2] = al_load_bitmap("hothDamage1.png");
	base[3] = al_load_bitmap("hothDamage2.png");
	base[4] = al_load_bitmap("hothDamage3.png");

	image[0] = al_load_bitmap("turretBarrel.png");						//player image array
	image[1] = al_load_bitmap("turretBarrel.png");
	image[2] = al_load_bitmap("turretBarrel.png");
	image[3] = al_load_bitmap("turretBarrel.png");
	image[4] = al_load_bitmap("turretBarrel.png");

	al_convert_mask_to_alpha(image[0], al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(image[1], al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(image[2], al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(image[3], al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(image[4], al_map_rgb(0, 0, 0));

	livesUsed = 0;
	killed = false;
	x = 64;
	y = HEIGHT / 1.2;
	lives = 5;
	lives2 = 5;
	//initialize player values.
	speed = 7;
	boundx = al_get_bitmap_width(image[0]);
	boundy = al_get_bitmap_height(image[0]);
	score = 0;
}
void player::DrawPlayer()
{
	if (livesUsed <= 4){
		al_draw_bitmap(base[livesUsed], 0, 0, 0);				
		al_draw_rotated_bitmap(image[livesUsed], boundx / 2, boundy/2, x, y, angle, 0);	
		}
	else{
		killed = true;										//If none remain then ship/base is dead
	}
}
void player::MoveUp()
{

}
void player::MoveDown(int HEIGHT)
{

}
//If move left then draw rotated bitmap and adjust the bullet direction.
void player::MoveLeft()
{
	if (angle <= 0){
		angle = 0;
	 	al_draw_rotated_bitmap(image[livesUsed], boundx / 2, boundy / 2, x, y, angle, 0);
	}
	else{
		angle -= .1;
		al_draw_rotated_bitmap(image[livesUsed], boundx / 2, boundy / 2, x, y, angle, 0);
	}
}
//If move right then draw rotated bitmap and adjust the bullet direction.
void player::MoveRight()
{
	if (angle >= 1.6){
		angle = 1.6;
 		al_draw_rotated_bitmap(image[livesUsed], boundx / 2, boundy / 2, x, y, angle, 0);
	}
	else{
		angle += .1;
		al_draw_rotated_bitmap(image[livesUsed], boundx / 2, boundy / 2, x, y, angle, 0);
	}
}
