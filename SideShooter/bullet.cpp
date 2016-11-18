#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "bullet.h"
#include <iostream>
#include <math.h>
using namespace std;

bullet::bullet()									//Class constructor
{
	hits = 0;
	speed = 30;
	live = false;
	image = al_load_bitmap("bullet.png");
	tieExplode = al_load_sample("tieExplode.wav");
	laserBlast = al_load_sample("laserBlast.wav");

}
bullet::~bullet()									//Class destructor
{
	al_destroy_bitmap(image);
}
void bullet::Drawbullet()							//draw bullet based on status
{
	if(live)
		
		//al_draw_bitmap(image, x, y, 0);
		al_draw_filled_circle(x, y, 8, al_map_rgb(255, 255, 255));
		//al_draw_filled_circle(x, y, 6, al_map_rgb(255, 0, 0));

}
void bullet::Firebullet(player &Player)				//Gets directional values when the spacebar is pressed.
{
	if(!live)
	{
		angle = Player.getAngle();
		x = Player.getX();
		y = Player.getY();
		live = true;
		al_play_sample(laserBlast, .1, 1, 5.0, ALLEGRO_PLAYMODE_ONCE, NULL);
	}
}
void bullet::Updatebullet(int HEIGHT, player &Player)	//Updates bullet based on values retrieved when fired
{
	if (live)
	{
		y -= speed*cos(angle);		x += speed*sin(angle);

		if (y <= 0)
			live = false;
		if (x <= 0)
			live = false;
		if (x >= 700)
			live = false;
	}
}
void bullet::Collidebullet(enemy enemys[], int cSize, player &Player)		//Erase bullet if collision occurs.
{
	if(live)
	{
		for(int j =0; j < cSize; j++)
		{
			if(enemys[j].getLive())
			{
				if(x > (enemys[j].getX() - enemys[j].getBoundX()) &&
					x < (enemys[j].getX() + enemys[j].getBoundX()) &&
					y > (enemys[j].getY() - enemys[j].getBoundY()) &&
					y < (enemys[j].getY() + enemys[j].getBoundY()))
				{
					live = false;
					enemys[j].setLive(false);
					Player.updateScore();									//Update score when bullet makes impact upon a enemy
					enemys[j].setDead(true);
					al_play_sample(tieExplode, .6, 1, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

				}
			}
		}
	}

}
void bullet::CollidebulletBoss(boss &bossS, player &Player)					//Calculate collision of bullet to the boss
{
	if (live)
	{
		for (int j = 0; j < 1; j++)
		{
			if (bossS.getLive())
			{
				if (x >(bossS.getX() - bossS.getBoundX()) &&
					x < (bossS.getX() + bossS.getBoundX()) &&
					y >(bossS.getY() - bossS.getBoundY()) &&
					y < (bossS.getY() + bossS.getBoundY()))
				{
					live = false;
					Player.updateScore();									//Update score when bullet makes impact upon a enemy
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