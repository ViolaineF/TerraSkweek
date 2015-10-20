#include "Entity.h"



Entity::Entity()
{
}

void Entity::Draw()
{
}

void Entity::SetLife()
{
}

void Entity::MoveLeft()
{
}

void Entity::MoveRight()
{
}

void Entity::MoveUp()
{
}

void Entity::MoveDown()
{
}

void Entity::Teleport(position a)
{
}

void Entity::GetPos()
{
}

void Entity::Attack()
{
}

void Entity::Death()
{
}

void Entity::DefineEntity(position pos, int life , int def, int dir, Weapon weap, AudioFile hurt, AudioFile death)
{
	m_pos = pos; 
	m_life = life;

	m_def = def;
	m_dir = dir;
	s_hurt = hurt;
	s_death = death;
	m_weapon = weap;

}



Entity::~Entity()
{
}
