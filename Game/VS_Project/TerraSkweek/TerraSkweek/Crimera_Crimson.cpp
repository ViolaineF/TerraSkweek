#include "Crimera_Crimson.h"



Crimera_Crimson::Crimera_Crimson()
{
	int random_direction = rand() % 2;
	if (random_direction == 0)
		m_pos = { 4,4,0 };
	if (random_direction == 1)
		m_pos = { 5,5,0 };

	m_life = 1;
	m_def = 1;
	m_dir = 0.0;
	m_speed = 0.1;
}


Crimera_Crimson::~Crimera_Crimson()
{
}
