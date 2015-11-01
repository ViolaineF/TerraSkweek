#include "River.h"

River::River()
{
	activated = false;
	frameActuelle = 0;
}

River::River(int a, int b, bool c, char d ,char biomeChar)
{
	m_posSprite.x = a;
	m_posSprite.y = b;
	m_posSprite.z = c;
	direction = d;
	biome = biomeChar;
	activated = false;
	frameActuelle = 0;
}


void River::LoadAllTextures()
{
	switch (biome)
	{

	case '1':
		LoadGLTextures("river", "river_01.png");
		LoadGLTextures("river", "river_02.png");
		LoadGLTextures("river", "river_03.png");
		LoadGLTextures("river", "riverSplash_01.png");
		LoadGLTextures("river", "riverSplash_02.png");
		LoadGLTextures("river", "riverSplash_03.png");
		break;

	case '2':
		LoadGLTextures("river", "2corrupted/river_01.png");
		LoadGLTextures("river", "2corrupted/river_02.png");
		LoadGLTextures("river", "2corrupted/river_03.png");
		LoadGLTextures("river", "2corrupted/riverSplash_01.png");
		LoadGLTextures("river", "2corrupted/riverSplash_02.png");
		LoadGLTextures("river", "2corrupted/riverSplash_03.png");
		break;
	}
}



void River::Draw()
{
	if (direction == 'l')
	{
		if (activated)
		{
			DrawSprite(m_posSprite);
			const int vitesse = 600;
			frameActuelle = (frameActuelle + 1) % vitesse;
			int frame = frameActuelle * 3 / vitesse;

			if (frame < 3)
			{
				glPushMatrix();
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, river[frame + 3]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y + 1);	glEnd();
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				glutPostRedisplay();
			}
			else
			{
				frameActuelle = 0;
				activated = false;
			}
		}
		else
		{
			DrawSprite(m_posSprite);
			const int vitesse = 600;
			frameActuelle = (frameActuelle + 1) % vitesse;
			int frame = frameActuelle * 3 / vitesse;

			if (frame < 3)
			{
				glPushMatrix();
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, river[frame]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y + 1);	glEnd();
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				glutPostRedisplay();
			}
		}
	}

	if (direction == 'r')
	{
		if (activated)
		{
			DrawSprite(m_posSprite);
			const int vitesse = 600;
			frameActuelle = (frameActuelle + 1) % vitesse;
			int frame = frameActuelle * 3 / vitesse;

			if (frame < 3)
			{
				glPushMatrix();
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, river[frame + 3]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y + 1);	glEnd();
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				glutPostRedisplay();
			}
			else
			{
				frameActuelle = 0;
				activated = false;
			}
		}
		else
		{
			DrawSprite(m_posSprite);
			const int vitesse = 600;
			frameActuelle = (frameActuelle + 1) % vitesse;
			int frame = frameActuelle * 3 / vitesse;

			if (frame < 3)
			{
				glPushMatrix();
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, river[frame]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y + 1);	glEnd();
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				glutPostRedisplay();
			}
		}
	}

	if (direction == 'u')
	{
		if (activated)
		{
			DrawSprite(m_posSprite);
			const int vitesse = 600;
			frameActuelle = (frameActuelle + 1) % vitesse;
			int frame = frameActuelle * 3 / vitesse;

			if (frame < 3)
			{
				glPushMatrix();
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, river[frame + 3]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y + 1);	glEnd();
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				glutPostRedisplay();
			}
			else
			{
				frameActuelle = 0;
				activated = false;
			}
		}
		else
		{
			DrawSprite(m_posSprite);
			const int vitesse = 600;
			frameActuelle = (frameActuelle + 1) % vitesse;
			int frame = frameActuelle * 3 / vitesse;

			if (frame < 3)
			{
				glPushMatrix();
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, river[frame]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y + 1);	glEnd();
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				glutPostRedisplay();
			}
		}
	}

	if (direction == 'd')
	{
		if (activated)
		{
			DrawSprite(m_posSprite);
			const int vitesse = 600;
			frameActuelle = (frameActuelle + 1) % vitesse;
			int frame = frameActuelle * 3 / vitesse;

			if (frame < 3)
			{
				glPushMatrix();
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, river[frame + 3]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y + 1);	glEnd();
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				glutPostRedisplay();
			}
			else
			{
				frameActuelle = 0;
				activated = false;
			}
		}
		else
		{
			DrawSprite(m_posSprite);
			const int vitesse = 600;
			frameActuelle = (frameActuelle + 1) % vitesse;
			int frame = frameActuelle * 3 / vitesse;

			if (frame < 3)
			{
				glPushMatrix();
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, river[frame]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_posSprite.x + 1, m_posSprite.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_posSprite.x, m_posSprite.y + 1);	glEnd();
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				glutPostRedisplay();
			}
		}
	}

}

void River::activation()
{
	activated = true;
}

River::~River()
{
}
