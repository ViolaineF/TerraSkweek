#include "Enemy.h"



Enemy::Enemy() : Entity()
{
	afraid = false;
}

int Enemy::LoadGLTextures(/*string type,*/string name)
{

	//if (type == "idle") {
	GLuint essai = SOIL_load_OGL_texture
		(
			name.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	idle.push_back(essai); // Add to the texture vector

	if (run.at(run.size() - 1) == 0)
		return false;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;       // Return Success

					   //}

}


void Enemy::Draw()
{


	static int frameActuelle = 0;
	const int vitesse = 1200;
	frameActuelle = (frameActuelle + 1) % vitesse;
	int frame = frameActuelle * 3 / vitesse;

	if (afraid == false)
	{
		glPushMatrix();

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, run[frame]);
		glBegin(GL_QUADS);
		glColor3d(1.0, 1.0, 1.0); glTexCoord2f(1.0f, 1.0f);
		glVertex2d(m_pos.x, m_pos.y); glTexCoord2f(0.0f, 1.0f);
		glVertex2d(m_pos.x + 1, m_pos.y); glTexCoord2f(0.0f, 0.0f);
		glVertex2d(m_pos.x + 1, m_pos.y + 1);	glTexCoord2f(1.0f, 0.0f);
		glVertex2d(m_pos.x, m_pos.y + 1);	glEnd();
		glDisable(GL_TEXTURE_2D);

		////////////////////////	Mettre tout sur le même calque	////////////////////////
		glPopMatrix();
		glutPostRedisplay();

	}
}


Enemy::~Enemy()
{
}

