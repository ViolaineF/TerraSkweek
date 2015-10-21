#include "Devourer_Corruption.h"



Devourer_Corruption::Devourer_Corruption()
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


Devourer_Corruption::~Devourer_Corruption()
{
}
