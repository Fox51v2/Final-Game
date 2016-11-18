#include "level2.h"
#include "enemy2.h"
#include "boss.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

class bullet2
{
public:
	bullet2();
	~bullet2();
	void Drawbullet2();
	void Firebullet2(level2 &level2);
	void Updatebullet2(int WIDTH, level2 &level2);
	void Collidebullet2(enemy2 enemys[], int cSize, level2 &level2);
	void CollidebulletBoss2(boss &bossS, level2 &level2);

private:
	int x2;
	int y2;
	int speed2;
	float angle2;
	int hits2;
	bool live2;
	ALLEGRO_BITMAP *image2;
	ALLEGRO_BITMAP *BossImage2;
	ALLEGRO_SAMPLE *tieExplode, *laserBlast;

};

