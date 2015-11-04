#include "Enemy.h"



Enemy::Enemy() : Entity()
{
	afraid = false;
	currentFrame = 0;
	m_speed = 0.1;
	m_damage = 1;
	m_randomIt = 4;
	run.resize(0);
	death.resize(0);
}

int Enemy::LoadGLTextures(string type,string directory)
{
	string name = "Art/" + directory;

	if (type == "run") {
	GLuint essai = SOIL_load_OGL_texture
		(
			name.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	run.push_back(essai); // Add to the texture vector

	if (run.at(run.size() - 1) == 0)
		return false;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;       // Return Success

	}

	if (type == "death") {
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		death.push_back(essai); // Add to the texture vector

		if (death.at(death.size() - 1) == 0)
			return false;

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return true;       // Return Success
	}

}


bool Enemy::Move(Position playerPos, float light)
{
	if (m_life <= 0) {
		return false;
	}


	int maxMoves = 20;

	if (light < 1) { // If the player is invisible, move randomly
		m_random = 1;
	}
	else { // Chase the player
		m_random = 0;
	}
	// RANDOM MOVE
	if (m_random) {
		if (m_randomIt == maxMoves) {// If the enemy must choose a new direction
			switch (rand() % 4)// Create a value between 0 and 3 (inclusive) & Use it to define m_dir (char)
			{
			case 0 : m_dir = 'u';
				break;
			case 1: m_dir = 'd';
				break;
			case 2: m_dir = 'r';
				break;
			case 3: m_dir = 'l';
				break;
			}
		}
		switch (m_dir)// Move accordingly
		{
		case 'u':// UP 
			MoveUp();
			break;
		case 'd':// DOWN
			MoveDown();
			break;
		case 'r':// RIGHT
			MoveRight();
			break;
		case 'l':// LEFT
			MoveLeft();
			break;
		}

		m_randomIt--; // Decrease the numbers of moves left in this direction

	}
	// CHASE PLAYER
	else  {

		int axisDir = 1;
		float margin = 0.2;
		// Difference accepted between the position of the enemy and the player, within wich it's supposed null

		float horizontalDiff = m_pos.x - playerPos.x;
		float verticalDiff = m_pos.y - playerPos.y;

		if (horizontalDiff >= -margin && horizontalDiff <= margin) {
			axisDir = 1;// Move vertically
		}
		else if (verticalDiff >= -margin && verticalDiff <= margin) {
			axisDir = 0;// Move horizontally
		}
		else {
			axisDir = rand() % 2; // Create a value between 0 and 1 (move horizontally or vertically)
		}

		switch (axisDir)
		{
		case 0:
			if (horizontalDiff > 0) {// Enemy is at the right of PacMan 
				MoveLeft();
			}
			else {
				MoveRight();
			}
			break;
		case 1:
			if (verticalDiff < 0) {// Enemy is at the top of PacMan 
				MoveDown();
			}
			else {
				MoveUp();
			}
			break;
		}
	}
	
	if (m_randomIt == 0) {
		m_randomIt = maxMoves; // Reset the iterator, the enemy will choose another direction on the next move
	}
	
	return true;

}

int Enemy::GetDamage()
{
	return m_damage;
}

void Enemy::LoadAllTextures()
{
}


void Enemy::Draw()
{
	const int speed = 1200;
	currentFrame = (currentFrame + 1) % speed;

	//-------------------- CHECK LIFE FIRST
	if (m_life <= 0) {

		int frame = currentFrame * (death.size()) / speed;

			glPushMatrix();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, death[frame]);
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

			if (frame == (death.size()-1)) { // If the death animation has entirely played itself, then dead is true;
				m_death = true;
			}

	}
	else if (afraid == false && !m_freeze)
	{
		int frame = currentFrame * (run.size()) / speed;

		glPushMatrix();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, run[frame]);
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
	else if (m_freeze) {

		int frame = currentFrame * (freeze.size()) / speed;

		glPushMatrix();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, freeze[frame]);
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

		if (frame == (freeze.size() - 1)) { // If the death animation has entirely played itself, then dead is true;
			m_freeze = false;
		}



	}

/*	if (afraid == false)
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
	}*/
}

Enemy::~Enemy()
{
	m_freeze = false;
}

