#include "Player.h"

extern std::vector<GLuint> texture;


void Player::LoadAllTextures()
{
	LoadGLTextures("idle","Art/player.png");
}

int Player::LoadGLTextures(string type,string name)
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

void Player::Draw()
{
	glPushMatrix();

	// Left
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, idle[0]);
	glBegin(GL_QUADS);

	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2d(m_pos.x, m_pos.y);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2d(m_pos.x + 1, m_pos.y);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2d(m_pos.x + 1, m_pos.y + 1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2d(m_pos.x, m_pos.y + 1);

	glEnd();
	glDisable(GL_TEXTURE_2D);


	glPopMatrix();
}

Player::Player() : Entity()
{
	m_pos = { 4,4,0 };
	m_life = 10;
	m_def = 10;
	m_dir = 'l';
	m_speed = 0.1;
	idle.resize(0);
	//LoadGLTextures( /*"idle",*/"Art/player.png");
}


Player::~Player()
{
}


