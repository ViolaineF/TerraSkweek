#include "Player.h"

extern std::vector<GLuint> texture;


void Player::LoadAllTextures()
{
	LoadGLTextures("idle", "Art/player/player_idle_01.png");
	LoadGLTextures("idle", "Art/player/player_idle_02.png");
	LoadGLTextures("idle", "Art/player/player_idle_03.png");
	LoadGLTextures("idle", "Art/player/player_idle_04.png");
	LoadGLTextures("left", "Art/player/player_left_01.png");
	LoadGLTextures("left", "Art/player/player_left_02.png");
	LoadGLTextures("left", "Art/player/player_left_03.png");
	LoadGLTextures("left", "Art/player/player_left_04.png");	
	LoadGLTextures("up", "Art/player/player_left_01.png");
	LoadGLTextures("up", "Art/player/player_left_02.png");
	LoadGLTextures("up", "Art/player/player_left_03.png");
	LoadGLTextures("up", "Art/player/player_left_04.png");
	LoadGLTextures("down", "Art/player/player_left_01.png");
	LoadGLTextures("down", "Art/player/player_left_02.png");
	LoadGLTextures("down", "Art/player/player_left_03.png");
	LoadGLTextures("down", "Art/player/player_left_04.png");
	LoadGLTextures("fire_idle", "Art/player/player_fire_01.png");
	LoadGLTextures("fire_idle", "Art/player/player_fire_02.png");
	LoadGLTextures("fire_idle", "Art/player/player_fire_03.png");
	LoadGLTextures("fire_idle", "Art/player/player_fire_04.png");
	LoadGLTextures("fire_left", "Art/player/player_fire_01.png");
	LoadGLTextures("fire_left", "Art/player/player_fire_02.png");
	LoadGLTextures("fire_left", "Art/player/player_fire_03.png");
	LoadGLTextures("fire_left", "Art/player/player_fire_04.png");
	LoadGLTextures("fire_up", "Art/player/player_fire_01.png");
	LoadGLTextures("fire_up", "Art/player/player_fire_02.png");
	LoadGLTextures("fire_up", "Art/player/player_fire_03.png");
	LoadGLTextures("fire_up", "Art/player/player_fire_04.png");
	LoadGLTextures("fire_down", "Art/player/player_fire_01.png");
	LoadGLTextures("fire_down", "Art/player/player_fire_02.png");
	LoadGLTextures("fire_down", "Art/player/player_fire_03.png");
	LoadGLTextures("fire_down", "Art/player/player_fire_04.png");

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

	if (type == "left") {
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		left.push_back(essai); // Add to the texture vector
		if (left.at(left.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}
	
	if (type == "up") {
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		up.push_back(essai); // Add to the texture vector
		if (up.at(up.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}
	
	if (type == "down") {
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		down.push_back(essai); // Add to the texture vector
		if (down.at(down.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}
	
	if (type == "fire_idle") {
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		fire_idle.push_back(essai); // Add to the texture vector
		if (fire_idle.at(fire_idle.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}

	if (type == "fire_left") {
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		fire_left.push_back(essai); // Add to the texture vector
		if (fire_left.at(fire_left.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}

	if (type == "fire_up") {
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		fire_up.push_back(essai); // Add to the texture vector
		if (fire_up.at(fire_up.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}

	if (type == "fire_down") {
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		fire_down.push_back(essai); // Add to the texture vector
		if (fire_down.at(fire_down.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}

}

void Player::Draw()
{
	//cout << m_life << endl;

	const int vitesse = 4000;
	currentFrame = (currentFrame + 1) % vitesse;
	int frame = currentFrame * 4 / vitesse;
	
	if (!m_firing)
	{
		if (m_life < 150 && m_life > 50)
		{
			switch (m_dir)
			{
			case 'i':
				glPushMatrix();
				// Left
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, idle[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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
				break;

			case 'l':
				glPushMatrix();
				// Left
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, left[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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
				break;


			case 'r':
				glPushMatrix();
				// right
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, left[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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
				break;

			case 'u':
				glPushMatrix();
				// up
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, up[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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
				break;

			case 'd':

				glPushMatrix();
				// down
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, down[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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
				break;
			}
		}
		if (m_life <= 50)
		{
			switch (m_dir)
				{

			case 'i':
				glPushMatrix();
				// Left
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, idle[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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
				break;

			case 'l':
				glPushMatrix();
				// Left
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, left[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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
				break;


			case 'r':
				glPushMatrix();
				// right
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, left[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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
				break;

			case 'u':
				glPushMatrix();
				// up
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, up[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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
				break;

			case 'd':

				glPushMatrix();
				// down
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, down[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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
				break;
			}
		}
	}

	else if (m_firing)
	{


		if ((m_life < 150 && m_life > 50))
		{
			switch (m_dir)
			{
			case 'i':
				glPushMatrix();
				// Left
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, fire_idle[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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

				if (frame >= fire_idle.size() - 1)
					m_firing = false;

				break;

			case 'l':
				glPushMatrix();
				// Left
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, fire_left[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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

				if (frame >= fire_left.size() - 1)
					m_firing = false;

				break;

			case 'r':
				glPushMatrix();
				// right
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, fire_left[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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

				if (frame >= fire_left.size() - 1)
					m_firing = false;

				break;

			case 'u':
				glPushMatrix();
				// up
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, fire_up[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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

				if (frame >= fire_up.size() - 1)
					m_firing = false;

				break;

			case 'd':

				glPushMatrix();
				// down
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, fire_down[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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
				
				if (frame >= fire_down.size() - 1)
					m_firing = false;

				break;

			}
		}
		if (m_life <= 50)
		{
			switch (m_dir)
				{

			case 'i':
				glPushMatrix();
				// Left
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, fire_idle[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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

				if (frame >= fire_idle.size() - 1)
					m_firing = false;

				break;

			case 'l':
				glPushMatrix();
				// Left
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, fire_left[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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

				if (frame >= fire_left.size() - 1)
					m_firing = false;

				break;

			case 'r':
				glPushMatrix();
				// right
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, fire_left[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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

				if (frame >= fire_left.size() - 1)
					m_firing = false;

				break;

			case 'u':
				glPushMatrix();
				// up
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, fire_up[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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
				if (frame >= fire_up.size() - 1)
					m_firing = false;

				break;

			case 'd':

				glPushMatrix();
				// down
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, fire_down[frame]);
				glBegin(GL_QUADS);
				glColor4d(1.0, 1.0, 1.0, opacity);
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

				if (frame >= fire_down.size() - 1)
					m_firing = false;

				break;
			}
		}
	}
	
}

void Player::SetMoving(bool a)
{
	m_moving = a;
}

bool Player::IsMoving()
{
	return m_moving;
}

Player::Player() : Entity()
{
	//m_name = name;

	m_pos = { 4,4,0 };
	m_life = 5;
	m_def = 10;
	m_dir = 'l';
	m_speed = 0.1;
	idle.resize(0);
	m_moving = 0;
	//LoadGLTextures( /*"idle",*/"Art/player.png");
}

void Player::setOpacity(float light)
{
	opacity = light/4;
}

Player::~Player()
{
}


