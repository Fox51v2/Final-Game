#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "enemy2.h"

enemy2::enemy2()									//class constructor
{
	image = al_load_bitmap("tieFighter.png");
	image2 = al_load_bitmap("deadTieFighter.png");
	//image3 = al_load_bitmap("base2.png");
	al_convert_mask_to_alpha(image, al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(image2, al_map_rgb(0, 0, 0));
	sample = al_load_sample("r2d2.wav");

	live = false;
	dead = false;
	speed = (rand() % 28)+2;
	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);

}
enemy2::~enemy2()									//class destructor
{
	al_destroy_bitmap(image);
	al_destroy_bitmap(image2);
}
void enemy2::Drawenemy()							//Draws enemy image based on their live status
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
void enemy2::Startenemy(int WIDTH, int HEIGHT )	//Starts each new enemy at a random location
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
void enemy2::Updateenemy()						//Moves the enemy-
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
void enemy2::Collideenemy(level2 &level2)
{
	if (live)
	{
		if (x - boundx < level2.getX() + level2.getBoundX() - 50 &&
			x + boundx > level2.getX() - level2.getBoundX() + 50 &&
			y - boundy < level2.getY() + level2.getBoundY() &&
			y + boundy > level2.getY() - level2.getBoundY() + 50)
		{
			level2.removeLife();											//Decrement level2 lives upon impact with enemy
			level2.usedLives();												//Increment lives used upon impact with a enemy
			al_play_sample(sample, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			live = false;
		}
		if (y >= 700)
		{
			live = false;
		}
	}
}