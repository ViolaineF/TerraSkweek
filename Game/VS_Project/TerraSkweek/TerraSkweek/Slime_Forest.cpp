#include "Slime_Forest.h"



Slime_Forest::Slime_Forest()
{
	int random_spawn = rand() % 2;
	if (random_spawn == 0)
		m_pos = { 4,4,0 };
	if (random_spawn == 1)
		m_pos = { 5,5,0 };

	m_life = 1;
	m_def = 1;
	m_dir = 0.0;
	m_speed = 0.1;
}


void Slime_Forest::LoadAllTextures()
{
	LoadGLTextures("run", "Art/Slime_01.png");
	LoadGLTextures("run", "Art/Slime_02.png");
	LoadGLTextures("run", "Art/Slime_03.png");
	LoadGLTextures("run", "Art/Slime_04.png");
	LoadGLTextures("run", "Art/Slime_05.png");
}

Slime_Forest::~Slime_Forest()
{
}
