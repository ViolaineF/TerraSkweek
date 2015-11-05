#include "Slime_Forest.h"


Slime_Forest::Slime_Forest(Position pos) : Enemy(pos)
{
	//int random_spawn = rand() % 2;
	//if (random_spawn == 0)
	//	m_pos = { 5,5,0 };
	//if (random_spawn == 1)
	//	m_pos = { 13,13,0 };

	m_pos = pos;
	m_life = 1;
	m_def = 1;
	m_dir = 'd';
	m_speed = 0.05;
	LoadAllTextures();
}


void Slime_Forest::LoadAllTextures()
{
	LoadGLTextures("run", "Slime_01.png");
	LoadGLTextures("run", "Slime_02.png");
	LoadGLTextures("run", "Slime_03.png");
	LoadGLTextures("run", "Slime_04.png");
	LoadGLTextures("run", "Slime_05.png");


	LoadGLTextures("death", "2corrupted/slimer_death_1.png");
	LoadGLTextures("death", "2corrupted/slimer_death_2.png");
	LoadGLTextures("death", "2corrupted/slimer_death_3.png");
	LoadGLTextures("death", "2corrupted/slimer_death_4.png");

	LoadGLTextures("freeze", "2corrupted/slimer_freeze_01.png");
	LoadGLTextures("freeze", "2corrupted/slimer_freeze_02.png");
	LoadGLTextures("freeze", "2corrupted/slimer_freeze_03.png");
	LoadGLTextures("freeze", "2corrupted/slimer_freeze_03.png");
	LoadGLTextures("freeze", "2corrupted/slimer_freeze_03.png");
	LoadGLTextures("freeze", "2corrupted/slimer_freeze_03.png");
	LoadGLTextures("freeze", "2corrupted/slimer_freeze_03.png");
	LoadGLTextures("freeze", "2corrupted/slimer_freeze_03.png");
	LoadGLTextures("freeze", "2corrupted/slimer_freeze_03.png");
	LoadGLTextures("freeze", "2corrupted/slimer_freeze_03.png");
	LoadGLTextures("freeze", "2corrupted/slimer_freeze_03.png");

}

Slime_Forest::~Slime_Forest()
{
}
