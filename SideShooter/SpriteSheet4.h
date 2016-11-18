#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
using namespace std;
class Sprite4
{
	friend int collided4(int x, int y);
	friend bool inMap(int x, int y);
	friend bool endMap(int x, int y);
public:
	Sprite4();
	~Sprite4();
	void InitSprites4(int width, int height);
	void UpdateSprites4(int width, int height, int dir); //dir 1 = right, 0 = left, 2 = Standing Still
	void DrawSprites4(int xoffset, int yoffset);
	//void setJump(int jumpSprite) { curFrame = jumpSprite; }
	bool CollideSprite();
	float getX() { return x; }
	float getY() { return y; }
	int getWidth() { return frameWidth; }
	int getHeight() { return frameHeight; }
	int jumping(int jump, const int JUMPIT);
	bool CollisionEndBlock();
	bool CollisionEndGame();
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