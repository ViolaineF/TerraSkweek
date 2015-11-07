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
	LoadGLTextures("left", "Slime_left_01.png");
	LoadGLTextures("left", "Slime_left_02.png");
	LoadGLTextures("left", "Slime_left_03.png");
	LoadGLTextures("left", "Slime_left_04.png");
	LoadGLTextures("left", "Slime_left_05.png");

	LoadGLTextures("right", "Slime_right_01.png");
	LoadGLTextures("right", "Slime_right_02.png");
	LoadGLTextures("right", "Slime_right_03.png");
	LoadGLTextures("right", "Slime_right_04.png");
	LoadGLTextures("right", "Slime_right_05.png");

	LoadGLTextures("up", "Slime_up_01.png");
	LoadGLTextures("up", "Slime_up_02.png");
	LoadGLTextures("up", "Slime_up_03.png");
	LoadGLTextures("up", "Slime_up_04.png");
	LoadGLTextures("up", "Slime_up_05.png");

	LoadGLTextures("down", "Slime_down_01.png");
	LoadGLTextures("down", "Slime_down_02.png");
	LoadGLTextures("down", "Slime_down_03.png");
	LoadGLTextures("down", "Slime_down_04.png");
	LoadGLTextures("down", "Slime_down_05.png");

	LoadGLTextures("death", "Slime_death_01.png");
	LoadGLTextures("death", "Slime_death_02.png");
	LoadGLTextures("death", "Slime_death_03.png");
	LoadGLTextures("death", "Slime_death_04.png");

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
