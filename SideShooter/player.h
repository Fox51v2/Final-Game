#ifndef PLAYERH
#define PLAYERH
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

class player
{
public:
	player(int HEIGHT, int WIDTH);
	~player();
	void DrawPlayer();
	void MoveUp();
	void MoveDown(int HEIGHT);
	void MoveLeft();
	void MoveRight();
	void updateScore(){ score++; }
	int getScore(){ return score; }
	int getBoundX(){return boundx;}
	int getBoundY(){return boundy;}
	int getX(){return x;}
	int getY(){return y;}
	void setHard(bool l){ hard = l; }
	void setLives(){ lives=5; }
	void setScore(){ score = 0; }
	bool getHard() { return hard; }
	void removeLife(){ lives--; }
	void usedLives(){ livesUsed++; }
	int getLives(){ return lives; }
	int getLives2(){ return lives2; }
	float getAngle(){ return angle; }

private:
	int x;
	int y;
	int lives;
	int lives2;
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
