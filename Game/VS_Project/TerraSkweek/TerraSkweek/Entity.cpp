#include "Entity.h"



Entity::Entity()
{
}

int Entity::LoadGLTextures(string type,string name)
{

	if (type == "idle") {
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		idle.push_back(essai); // Add to the texture vector

		if (idle.at(idle.size() - 1) == 0)
			return false;

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return true;       // Return Success

	}

}

void Entity::Draw()
{
	glPushMatrix();

	glBegin(GL_QUADS);

	glColor3d(0.0, 1.0, 1.0); glVertex2d(m_pos.x, m_pos.y);
	glColor3d(0.0, 0.0, 1.0); glVertex2d(m_pos.x + 1, m_pos.y);
	glColor3d(0.0, 0.0, 1.0); glVertex2d(m_pos.x + 1, m_pos.y + 1);
	glColor3d(0.0, 0.0, 1.0); glVertex2d(m_pos.x, m_pos.y + 1);

	glEnd();


	//// Left
	//glEnable(GL_TEXTURE_2D);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glBindTexture(GL_TEXTURE_2D, idle[0]);
	//glBegin(GL_QUADS);

	//glColor3d(1.0, 1.0, 1.0);
	//glTexCoord2f(1.0f, 1.0f);
	//glVertex2d(m_pos.x, m_pos.y);
	//glTexCoord2f(0.0f, 1.0f);
	//glVertex2d(m_pos.x + 1, m_pos.y);
	//glTexCoord2f(0.0f, 0.0f);
	//glVertex2d(m_pos.x + 1, m_pos.y + 1);
	//glTexCoord2f(1.0f, 0.0f);
	//glVertex2d(m_pos.x, m_pos.y + 1);

	//glEnd();
	//glDisable(GL_TEXTURE_2D);


	glPopMatrix();
	
}

void Entity::SwitchDir(int dir)
{
	m_dir = dir;
}

int Entity::GetDir()
{
	return m_dir;
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

Position Entity::GetPos()
{
	return m_pos;
}

void Entity::Attack()
{
}

void Entity::Death()
{
}

Entity::Entity(Position pos, int life , int def, int dir, Weapon weap, AudioFile hurt, AudioFile death)
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
