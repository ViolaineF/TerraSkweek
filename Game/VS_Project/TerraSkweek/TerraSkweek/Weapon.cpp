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

Weapon::Weapon(Position pos, bool dropped, int type)
{
	m_pos = pos; // Placed on the dropped position
	m_dir = 'l'; // facing left by default
	currentFrame = 0; // Weapon texture
	m_drop = 1;
	m_type = type;
	LoadAllTextures();
}

Weapon::Weapon(string emitter, char dir, Position pos)
{
	m_dir = dir;
	m_pos = pos;
	currentFrame = 0;
	m_impact = 0;
	m_drop = 0;

	if (emitter == "player") {
		m_damage = 1;
		m_speed = 0.1;
		m_type = 1;
		LoadAllTextures();
	}
}

void Weapon::MoveFire()
{
	if (!m_drop) { // Move only if it's not a dropped weapon nor an Arrow or TNT
		
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

}

//void Weapon::DrawSprite(Position drop)
//{
//	m_posSprite.x = drop.x;
//	m_posSprite.y = drop.y;
//	m_posSprite.z = drop.z;
//}

void Weapon::DrawFire()
{
	if (m_drop) { // Draw a weapon sprite

		glPushMatrix();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, fireAnimation[0]);
		glBegin(GL_QUADS);
		glColor3d(1.0, 1.0, 1.0);
		glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x, m_pos.y);
		glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x + 1, m_pos.y);
		glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x + 1, m_pos.y + 1);
		glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x, m_pos.y + 1);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glutPostRedisplay();

	}
	else { // Draw a fire sprite

		const int vitesse = 1200;
		currentFrame = (currentFrame + 1) % vitesse;
		int frame = currentFrame * (fireAnimation.size()) / vitesse;

		if (m_impact) {

			glPushMatrix();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, fireAnimation[frame]);
			glBegin(GL_QUADS);
			glColor3d(1.0, 1.0, 1.0);
			glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x, m_pos.y);
			glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x + 1, m_pos.y);
			glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x + 1, m_pos.y + 1);
			glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x, m_pos.y + 1);

			glEnd();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
			glutPostRedisplay();

			if (frame == (fireAnimation.size() - 1)) {
				m_destroy = true;
			}
		}
		else {

			glPushMatrix();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, fireAnimation[1]);
			glBegin(GL_QUADS);
			glColor3d(1.0, 1.0, 1.0);
			glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x, m_pos.y);
			glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x + 1, m_pos.y);
			glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x + 1, m_pos.y + 1);
			glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x, m_pos.y + 1);

			glEnd();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
			glutPostRedisplay();

		}

	}





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

void Weapon::LoadAllTextures()
{
	if (m_type == 1) {
		LoadGLTextures("fireAnimation", "Weapon_01.png"); // Weapon sprite
		LoadGLTextures("fireAnimation", "Bullet_01.png"); // Fire sprite
		LoadGLTextures("fireAnimation", "Bullet_01_impact_1.png"); // Fire on impact animation
		LoadGLTextures("fireAnimation", "Bullet_01_impact_2.png");
		LoadGLTextures("fireAnimation", "Bullet_01_impact_3.png");
		LoadGLTextures("fireAnimation", "Bullet_01_impact_4.png");

	}
	
}

int Weapon::LoadGLTextures(string type, string nameIncomplete)
{	
	string name = "Art/" + nameIncomplete;

	if (type == "fireAnimation")
	{
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		fireAnimation.push_back(essai); // Add to the texture vector
		if (fireAnimation.at(fireAnimation.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success

						   //	LoadGLTextures("gun", "Art/Weapon_01.png");

	}


	if(type == "gun")
	{ 
	GLuint essai = SOIL_load_OGL_texture
		(
			name.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
		);

	gun.push_back(essai); // Add to the texture vector
	if (gun.at(gun.size() - 1) == 0)
		return false;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	return true;       // Return Success

//	LoadGLTextures("gun", "Art/Weapon_01.png");

	}

	if (type == "freeze")
	{
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		freeze.push_back(essai); // Add to the texture vector
		if (freeze.at(freeze.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}

	if (type == "invincible")
	{
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		invincible.push_back(essai); // Add to the texture vector
		if (invincible.at(invincible.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}

	if (type == "tnt")
	{
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		tnt.push_back(essai); // Add to the texture vector
		if (tnt.at(tnt.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}
	if (type == "arrow")
	{
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		arrow.push_back(essai); // Add to the texture vector
		if (arrow.at(arrow.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}

}

int Weapon::GetType()
{
	return m_type;
}


void Weapon::SetType(int type)
{
	m_type = type;
}

void Weapon::SetImpact(bool a)
{
	m_impact = a;
}

bool Weapon::IsDestroyed()
{
	return m_destroy;
}

Weapon::~Weapon()
{
}
