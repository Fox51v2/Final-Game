#include "SpriteSheet4.h"
#include <iostream>
using namespace std;

Sprite4::Sprite4()
{
	image = NULL;
}
Sprite4::~Sprite4()
{
	al_destroy_bitmap(image);
}
void Sprite4::InitSprites4(int width, int height)
{
	x = 80;
	y = 50;

	left = false;
	right = false;
	falling = false;
	maxFrame = 12;
	curFrame = 0;
	jumpFrame = 9;
	frameCount = 0;
	frameDelay = 6;
	frameWidth = 34;
	frameHeight = 34;
	animationColumns = 5;
	animationDirection = 1;

	image = al_load_bitmap("new.png");
	al_convert_mask_to_alpha(image, al_map_rgb(255, 0, 255));
}

void Sprite4::UpdateSprites4(int width, int height, int dir)
{
	int oldx = x;
	int oldy = y;

	if (dir == 1){ //right key
		animationDirection = 1;
		x += 2;
		right = true;
		if ((++frameCount > frameDelay)) //if right and not falling
		{
			frameCount = 0;
			if (++curFrame >= 4)
				curFrame = 1;
		}
	}
	else if (dir == 0){ //left key
		animationDirection = 0;
		x -= 2;
		left = true;
		if ((++frameCount > frameDelay))  //if left and not falling
		{
			frameCount = 0;
			if (++curFrame >= 4)
				curFrame = 1;
		}
	}
	else //represent that they hit the space bar and that mean direction = 0
		animationDirection = dir;

	//check for collided with foreground tiles
	if (animationDirection == 0)
	{
		if (collided4(x, y + frameHeight)) { //collision detection to the left
			x = oldx;
			y = oldy;
		}

	}

	else if (animationDirection == 1)
	{
		if (collided4(x + frameWidth, y + frameHeight)) { //collision detection to the right
			x = oldx;
			y = oldy;
		}
	}
}

bool Sprite4::CollisionEndBlock()
{
	if (inMap(x + frameWidth / 2, y + frameHeight + 5)){

		return true;
	}
	else
		return false;
}

bool Sprite4::CollisionEndGame()
{
	if (endMap(x + frameWidth / 2, y + frameHeight + 5)){

		return true;
	}
	else
		return false;
}

void Sprite4::setJumpFrame()
{
	jumped = true;
}

void Sprite4::DrawSprites4(int xoffset, int yoffset)
{
	int fx = (curFrame % animationColumns) * frameWidth;
	int fy = (curFrame / animationColumns) * frameHeight;

	if ((animationDirection == 1) || (right == true)){
		al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - xoffset, y - yoffset, 0);
		right = false;

	}
	else if ((animationDirection == 0) || (left == true)){
		al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - xoffset, y - yoffset, ALLEGRO_FLIP_HORIZONTAL);
		left = false;
	}
	else if (animationDirection == 2){
		al_draw_bitmap_region(image, 0, 0, frameWidth, frameHeight, x - xoffset, y - yoffset, 0);
	}
	else if (animationDirection == 3){
		al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - xoffset, y - yoffset, 0);
	}
}

int Sprite4::jumping(int jump, const int JUMPIT)
{
	//handle jumping
	if (jump == JUMPIT) {
		if (!collided4(x + frameWidth / 2, y + frameHeight + 5))
			jump = 0;

	}
	else
	{
		//if (!collided(x , y))
		//{
		UpdateSprites4(x, y, 3);
		y -= jump / 3;
		jump--;									//If you do not want to pass through blocks while 
		falling = true;							//jumping then unvoid the if and while statements.
		//cout << "jumped" << endl;
		//}
		//while (collided(x, y))
		//{
		//	y += 3;
		//}

	}

	if (jump<0)
	{
		if (collided4(x + frameWidth / 2, y + frameHeight))
		{
			falling = false;
			//cout << "landed" << endl;
			jump = JUMPIT;
			while (collided4(x + frameWidth / 2, y + frameHeight))
			{
				y -= 3;
			}
		}
	}
	if (y <= 0){
		y = 0;
	}
	return jump;
}