#include "SpriteSheet.h"
#include <iostream>
using namespace std;

Sprite::Sprite()
{
	image=NULL;
}
Sprite::~Sprite()
{
	al_destroy_bitmap(image);
}
void Sprite::InitSprites(int width, int height)
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
	image = al_load_bitmap("tieEx.png");
	al_convert_mask_to_alpha(image, al_map_rgb(255,0,255));
}

void Sprite::UpdateSprites(int width, int height, int dir)
{
	int oldx = x;
	int oldy = y;
	y = y - 12;
	if(dir == 1){ //right key
		animationDirection = 1; 
		x+=speed; 
		right = true;
	}
	else if (dir == 0){ //left key
		animationDirection = 0; 
		x-=speed; 
		left = true;
	}
	else if (dir == 4){ //up key
		animationDirection = 1;
		y -= speed;
		left = true;
	}
	else if (dir == 5){ //down key
		animationDirection = 1;
		y += speed;
		left = true;
	}
	   else //represent that they hit the space bar and that mean direction = 0
		animationDirection = dir;

	//check for collided with foreground tiles
	if (animationDirection==0)
	{ 
		if (x<=110) { //collision detection to the left
			x = oldx; 
		}

	}

	else if (animationDirection ==1)
	{ 
		if (x>=290) { //collision detection to the right
			x = oldx; 
		}
	}
}

bool Sprite::CollisionEndBlock()
{
	if (endValue(x + frameWidth / 2, y + frameHeight + 5)){

		return true;
	}
	else
		return false;
}

bool Sprite::CollisionEndGame()
{
	if (endGame(x + frameWidth / 2, y + frameHeight + 5)){

		return true;
	}
	else
		return false;
}

void Sprite::DrawSprites(int xoffset, int yoffset)
{
	int fx = (curFrame % animationColumns) * frameWidth;
	int fy = (curFrame / animationColumns) * frameHeight;

	al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - xoffset, y - yoffset, 0);

}
