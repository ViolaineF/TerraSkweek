#include "DemonEye_Forest.h"



void DemonEye_Forest::LoadAllTextures()
{
	LoadGLTextures("left", "Eye_left_01.png");
	LoadGLTextures("left", "Eye_left_02.png");
	LoadGLTextures("left", "Eye_left_03.png");
	LoadGLTextures("left", "Eye_left_04.png");
	LoadGLTextures("left", "Eye_left_05.png");
	LoadGLTextures("left", "Eye_left_06.png");


	LoadGLTextures("right", "eye_right_01.png");
	LoadGLTextures("right", "eye_right_02.png");
	LoadGLTextures("right", "eye_right_03.png");
	LoadGLTextures("right", "eye_right_04.png");
	LoadGLTextures("right", "eye_right_05.png");
	LoadGLTextures("right", "eye_right_06.png");


	LoadGLTextures("up", "Eye_up_01.png");
	LoadGLTextures("up", "Eye_up_02.png");
	LoadGLTextures("up", "Eye_up_03.png");
	LoadGLTextures("up", "Eye_up_04.png");
	LoadGLTextures("up", "Eye_up_05.png");


	LoadGLTextures("down", "Eye_down_01.png");
	LoadGLTextures("down", "Eye_down_02.png");
	LoadGLTextures("down", "Eye_down_03.png");
	LoadGLTextures("down", "Eye_down_04.png");
	LoadGLTextures("down", "Eye_down_05.png");


	LoadGLTextures("death", "eye_death_01.png");
	LoadGLTextures("death", "eye_death_02.png");
	LoadGLTextures("death", "eye_death_03.png");
	LoadGLTextures("death", "eye_death_04.png");
	LoadGLTextures("death", "eye_death_05.png");
	LoadGLTextures("death", "eye_death_06.png");
	LoadGLTextures("death", "eye_death_07.png");
	LoadGLTextures("death", "eye_death_08.png");
	LoadGLTextures("death", "eye_death_09.png");

}

DemonEye_Forest::DemonEye_Forest(Position pos) : Enemy(pos)
{
	m_pos = pos;
	m_life = 1;
	m_def = 1;
	m_dir = 'd';
	LoadAllTextures();
}


DemonEye_Forest::~DemonEye_Forest()
{
}
