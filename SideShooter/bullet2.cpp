#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "bullet2.h"
#include <iostream>
#include <math.h>
using namespace std;

bullet2::bullet2()									//Class constructor
{
	hits2 = 0;
	speed2 = 15;
	live2 = false;
	tieExplode = al_load_sample("tieExplode.wav");
	image2 = al_load_bitmap("bullet.png");
	laserBlast = al_load_sample("laserBlast.wav");

}
bullet2::~bullet2()									//Class destructor
{
	al_destroy_bitmap(image2);
}
void bullet2::Drawbullet2()							//draw bullet based on status
{
	if(live2)
		
		al_draw_filled_circle(x2, y2, 4, al_map_rgb(0, 255, 0));
		al_draw_filled_circle(x2+64, y2, 4, al_map_rgb(0, 255, 0));

}
void bullet2::Firebullet2(level2 &level2)				//Gets directional values when the spacebar is pressed.
{
	if(!live2)
	{
		x2 = level2.getX();
		y2 = level2.getY();
		live2 = true;
		al_play_sample(laserBlast, .1, 1, 5.0, ALLEGRO_PLAYMODE_ONCE, NULL);

	}
}
void bullet2::Updatebullet2(int HEIGHT, level2 &level2)	//Updates bullet based on values retrieved when fired
{
	if (live2)
	{
		y2 = y2 - speed2;

		if (y2 <= 0)
			live2 = false;
		if (x2 <= 0)
			live2 = false;
		if (x2 >= 700)
			live2 = false;
	}
}
void bullet2::Collidebullet2(enemy2 enemys[], int cSize, level2 &level2)		//Erase bullet if collision occurs.
{
	if(live2)
	{
		for(int j =0; j < cSize; j++)
		{
			if(enemys[j].getLive())
			{
				if(x2 > (enemys[j].getX() - enemys[j].getBoundX()) &&
					x2 < (enemys[j].getX() + enemys[j].getBoundX()) &&
					y2 > (enemys[j].getY() - enemys[j].getBoundY()) &&
					y2 < (enemys[j].getY() + enemys[j].getBoundY()))
				{
					live2 = false;
					enemys[j].setLive(false);
					level2.updateScore();									//Update score when bullet makes impact upon a enemy
					enemys[j].setDead(true);
					al_play_sample(tieExplode, .6, 1, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

				}
			}
		}
	}

}
void bullet2::CollidebulletBoss2(boss &bossS, level2 &level2)					//Calculate collision of bullet to the boss
{
	if (live2)
	{
		for (int j = 0; j < 1; j++)
		{
			if (bossS.getLive())
			{
				if (x2 >(bossS.getX() - bossS.getBoundX()) &&
					x2 < (bossS.getX() + bossS.getBoundX()) &&
					y2 >(bossS.getY() - bossS.getBoundY()) &&
					y2 < (bossS.getY() + bossS.getBoundY()))
				{
					live2 = false;
					level2.updateScore();									//Update score when bullet makes impact upon a enemy
					bossS.setDead(true);
					bossS.updateHits();
				}
			}
		}
	}
	if (bossS.getHits() > 300){												//Kills the boss when enough hits has occured
		bossS.setLive(false);
	}
}