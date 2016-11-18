#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
//#include "boss.h"
#include "bullet.h"
#include <iostream>
using namespace std;

boss::boss()									//Class constructor
{
	boss0 = al_load_bitmap("boss0.png");
	boss1 = al_load_bitmap("boss1.png");
	boss2 = al_load_bitmap("boss2.png");
	boss3 = al_load_bitmap("boss3.png");

	live = false;
	dead = false;
	hits = 0;
	wave = 0;
	boundx = al_get_bitmap_width(boss0);
	boundy = al_get_bitmap_height(boss0);

}
boss::~boss()									//Class destructor
{
	al_destroy_bitmap(boss0);
	al_destroy_bitmap(boss1);
	al_destroy_bitmap(boss2);
	al_destroy_bitmap(boss3);
}
void boss::Drawboss()							//Draw boss based on hits
{
	if ((hits <= 100))
	{
		al_draw_bitmap(boss0, x, y, 0);
	}
	else if ((hits >= 100) && (hits <= 200))
	{
		al_draw_bitmap(boss1, x, y, 0);
	}
	else if ((hits >= 200) && (hits <= 300))
	{
		al_draw_bitmap(boss2, x, y, 0);
	}
	else{
		al_draw_bitmap(boss3, x, y, 0);
	}
}
void boss::Startboss(int WIDTH, int HEIGHT)			//Starts the boss in a random location
{
	if (!live)
	{
		wave += 1;
		speed += .5;
		hits = 0;
		live = true;
		x = rand() % (WIDTH - boundx);
		y = 0;
	}
}
void boss::Updateboss()								//Updates boss based on initial location
{

	if (live)
	{
		y += speed;
	}
	if (!live)
	{
		y += speed;
	}
}
void boss::Collideboss(player &Player)				//Detect collision between player and bullet
{
	if (live)
	{
		if (x - boundx < Player.getX() + Player.getBoundX() &&
			x + boundx > Player.getX() - Player.getBoundX() &&
			y - boundy < Player.getY() + Player.getBoundY() &&
			y + boundy > Player.getY() - Player.getBoundY())
		{
			Player.removeLife();											//Decrement player lives upon impact with boss
			Player.usedLives();												//Increment lives used upon impact with a boss

			live = false;
		}
		if ((Player.getHard())&&(y - boundy < Player.getY() + Player.getBoundY() &&
			y + boundy > Player.getY() - Player.getBoundY())){

			Player.removeLife();											
			Player.usedLives();												

			dead = true;
			live = false;
		}
		if (y >= 700)
		{
			live = false;
		}
	}
}