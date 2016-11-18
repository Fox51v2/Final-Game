#ifndef enemyH
#define enemyH
#include "player.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

class enemy
{
public:
	enemy();
	~enemy();
	void Drawenemy();
	void Startenemy(int WIDTH, int HEIGHT );
	void Updateenemy();
	void Collideenemy(player &Player);
	int getBoundX(){return boundx;}
	int getBoundY(){return boundy;}
	int getX(){return x;}
	int getY(){return y;}
	bool getLive() {return live;}
	void setLive(bool l){ live = l; }
	void setDead(bool l){ dead = l; }

private:
	int x;
	int y;
	bool dead;
	bool live;
	int speed;
	int boundx;
	int boundy;
	
		ALLEGRO_BITMAP *image2;
		ALLEGRO_BITMAP *image;
		ALLEGRO_SAMPLE *sample;

};
#endif
