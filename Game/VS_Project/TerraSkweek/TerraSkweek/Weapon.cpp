#include "Weapon.h"



bool operator==(const Position &a, const Position &b)
{
	//return (a.x == b.x && a.y==b.y && a.z==b.z);
	float margin = 0.4;
	return (a.x <= (b.x+margin) && a.x >= (b.x-margin) && a.y <= (b.y + margin) && a.y >= (b.y - margin) && a.z == b.z);

}
bool operator!=(const Position &a, const Position &b)
{
	return !(a==b);
}



Weapon::Weapon()
{
	m_pos = { 0.0,0.0,0 };
	m_dir = 'l';
	m_damage = 1;
	m_speed = 0.1;
	m_type = 1;
	currentFrame = 0;
	m_impact = false;
	m_drop = false;
	m_destroy = false;
	//s_fire;
	//s_impact;

	fireAnimation.resize(0);

	gun.resize(0);
	freeze.resize(0);
	invincible.resize(0);
	tnt.resize(0);
	arrow.resize(0);
}

Weapon::Weapon(Position pos, bool dropped, int type)
{
	m_pos = pos; // Placed on the dropped position
	m_dir = 'l'; // facing left by default
	currentFrame = 0; // Weapon texture
	m_drop = 1;
	m_type = type;
	m_destroy = false;
	m_middle = 0.15;
	LoadAllTextures();
}

Weapon::Weapon(int type, char dir, Position pos)
{
	m_dir = dir;
	m_pos = pos;

	m_middle = 0.15;

	currentFrame = 0;
	m_impact = 0;
	m_drop = 0;
	m_destroy = false;
	m_type = type;

	switch (type)
	{
	case 1 : // Simple Fire
		m_damage = 1;
		m_speed = 0.1;
		break;

	case 2: // Cross fire
		m_damage = 2;
		m_speed = 0.2;
		break;

	case 3: // Diag fire
		m_damage = 2;
		m_speed = 0.2;
		break;

	}

	LoadAllTextures();

}

bool Weapon::MoveFire()
{
	if (!m_drop && !m_impact) { // Move only if it's not a dropped weapon nor impacted nor an Arrow nor TNT
		
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
		case '1':// UP & RIGHT
			m_pos.y -= m_speed;
			m_pos.x += m_speed;
			break;
		case '2':// DOWN & RIGHT
			m_pos.y += m_speed;
			m_pos.x += m_speed;
			break;
		case '3':// DOWN & LEFT
			m_pos.y += m_speed;
			m_pos.x -= m_speed;
			break;
		case '4':// UP & LEFT
			m_pos.y -= m_speed;
			m_pos.x -= m_speed;
			break;
		}

		return true;
	}

	return false; // If not moving

}

void Weapon::DrawFire()
{
	if (m_drop && !m_impact) { // Draw a weapon sprite

		glPushMatrix();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, gun[0]);
		glBegin(GL_QUADS);
		glColor3d(1.0, 1.0, 1.0);
		glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x - 2*m_middle, m_pos.y - 2*m_middle);
		glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x + 4*m_middle, m_pos.y - 2*m_middle);
		glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x + 4*m_middle, m_pos.y + 4*m_middle);
		glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x - 2*m_middle, m_pos.y + 4*m_middle);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glutPostRedisplay();

	}
	else { // Draw a fire sprite
		
		const int vitesse = 200;
		currentFrame = (currentFrame + 1) % vitesse;
		int frame = currentFrame * (fireAnimation.size()) / vitesse;

		if (m_impact) { // Impact animation

			glPushMatrix();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, fireAnimation[frame]);
			glBegin(GL_QUADS);
			glColor3d(1.0, 1.0, 1.0);
			switch (m_dir)// Move accordingly
			{
			case 'u':// UP
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x + 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x + 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case 'd':// DOWN
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case 'r':// RIGHT
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case 'l':// LEFT
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case '1':// UP & RIGHT
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case '2':// DOWN & RIGHT
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case '3':// DOWN & LEFT
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case '4':// UP & LEFT
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			}


			glEnd();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
			glutPostRedisplay();

			if (frame == (fireAnimation.size() - 1)) {
				m_destroy = true;
			}
		}
		else { // Moving sprite

			glPushMatrix();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, fireAnimation[0]);
			glBegin(GL_QUADS);
			glColor3d(1.0, 1.0, 1.0);



			switch (m_dir)// Move accordingly
			{
			case 'u':// UP
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case 'd':// DOWN
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case 'r':// RIGHT
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case 'l':// LEFT
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case '1':// UP & RIGHT				
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case '2':// DOWN & RIGHT
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case '3':// DOWN & LEFT
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			case '4':// UP & LEFT
				glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y - m_middle);
				glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x+ 2*m_middle, m_pos.y+ 2*m_middle);
				glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y+ 2*m_middle);
				break;
			}


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
	switch (m_type)
	{
	case 1 :
		LoadGLTextures("gun", "Weapon_01.png"); // Weapon sprite
		LoadGLTextures("fireAnimation", "Bullet_01.png"); // Fire sprite
		LoadGLTextures("fireAnimation", "Bullet_01_impact_1.png"); // Fire on impact animation
		LoadGLTextures("fireAnimation", "Bullet_01_impact_2.png");
		LoadGLTextures("fireAnimation", "Bullet_01_impact_3.png");
		LoadGLTextures("fireAnimation", "Bullet_01_impact_4.png");

		break;

	case 2 :
		LoadGLTextures("gun", "Weapon_02.png"); // Weapon sprite
		LoadGLTextures("fireAnimation", "Bullet_02.png"); // Fire sprite
		LoadGLTextures("fireAnimation", "Bullet_02_impact_1.png"); // Fire on impact animation
		LoadGLTextures("fireAnimation", "Bullet_02_impact_2.png");
		LoadGLTextures("fireAnimation", "Bullet_02_impact_3.png");
		LoadGLTextures("fireAnimation", "Bullet_02_impact_4.png");
		
		break;

	case 3:
		LoadGLTextures("gun", "Weapon_03.png"); // Weapon sprite
		LoadGLTextures("fireAnimation", "Bullet_03.png"); // Fire sprite
		LoadGLTextures("fireAnimation", "Bullet_03_impact_1.png"); // Fire on impact animation
		LoadGLTextures("fireAnimation", "Bullet_03_impact_2.png");
		LoadGLTextures("fireAnimation", "Bullet_03_impact_3.png");
		LoadGLTextures("fireAnimation", "Bullet_03_impact_4.png");

		break;

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

void Weapon::SetCurrentFrame(int x)
{
	currentFrame = x;
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
