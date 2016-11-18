#include "player.h"
#include "enemy.h"
#include "boss.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

class bullet
{
public:
	bullet();
	~bullet();
	void Drawbullet();
	void Firebullet(player &Player);
	void Updatebullet(int WIDTH, player &Player);
	void Collidebullet(enemy enemys[], int cSize, player &Player);
	void CollidebulletBoss(boss &bossS, player &Player);

private:
	int x;
	int y;
	int speed;
	float angle;
	int hits;
	bool live;
	ALLEGRO_BITMAP *image;
	ALLEGRO_BITMAP *BossImage;
	ALLEGRO_SAMPLE *tieExplode, *laserBlast;

};

