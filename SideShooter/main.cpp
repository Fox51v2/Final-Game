//Shane Chamberlain
//CPSC440
//FinalProject

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "SpriteSheet.h"
#include "SpriteSheet4.h"
#include "mappy_A5.h"
#include "player.h"
#include "level2.h"
#include "enemy.h"
#include "enemy2.h"
#include "bullet.h"
#include "bullet2.h"
#include "boss.h"
#include "star2.h"
#include <iostream>
using namespace std;

int main(void)
{
	//variables
	int lives;
	int score;
	int highScore = 0;
	bool doneLevel1 = false;
	bool doneLevel2 = false;
	bool doneLevel4 = false;
	bool doneLevel5 = false;

	bool title = false;
	bool redraw = true;
	const int FPS = 60;

	const int NUM_stars = 100;
	const int WIDTH = 700;
	const int HEIGHT = 700;
	const int ENDWIDTH = 700;
	const int ENDHEIGHT = 700;
	const int NUM_bulletS = 50;
	const int NUM_enemyS = 15;
	//const int NUM_bossS = 1;
	bool render = false;

	enum KEYS{ UP, DOWN, LEFT, RIGHT, SPACE };
	bool keys[5] = { false, false, false, false, false };
	int fpsTimer = 7200;
	int countDown = 30;
	int time = 30;
	bool loss = false;
	bool done = false;
	bool intro1 = false;
	bool intro2 = false;
	bool intro4 = false;
	bool intro5 = false;

	bool endMap(int x, int y);//End Block with the User Value = 8
	bool inMap(int x, int y);//End Block with the User Value = 2
	bool endTrench(int x, int y);//End Block with the User Value = 8
	bool inTrench(int x, int y);//End Block with the User Value = 2

	int xOff = 0;
	int yOff = 0;

	//allegro variable
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_SAMPLE *sample = NULL;
	ALLEGRO_SAMPLE *level1Music = NULL;
	ALLEGRO_SAMPLE *level2Music = NULL;
	ALLEGRO_SAMPLE *level3Music = NULL;
	ALLEGRO_SAMPLE *level1IntroSound = NULL;

	ALLEGRO_BITMAP *background = NULL;
	ALLEGRO_BITMAP *victoryBackground = NULL;
	ALLEGRO_BITMAP *level1Intro = NULL;
	ALLEGRO_BITMAP *level2Intro = NULL;
	ALLEGRO_BITMAP *level4Intro = NULL;
	ALLEGRO_BITMAP *level5Intro = NULL;

	ALLEGRO_BITMAP *base = NULL;
	ALLEGRO_BITMAP *introScreen = NULL;

	Sprite5 player5;
	Sprite4 player4;
	const int JUMPIT = 1600;
	int jump = JUMPIT;

	//program init
	if (!al_init())										//initialize Allegro
		return -1;
	if (!al_install_audio())
		return -1;
	if (!al_init_acodec_addon())
		return -1;
	if (!al_reserve_samples(10))
		return -1;

	al_set_target_bitmap(al_get_backbuffer(display));

	al_init_font_addon();
	al_init_ttf_addon();

	//font declarations
	ALLEGRO_FONT *fontTop = al_load_font("mk4.ttf", 42, 0);
	ALLEGRO_FONT *fontScore = al_load_font("mk4.ttf", 28, 0);
	ALLEGRO_FONT *fontIntro = al_load_font("galaga.ttf", 32, 0);

	display = al_create_display(WIDTH, HEIGHT);			//create our display object
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	if (!display)										//test display object
		return -1;

	//Install and initialize
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	//object variables
	bullet bullets[NUM_bulletS];
	bullet2 bullets2[NUM_bulletS];
	enemy enemys[NUM_enemyS];
	enemy2 enemys2[NUM_enemyS];
	star stars[NUM_stars];

	//Register events
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	//Bitmap declarations
	introScreen = al_load_bitmap("titleScreen.png");
	background = al_load_bitmap("test.png");
	victoryBackground = al_load_bitmap("victoryBackground.png");
	level1Intro = al_load_bitmap("level1Intro.png");
	level2Intro = al_load_bitmap("level2Intro.png");
	level4Intro = al_load_bitmap("level4Intro.png");

	level5Intro = al_load_bitmap("level5Intro.png");
	sample = al_load_sample("r2d2.wav");
	level1Music = al_load_sample("level1Music.wav");
	level2Music = al_load_sample("r2d2.wav");
	level3Music = al_load_sample("r2d2.wav");
	level1IntroSound = al_load_sample("level1IntroSound.wav");

	player5.InitSprites(WIDTH, HEIGHT);
	player4.InitSprites4(WIDTH, HEIGHT);

	if (MapLoad("trenchRun.fmp", 1))
		return -5;
	//base = al_load_bitmap("base0.png");

	al_start_timer(timer);
	//al_play_sample(sample, 1.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	al_play_sample(level1Music, .4, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	while ((!title) && (!done))
	{
		//Draws the intro text
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		al_draw_bitmap(introScreen, 0, 0, 0);
		al_flip_display();

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			if (keys[SPACE]){
				title = true;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			title = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_S:
				title = true;
				break;
			}
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_S:
				title = false;
				break;
			}
		}
	}
	//End intro loop

	//Begin game loop
	while (!done){
		al_play_sample(level1IntroSound, .5, 0.0, 1.5, ALLEGRO_PLAYMODE_ONCE, NULL);
		level2 mylevel2(HEIGHT, WIDTH);
		player myPlayer(HEIGHT, WIDTH);

		//Begin level 1 intro
		while ((!intro1) && (!done) && (!loss))
		{
			//Draws the intro text
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);

			al_draw_bitmap(level1Intro, 0, 0, 0);
			al_flip_display();

			if (ev.type == ALLEGRO_EVENT_TIMER)
			{
				redraw = true;
				if (keys[UP]){								//If left is pressed start easy game.
					intro1 = true;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				intro1 = true;
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_S:
					intro1 = true;
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_UP)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;

				case ALLEGRO_KEY_S:
					intro1 = false;
					break;
				}
			}
		}
		//End intro loop

		//Begin game loop
		while ((!doneLevel1) && (!done) && (!loss))
		{
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);

			if (ev.type == ALLEGRO_EVENT_TIMER)
			{
				redraw = true;
				fpsTimer--;
				if (keys[LEFT])
					myPlayer.MoveLeft();
				if (keys[RIGHT])
					myPlayer.MoveRight();
				if (keys[SPACE]){
					for (int i = 0; i < NUM_bulletS; i++)
						bullets[i].Firebullet(myPlayer);
				}
				for (int i = 0; i < NUM_bulletS; i++)
					bullets[i].Updatebullet(HEIGHT, myPlayer);
				for (int i = 0; i < NUM_enemyS; i++){									//Draw number of enemies based on their limit.
					enemys[i].Startenemy(WIDTH, HEIGHT);
				}
				for (int i = 0; i < NUM_enemyS; i++){
					enemys[i].Updateenemy();
				}
				for (int i = 0; i < NUM_bulletS; i++){
					bullets[i].Collidebullet(enemys, NUM_enemyS, myPlayer);
				}
				for (int i = 0; i < NUM_enemyS; i++)
					enemys[i].Collideenemy(myPlayer);
			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				done = true;
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = true;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE] = true;
					for (int i = 0; i < NUM_bulletS; i++)
						bullets[i].Firebullet(myPlayer);
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_UP)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = false;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE] = false;
					break;
				}
			}

			if (redraw && al_is_event_queue_empty(event_queue))			//update game 
			{
				redraw = false;

				al_draw_bitmap(background, 0, 0, 0);					//update environment
				//al_draw_bitmap(base, 0, 0, 0);

				myPlayer.DrawPlayer();									//update ship
				for (int i = 0; i < NUM_bulletS; i++)
					bullets[i].Drawbullet();							//update bullets
				for (int i = 0; i < NUM_enemyS; i++)
					enemys[i].Drawenemy();								//update enemies

				//Update screen text
				al_draw_textf(fontTop, al_map_rgb(255, 0, 0), WIDTH * .75, 5, ALLEGRO_ALIGN_CENTRE, "Timer %i", countDown);
				al_draw_textf(fontTop, al_map_rgb(255, 0, 0), WIDTH * .05, 5, ALLEGRO_ALIGN_LEFT, "High Score %i", highScore);

				al_draw_textf(fontScore, al_map_rgb(255, 0, 0), WIDTH / 2 - 10, HEIGHT - 30, ALLEGRO_ALIGN_RIGHT, "LIVES  %i", lives);
				al_draw_textf(fontScore, al_map_rgb(255, 0, 0), WIDTH / 2 + 10, HEIGHT - 30, ALLEGRO_ALIGN_LEFT, "SCORE %i", score);


				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
			//get methods for score and lives
			score = myPlayer.getScore();
			lives = myPlayer.getLives();
			if (fpsTimer % 60 == 0){
				countDown--;
			}
			//End the game if the lives reaches 0
			if (lives <= 0){
				loss = true;
			}
			if (countDown <= 0){
				doneLevel1 = true;
			}
		}
		//End level 1 loop

		//Begin level 2 Intro
		while ((!intro2) && (!done) && (!loss))
		{
			keys[LEFT] = false;
			keys[RIGHT] = false;

			//Draws the intro text
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);

			al_draw_bitmap(level2Intro, 0, 0, 0);
			al_flip_display();

			if (ev.type == ALLEGRO_EVENT_TIMER)
			{
				redraw = true;
				if (keys[UP]){								//If left is pressed start easy game.
					intro2 = true;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				intro2 = true;
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_S:
					intro2 = true;
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_UP)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;

				case ALLEGRO_KEY_S:
					intro2 = false;
					break;
				}
			}
			countDown = 30;
			doneLevel2 = false;
		}
		//End intro loop

		//Begin level 2 loop
		while ((!doneLevel2) && (!done) && (!loss))
		{
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);

			if (ev.type == ALLEGRO_EVENT_TIMER)
			{
				redraw = true;
				fpsTimer--;
				if (keys[LEFT])
					mylevel2.MoveLeft();
				if (keys[RIGHT])
					mylevel2.MoveRight();
				if (keys[SPACE]){
					for (int i = 0; i < NUM_bulletS; i++)
						bullets2[i].Firebullet2(mylevel2);
				}
				for (int i = 0; i < NUM_bulletS; i++)
					bullets2[i].Updatebullet2(HEIGHT, mylevel2);
				for (int i = 0; i < NUM_enemyS; i++){									//Draw number of enemies based on their limit.
					enemys2[i].Startenemy(WIDTH, HEIGHT);
				}
				for (int i = 0; i < NUM_stars; i++){									//Draw number of enemies based on their limit.
					stars[i].Startstar(WIDTH, HEIGHT);
				}
				for (int i = 0; i < NUM_enemyS; i++){
					enemys2[i].Updateenemy();
				}
				for (int i = 0; i < NUM_stars; i++){
					stars[i].UpdateStars();
				}
				for (int i = 0; i < NUM_bulletS; i++){
					bullets2[i].Collidebullet2(enemys2, NUM_enemyS, mylevel2);
				}
				for (int i = 0; i < NUM_enemyS; i++)
					enemys2[i].Collideenemy(mylevel2);
				for (int i = 0; i < NUM_stars; i++)
					stars[i].Collidestar(mylevel2);
			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				done = true;
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = true;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE] = true;
					for (int i = 0; i < NUM_bulletS; i++)
						bullets2[i].Firebullet2(mylevel2);
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_UP)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = false;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE] = false;
					break;
				}
			}

			if (redraw && al_is_event_queue_empty(event_queue))			//update game 
			{
				redraw = false;

				for (int i = 0; i < NUM_stars; i++)
					stars[i].Drawstar();
				mylevel2.Drawlevel2();									//up[date ship
				for (int i = 0; i < NUM_bulletS; i++)
					bullets2[i].Drawbullet2();							//update bullets
				for (int i = 0; i < NUM_enemyS; i++)
					enemys2[i].Drawenemy();								//update enemies

				al_draw_textf(fontTop, al_map_rgb(255, 0, 0), WIDTH * .75, 5, ALLEGRO_ALIGN_CENTRE, "Timer %i", countDown);
				al_draw_textf(fontTop, al_map_rgb(255, 0, 0), WIDTH * .05, 5, ALLEGRO_ALIGN_LEFT, "High Score %i", highScore);

				al_draw_textf(fontScore, al_map_rgb(255, 0, 0), WIDTH / 2 - 10, HEIGHT - 30, ALLEGRO_ALIGN_RIGHT, "LIVES  %i", lives);
				al_draw_textf(fontScore, al_map_rgb(255, 0, 0), WIDTH / 2 + 10, HEIGHT - 30, ALLEGRO_ALIGN_LEFT, "SCORE %i", score);

				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
			//get methods for score and lives
			score = mylevel2.getScore() + myPlayer.getScore();;
			lives = mylevel2.getLives();
			if (fpsTimer % 60 == 0){
				countDown--;
			}
			//End the game if the lives reaches 0
			if (lives <= 0){
				loss = true;
			}
			if (countDown <= 0){
				doneLevel2 = true;
			}
		}
		//End level 2 loop


		//Begin level 4 intro
		while ((!intro4) && (!done) && (!loss))
		{
			//Draws the intro text
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);

			al_draw_bitmap(level4Intro, 0, 0, 0);
			al_flip_display();

			if (ev.type == ALLEGRO_EVENT_TIMER)
			{
				redraw = true;
				if (keys[UP]){								//If left is pressed start easy game.
					intro4 = true;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				intro4 = true;
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_S:
					intro4 = true;
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_UP)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;

				case ALLEGRO_KEY_S:
					intro4 = false;
					break;
				}
			}
		}
		//End intro loop


		//initialize level 4 map
		if (MapLoad("level4.fmp", 1))
			return -5;

		//Begin level4 loop
		while ((!doneLevel4) && (!done) && (!loss))
		{
			int WIDTH = 700;
			int HEIGHT = 700;
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);
			if (ev.type == ALLEGRO_EVENT_TIMER)
			{
				MapUpdateAnims();	//update animations
				render = true;
				if (keys[UP])
					;
				else if (keys[DOWN])
					;
				else if (keys[LEFT])
					player4.UpdateSprites4(WIDTH, HEIGHT, 0);
				else if (keys[RIGHT])
					player4.UpdateSprites4(WIDTH, HEIGHT, 1);
				else if (keys[SPACE])
					player4.UpdateSprites4(WIDTH, HEIGHT, 3);
				else
					player4.UpdateSprites4(WIDTH, HEIGHT, 2);
				if (player4.CollisionEndBlock())
					doneLevel4 = true;

				//If the ending tile is landed on end the game loop.
				if (player4.CollisionEndGame()){
					loss = true;					
					al_flip_display();
				}
				render = true;

			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				done = true;
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_UP:
					keys[UP] = true;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[DOWN] = true;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = true;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE] = true;
					jump = 30;
					player4.setJumpFrame();									//set jump frame
				}
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_UP)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_UP:
					keys[UP] = false;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[DOWN] = false;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = false;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE] = false;
					break;
				}
			}
			if (render && al_is_event_queue_empty(event_queue))
			{
				render = false;

				//update the map scroll position
				xOff = player4.getX() + player4.getWidth() - WIDTH / 2;
				yOff = player4.getY() + player4.getHeight() - HEIGHT / 2;

				//avoid moving beyond the map edge
				if (xOff < 0) xOff = 0;

				if (xOff >(mapwidth * mapblockwidth - WIDTH))
					xOff = mapwidth * mapblockwidth - WIDTH;
				if (yOff < 0)
					yOff = 0;
				if (yOff >(mapheight * mapblockheight - HEIGHT))
					yOff = mapheight * mapblockheight - HEIGHT;

				//draw the background tiles
				MapDrawBG(xOff, yOff, 0, 0, WIDTH, HEIGHT);

				//draw foreground tiles
				MapDrawFG(xOff, yOff, 0, 0, WIDTH, HEIGHT, 0);
				jump = player4.jumping(jump, JUMPIT);
				player4.DrawSprites4(xOff, yOff);
				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
		}
		//End level 4 loop

		//Initialize level 5 map;
		if (MapLoad("trenchRun.fmp", 1))
			return -5;

		//Begin level5 Intro
		while ((!intro5) && (!done) && (!loss))
		{
			keys[LEFT] = false;
			keys[RIGHT] = false;
			//Draws the intro text
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);

			al_draw_bitmap(level5Intro, 0, 0, 0);
			al_flip_display();

			if (ev.type == ALLEGRO_EVENT_TIMER)
			{
				redraw = true;
				if (keys[UP]){								//If left is pressed start easy game.
					intro5 = true;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				intro5 = true;
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_S:
					intro5 = true;
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_UP)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;

				case ALLEGRO_KEY_S:
					intro5 = false;
					break;
				}
			}
		}
		//End intro loop
		
		
		int WIDTH = 448;
		int HEIGHT = 700;
		int xOff = 0;
		int yOff = 0;


		//Begin level 5 loop
		if ((!doneLevel5) && (!done) && (!loss)){

			event_queue = al_create_event_queue();
			timer = al_create_timer(1.0 / 60);
			al_register_event_source(event_queue, al_get_timer_event_source(timer));
			al_register_event_source(event_queue, al_get_keyboard_event_source());

			al_start_timer(timer);
			//draw the background tiles
			MapDrawBG(xOff, yOff, 0, 0, WIDTH - 1, HEIGHT - 1);

			//draw foreground tiles
			MapDrawFG(xOff, yOff, 0, 0, WIDTH - 1, HEIGHT - 1, 0);
			player5.DrawSprites(0, 0);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
		while ((!doneLevel5) && (!done) && (!loss))
		{
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);
			if (ev.type == ALLEGRO_EVENT_TIMER)
			{
				MapUpdateAnims();	//update animations
				render = true;
				if (keys[LEFT])
					player5.UpdateSprites(WIDTH, HEIGHT, 0);
				else if (keys[RIGHT])
					player5.UpdateSprites(WIDTH, HEIGHT, 1);
				else
					player5.UpdateSprites(WIDTH, HEIGHT, 2);
				if (player5.CollisionEndBlock()){
					MapDrawFG(xOff, yOff, 0, 0, WIDTH, HEIGHT, 0);
					player5.DrawSprites(xOff, yOff);
					al_flip_display();
					loss = true;
					doneLevel5 = true;
				}
				//If the ending tile is landed on end the game loop.

				if (player5.CollisionEndGame()){
					//cout << "DEAD";
					MapDrawFG(xOff, yOff, 0, 0, WIDTH, HEIGHT, 0);
					player5.DrawSprites(xOff, yOff);
					al_flip_display();
					doneLevel5 = true;
				}
				render = true;

			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				done = true;
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = true;
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_UP)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = false;
					break;
				}
			}
			if (render && al_is_event_queue_empty(event_queue))
			{
				render = false;

				//update the map scroll position
				xOff = player5.getX() + player5.getWidth() - WIDTH / 1.2;
				yOff = player5.getY() + player5.getHeight() - HEIGHT / 1.2;

				//avoid moving beyond the map edge
				if (xOff < 0) xOff = 0;

				if (xOff >(mapwidth * mapblockwidth - WIDTH))
					xOff = mapwidth * mapblockwidth - WIDTH;
				if (yOff < 0)
					yOff = 0;
				if (yOff >(mapheight * mapblockheight - HEIGHT))
					yOff = mapheight * mapblockheight - HEIGHT;

				//draw the background tiles
				MapDrawBG(xOff, yOff, 0, 0, WIDTH, HEIGHT);

				//draw foreground tiles
				MapDrawFG(xOff, yOff, 0, 0, WIDTH, HEIGHT, 0);
				player5.DrawSprites(xOff, yOff);
				al_draw_textf(fontScore, al_map_rgb(255, 0, 0), 20, 20, ALLEGRO_ALIGN_LEFT, "TIMER -%d", time);
				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
		}
		if (highScore <= score){
			highScore = score;
		}
		//End level 5

		//loss conditions
		if (loss){
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_text(fontScore, al_map_rgb(255, 0, 0), ENDWIDTH / 2, ENDHEIGHT / 2 - 140, ALLEGRO_ALIGN_CENTRE, "Dak has began to close his tired eyes.");
			al_draw_text(fontScore, al_map_rgb(255, 0, 0), ENDWIDTH / 2, ENDHEIGHT / 2 - 80, ALLEGRO_ALIGN_CENTRE, "His final thoughts are about");
			al_draw_text(fontScore, al_map_rgb(255, 0, 0), ENDWIDTH / 2, ENDHEIGHT / 2 - 40, ALLEGRO_ALIGN_CENTRE, "how he has failed the rebellion.");
			al_draw_textf(fontScore, al_map_rgb(255, 0, 0), ENDWIDTH / 2, ENDHEIGHT / 2 + 20, ALLEGRO_ALIGN_CENTRE, "HIS FINAL SCORE IS %i", score);
			al_flip_display();
			al_rest(10.0);
		}
		if ((!loss) && (!done)){
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(victoryBackground, 0, 0, 0);
			al_draw_textf(fontScore, al_map_rgb(255, 0, 0), ENDWIDTH / 2, ENDHEIGHT / 2 - 80, ALLEGRO_ALIGN_CENTRE, "HIS FINAL SCORE IS %i", score);
			al_flip_display();
			al_rest(10.0);
		}
		done = true;
	}
	al_destroy_font(fontTop);
	al_destroy_font(fontScore);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_display(display);						//destroy our display object

	return 0;

}
int collided(int x, int y)
{
	BLKSTR *blockdata;
	blockdata = MapGetBlock(x / mapblockwidth, y / mapblockheight);
	return blockdata->tl;
}

bool inTrench(int x, int y)
{

	BLKSTR* data;
	data = MapGetBlock(x / mapblockwidth, y / mapblockheight);

	if (data->user5 == 10)
	{
		return true;
	}
	else
		return false;
}

//The end game function that returns true if a tile with the value user2=4 is landed on. "YOU WIN"
bool endTrench(int x, int y)
{
	BLKSTR* data;
	data = MapGetBlock(x / mapblockwidth, y / mapblockheight);

	if (data->user5 == 5)
	{
		return true;
	}
	else
		return false;
}

int collided4(int x, int y)
{
	BLKSTR *blockdata;
	blockdata = MapGetBlock(x / mapblockwidth, y / mapblockheight);
	return blockdata->tl;
}

bool inMap(int x, int y)
{

	BLKSTR* data;
	data = MapGetBlock(x / mapblockwidth, y / mapblockheight);

	if (data->user4 == 4)
	{
		return true;
	}
	else
		return false;
}

//The end game function that returns true if a tile with the value user2=4 is landed on. "YOU WIN"
bool endMap(int x, int y)
{
	BLKSTR* data;
	data = MapGetBlock(x / mapblockwidth, y / mapblockheight);

	if (data->user4 == 9)
	{
		return true;
	}
	else
		return false;
}