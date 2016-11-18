#include "level2.h"
#include <iostream>
using namespace std;

level2::level2()
{
	image=NULL;
}
level2::~level2()
{
	al_destroy_bitmap(image);
}
void level2::Initlevel2s(int width, int height)
{
	x = 80;
	y = 50;

	left = false;
	right = false;
	falling = false;
	maxFrame = 2;
	curFrame = 0;
	jumpFrame = 9;
	frameCount = 0;
	frameDelay = 6;
	frameWidth = 32;
	frameHeight = 32;
	animationColumns = 3;
	animationDirection = 1;

	image = al_load_bitmap("r2d2.png");
	al_convert_mask_to_alpha(image, al_map_rgb(255,0,255));
}

void level2::Updatelevel2s(int width, int height, int dir)
{
	int oldx = x;
	int oldy = y;

	if(dir == 1){ //right key
		animationDirection = 1; 
		x+=2; 
		right = true;
		if ((++frameCount > frameDelay)) //if right and not falling
		{
			frameCount=0;
			if (++curFrame >= 3)
				curFrame=1;
		}
	}
	else if (dir == 0){ //left key
		animationDirection = 0; 
		x-=2; 
		left = true;
		if ((++frameCount > frameDelay))  //if left and not falling
		{
			frameCount=0;
			if (++curFrame >= 3)
				curFrame=1;
		}
	}
	else if (dir == 4){ //up key
		animationDirection = 1;
		y -= 2;
		left = true;
		if ((++frameCount > frameDelay))  //if left and not falling
		{
			frameCount = 0;
			if (++curFrame >= 3)
				curFrame = 1;
		}
	}
	else if (dir == 5){ //down key
		animationDirection = 1;
		y += 2;
		left = true;
		if ((++frameCount > frameDelay))  //if left and not falling
		{
			frameCount = 0;
			if (++curFrame >= 3)
				curFrame = 1;
		}
	}
	   else //represent that they hit the space bar and that mean direction = 0
		animationDirection = dir;

	//check for collided with foreground tiles
	if (animationDirection==0)
	{ 
		if (collided(x, y + frameHeight)) { //collision detection to the left
			x = oldx; 
			y = oldy;
		}

	}

	else if (animationDirection ==1)
	{ 
		if (collided(x + frameWidth, y + frameHeight)) { //collision detection to the right
			x = oldx; 
			y= oldy;
		}
	}
}

bool level2::CollisionEndBlock()
{
	if (endValue(x + frameWidth / 2, y + frameHeight + 5)){

		return true;
	}
	else
		return false;
}

bool level2::CollisionEndGame()
{
	if (endGame(x + frameWidth / 2, y + frameHeight + 5)){

		return true;
	}
	else
		return false;
}

void level2::setJumpFrame()
{		
	jumped = true;
}

void level2::Drawlevel2s(int xoffset, int yoffset)
{
	int fx = (curFrame % animationColumns) * frameWidth;
	int fy = (curFrame / animationColumns) * frameHeight;

	if ((animationDirection == 1)||(right==true)){
		al_draw_bitmap_region(image, fx, fy, frameWidth,frameHeight, x-xoffset, y-yoffset, 0
			);
		right = false;

	}
	else if ((animationDirection == 0) || (left == true)){
		al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - xoffset, y - yoffset, ALLEGRO_FLIP_HORIZONTAL);
		left = false;
		//ALLEGRO_FLIP_HORIZONTAL
	}
	else if (animationDirection == 2){
		al_draw_bitmap_region(image, 0, 0, frameWidth, frameHeight, x - xoffset, y - yoffset, 0);
	}
	else if (animationDirection == 3){
		al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - xoffset, y - yoffset, 0);
	}

}

int level2::jumping(int jump, const int JUMPIT)
{
	//handle jumping
	if (jump==JUMPIT) { 
		if (!collided(x + frameWidth/2, y + frameHeight + 5))
			jump = 0;

	}
	else
	{
		while ((collided(x, y)) || (collided(x + frameWidth / 2, y + frameHeight)))
		{
			y += 3;
		}

	}

	if (jump<0) 
	{				
		if (collided(x + frameWidth/2,  y + frameHeight))
		{ 
			falling=false;
			//cout << "landed" << endl;
			jump = JUMPIT; 
			while (collided(x + frameWidth/2,y + frameHeight))
			{
				x = x;
				y -= 3;
			}
		} 
	}
	if (y <= 0){
		y = 0;
	}
	return jump;
}