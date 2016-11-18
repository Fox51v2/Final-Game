#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "mappy_A5.h"
#include <iostream>
using namespace std;
class Sprite5
{
	friend int collided(int x, int y);
	friend bool endTrench(int x, int y);
	friend bool inTrench(int x, int y);
	friend bool getMap2(int x, int y);
	friend bool getMap3(int x, int y);

public:
	Sprite5();
	~Sprite5();
	void InitSprites(int width, int height);
	void UpdateSprites(int width, int height, int dir); //dir 1 = right, 0 = left, 2 = Standing Still
	void DrawSprites(int xoffset, int yoffset);
	//void setJump(int jumpSprite) { curFrame = jumpSprite; }
	bool CollideSprite();
	float getX() { return x; }
	float getY() { return y; }
	int getWidth() { return frameWidth; }
	int getHeight() { return frameHeight; }
	int jumping(int jump, const int JUMPIT);
	bool CollisionEndBlock();
	bool CollisionEndGame();
	bool CollisionMap2();
	bool CollisionMap3();
	void setJumpFrame();
	int speed;

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
	ALLEGRO_BITMAP *image5;
};