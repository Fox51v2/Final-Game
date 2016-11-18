#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
using namespace std;
class level2
{
	friend int collided(int x, int y);
	friend bool endValue( int x, int y );
	friend bool endGame(int x, int y);
	friend bool getMap2(int x, int y);
	friend bool getMap3(int x, int y);

public:
	level2();
	~level2();
	void Initlevel2s(int width, int height);
	void Updatelevel2s(int width, int height, int dir); //dir 1 = right, 0 = left, 2 = Standing Still
	void Drawlevel2s(int xoffset, int yoffset);
	//void setJump(int jumplevel2) { curFrame = jumplevel2; }
	bool Collidelevel2();
	float getX() {return x;}
	float getY() {return y;}
	int getWidth() {return frameWidth;}
	int getHeight() {return frameHeight;}
	int jumping(int jump, const int JUMPIT);
	bool CollisionEndBlock();
	bool CollisionEndGame();
	bool CollisionMap2();
	bool CollisionMap3();
	void setJumpFrame();

private:
	float x;
	float y;

	int jumpFrame;
	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int animationColumns;
	int animationRows;
	int animationDirection;
	bool jumped;
	bool falling;
	bool left;
	bool right;
	ALLEGRO_BITMAP *image;
};