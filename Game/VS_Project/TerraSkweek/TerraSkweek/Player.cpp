#include "Player.h"



Player::Player() : Entity()
{
	m_pos = { 4,4,0 };
	m_life = 10;
	m_def = 10;
	m_dir = 0.0;
	m_speed = 0.1;
}


Player::~Player()
{
}
