#include "Weapon.h"



bool operator==(const Position &a, const Position &b)
{
	//return (a.x == b.x && a.y==b.y && a.z==b.z);
	float margin = 0.2;
	return (a.x <= (b.x+margin) && a.x >= (b.x-margin) && a.y <= (b.y + margin) && a.y >= (b.y - margin) && a.z == b.z);

}
bool operator!=(const Position &a, const Position &b)
{
	return !(a==b);
}

Weapon::Weapon()
{
}

Weapon::Weapon(string emitter, char dir, Position pos)
{
	m_dir = dir;
	m_pos = pos;

	if (emitter == "player") {
		m_damage = 1;
		m_speed = 0.1;
		//LoadGlTextures("playerWeap");
	}

}

void Weapon::MoveFire()
{
	switch (m_dir)// Move accordingly
	{
	case 'u':// UP
		m_pos.y -= m_speed;
		break;
	case 'd':// DOWN
		m_pos.y += m_speed;
		break;
	case 'r':// RIGHT
		m_pos.x += m_speed;
		break;
	case 'l':// LEFT
		m_pos.x -= m_speed;
		break;
	}

}

void Weapon::DrawSprite(Position)
{

}

void Weapon::DrawFire()
{
	glPushMatrix();
	glBegin(GL_QUADS);

	glColor3d(0.0, 0.0, 0.0); glVertex2d(m_pos.x, m_pos.y);
	glColor3d(0.0, 0.0, 0.0); glVertex2d(m_pos.x + 1, m_pos.y);
	glColor3d(0.0, 0.0, 0.0); glVertex2d(m_pos.x + 1, m_pos.y + 1);
	glColor3d(0.0, 0.0, 0.0); glVertex2d(m_pos.x, m_pos.y + 1);

	glEnd();
	glPopMatrix();
	glutPostRedisplay();
}

Position Weapon::GetPos()
{
	return m_pos;
}

int Weapon::GetDamage()
{
	return m_damage;
}

char Weapon::GetDir()
{
	return m_dir;
}

int Weapon::LoadGLTextures(string name)
{
	//GLuint essai = SOIL_load_OGL_texture
	//	(
	//		name.c_str(),
	//		SOIL_LOAD_AUTO,
	//		SOIL_CREATE_NEW_ID,
	//		SOIL_FLAG_INVERT_Y
	//		);

	//textures.push_back(essai); // Add to the texture vector

	//if (textures.at(textures.size() - 1) == 0)
	//	return false;

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;       // Return Success
}


Weapon::~Weapon()
{
}
