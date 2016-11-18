#ifndef starH
#define starH
#include "level2.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

class star
{
public:
	star();
	~star();
	void Drawstar();
	void Startstar(int WIDTH, int HEIGHT );
	void UpdateStars();
	void Collidestar(level2 &level2);
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
	int starSpeed;

		ALLEGRO_BITMAP *image5;
};
#endif
