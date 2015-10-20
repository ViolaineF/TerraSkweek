#include "Entity.h"



Entity::Entity()
{
}

int Entity::LoadGLTextures(string name)
{
	GLuint essai = SOIL_load_OGL_texture
		(
			name.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	textures.push_back(essai); // Add to the texture vector

	if (textures.at(textures.size() - 1) == 0)
		return false;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;       // Return Success
}

void Entity::Draw()
{
}

void Entity::SetLife()
{
	m_life = 3;
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
