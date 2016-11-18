#ifndef bossH
#define bossH
#include "player.h"

class boss
{
public:
	boss();
	~boss();
	void Drawboss();
	void Startboss(int WIDTH, int HEIGHT);
	void Updateboss();
	void Collideboss(player &Player);
	int getBoundX(){ return boundx; }
	int getBoundY(){ return boundy; }
	int getX(){ return x; }
	int getY(){ return y; }
	int getHits(){ return hits; }
	int getWave(){ return wave; }
	void setBossSpeed(double speedBoost){ speed += speedBoost; }
	bool getLive() { return live; }
	void setLive(bool l){ live = l; }
	void setDead(bool l){ dead = l; }
	void updateHits(){ hits++; }

private:
	int x;
	int y;
	int wave;
	int hits;
	bool dead;
	bool live;
	double speed = 1;
	int boundx;
	int boundy;

	ALLEGRO_BITMAP *boss3;
	ALLEGRO_BITMAP *boss2;
	ALLEGRO_BITMAP *boss1;
	ALLEGRO_BITMAP *boss0;
};
#endif
