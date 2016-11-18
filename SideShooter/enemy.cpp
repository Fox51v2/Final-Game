#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "enemy.h"

enemy::enemy()									//class constructor
{
	image = al_load_bitmap("tieFighter.png");
	image2 = al_load_bitmap("deadTieFighter.png");
	sample = al_load_sample("Whatjunk.wav");
	al_convert_mask_to_alpha(image, al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(image2, al_map_rgb(0, 0, 0));

	live = false;
	dead = false;
	speed = (rand() % 7)+2;
	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);

}
enemy::~enemy()									//class destructor
{
	al_destroy_bitmap(image);
	al_destroy_bitmap(image2);
}
void enemy::Drawenemy()							//Draws enemy image based on their live status
{
	if(live)
	{
		al_draw_bitmap(image, x, y, 0);
	}
	if (!live)
	{
		al_draw_bitmap(image2, x, y, 0);
	}
}
void enemy::Startenemy(int WIDTH, int HEIGHT )	//Starts each new enemy at a random location
{
	if(!live)
	{
		if(rand() % 500 == 0)
		{
			live = true;
			x = rand() % (WIDTH - boundx);
			y = 0;

		}
	}
}
void enemy::Updateenemy()						//Moves the enemy-
{												//This could be simplified but I left it based on
												//live for possible modification later.
	if(live)
	{
		y += speed;
	}
	if (!live)
	{
		y += speed;
	}

}
void enemy::Collideenemy(player &Player)
{
	if(live)
	{
		if ((y >= 500 && x>= 300)){

			Player.removeLife();											
			Player.usedLives();												

			dead = true;
			live = false;
			al_play_sample(sample, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		}
	}
}