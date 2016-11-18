#ifndef level2H
#define level2H
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

class level2
{
public:
	level2(int HEIGHT, int WIDTH);
	~level2();
	void Drawlevel2();
	void MoveUp();
	void MoveDown(int HEIGHT);
	void MoveLeft();
	void MoveRight();
	void updateScore(){ score++; }
	int getScore(){ return score; }
	int getBoundX(){ return boundx; }
	int getBoundY(){ return boundy; }
	int getX(){ return x; }
	int getY(){ return y; }
	void setHard(bool l){ hard = l; }
	bool getHard() { return hard; }
	void removeLife(){ lives--; }
	void usedLives(){ livesUsed++; }
	int getLives(){ return lives; }
	void setLives(){ lives = 0; }
	float getAngle(){ return angle; }

private:
	int x;
	int y;
	int lives;
	int livesUsed;
	int speed;
	int boundx;
	int boundy;
	int score;
	bool hard;
	bool killed;
	float angle;

	ALLEGRO_BITMAP *image[5];
	ALLEGRO_BITMAP *base[5];

};
#endif
