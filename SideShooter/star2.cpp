#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "star2.h"

star::star()									//class constructor
{
	image5 = al_load_bitmap("star.png");
	al_convert_mask_to_alpha(image5, al_map_rgb(0, 0, 0));

	live = false;
	dead = false;
	speed = (rand() % 20);
	boundx = al_get_bitmap_width(image5);
	boundy = al_get_bitmap_height(image5);

}
star::~star()									//class destructor
{
	al_destroy_bitmap(image5);
}
void star::Drawstar()							//Draws star image based on their live status
{
	if(live)
	{
		al_draw_bitmap(image5, x, y, 0);
	}

}
void star::Startstar(int WIDTH, int HEIGHT )	//Starts each new star at a random location
{
	if(!live)
	{
		if(rand() % 50 == 0)
		{
			live = true;
			x = rand() % (WIDTH - boundx);
			y = 0;

		}
	}
}
void star::UpdateStars()						//Moves the star-
{												//This could be simplified but I left it based on
												//live for possible modification later.
	if(live)
	{
		y += speed;
	}

}
void star::Collidestar(level2 &level2)
{
		if (y >= 700)
		{
			live = false;
		}
	
}