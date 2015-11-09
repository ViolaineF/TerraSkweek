#include "Bunny_Forest.h"



Bunny_Forest::Bunny_Forest()
{
	int random_spawn = rand() % 2;
	if (random_spawn == 0)
		m_pos = { 4,4,0 };
	if (random_spawn == 1)
		m_pos = { 5,5,0 };

	m_life = 1;
	m_def = 1;
	m_dir = 0.0;
}


Bunny_Forest::~Bunny_Forest()
{
}
