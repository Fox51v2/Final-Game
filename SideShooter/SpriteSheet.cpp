#include "SpriteSheet.h"
#include "mappy_A5.h"
#include <iostream>

using namespace std;

Sprite5::Sprite5()
{
	image5 = NULL;
}
Sprite5::~Sprite5()
{
	al_destroy_bitmap(image5);
}
void Sprite5::InitSprites(int width, int height)
{
	x = 160;
	y = 5500;

	left = false;
	right = false;
	falling = false;
	maxFrame = 2;
	curFrame = 0;
	jumpFrame = 9;
	frameCount = 0;
	frameDelay = 6;
	frameWidth = 64;
	frameHeight = 57;
	animationColumns = 3;
	animationDirection = 1;
	speed = 15;
	image5 = al_load_bitmap("tieEx.png");
	al_convert_mask_to_alpha(image5, al_map_rgb(255, 0, 255));
}

void Sprite5::UpdateSprites(int width, int height, int dir)
{
	int oldx = x;
	int oldy = y;
	y = y - 12;
	if (dir == 1){ //right key
		x += speed;
		right = true;
	}
	else if (dir == 0){ //left key
		x -= speed;
		left = true;
	}


	//check for collided with foreground tiles
	if (dir == 0)
	{
		if (x <= 110) { //collision detection to the left
			x = oldx;
		}

	}

	else if (dir == 1)
	{
		if (x >= 290) { //collision detection to the right
			x = oldx;
		}
	}
}

bool Sprite5::CollisionEndBlock()
{
	if (endTrench(x + frameWidth / 2, y + frameHeight + 5)){

		return true;
	}
	else
		return false;
}

bool Sprite5::CollisionEndGame()
{
	if (inTrench(x + frameWidth / 2, y + frameHeight + 5)){

		return true;
	}
	else
		return false;
}

void Sprite5::DrawSprites(int xoffset, int yoffset)
{
	int fx = (curFrame % animationColumns) * frameWidth;
	int fy = (curFrame / animationColumns) * frameHeight;

	al_draw_bitmap_region(image5, fx, fy, frameWidth, frameHeight, x - xoffset, y - yoffset, 0);

}