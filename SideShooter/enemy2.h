#ifndef enemyH2
#define enemyH2
#include "level2.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

class enemy2
{
public:
	enemy2();
	~enemy2();
	void DrawStars();
	void StartStars(int WIDTH, int HEIGHT);
	void UpdateStars();
	void Drawenemy();
	void Startenemy(int WIDTH, int HEIGHT);
	void Updateenemy();
	void Collideenemy(level2 &level2);
	int getBoundX(){ return boundx; }
	int getBoundY(){ return boundy; }
	int getX(){ return x; }
	int getY(){ return y; }
	bool getLive() { return live; }
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

	ALLEGRO_BITMAP *image2;
	ALLEGRO_BITMAP *image;
	ALLEGRO_SAMPLE *sample;

};
#endif
