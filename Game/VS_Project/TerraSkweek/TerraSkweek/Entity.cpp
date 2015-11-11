#include "Entity.h"



Entity::Entity()
{
	//	Fire = false;
	currentFrame = 0;
	m_death = false;
	m_spriteSize = 37.5;
}


void Entity::SwitchDir(char d)
{
	m_dir = d;
}

char Entity::GetDir()
{
	return m_dir;
}

int Entity::GetLife()
{
	return m_life;
}

int Entity::GetWeapon()
{
	return m_weapon.GetType();
}

bool Entity::IsDead()
{
	return m_death;
}

void Entity::SetLife(int x)
{
	m_life = x;
}

void Entity::MoveLeft()
{
	m_pos.x -= m_speed;
}

void Entity::MoveRight()
{
	m_pos.x += m_speed;
}

void Entity::MoveUp()
{
	m_pos.y -= m_speed;
}

void Entity::MoveDown()
{
	m_pos.y += m_speed;
}

void Entity::Teleport(Position a)
{
	m_pos = a;
}

void Entity::SetSpeed(float speed)
{
	m_speed = speed;
}

Position Entity::GetPos()
{
	return m_pos;
}

void Entity::Attack()
{
	m_firing = true;
	currentFrame = 0;
}

//void Entity::Death()
//{
//
//}

Entity::Entity(Position pos, int life , int def, char dir, Weapon weap, AudioFile hurt, AudioFile death)
{
	m_pos = pos; 
	m_life = life;

	m_def = def;
	m_dir = dir;
	//s_hurt = hurt;
	//s_death = death;
	//m_weapon = weap;

}



Entity::~Entity()
{
}
