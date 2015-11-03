#include "Arrow.h"

Arrow::Arrow()
{
	activated = false;
	frameActuelle = 0;
}

Arrow::Arrow(float a, float b, bool c, char d)
{
	m_pos = { a, b, c };
	m_drop = true; // Because it's not moving nor animated
	direction = d;
	activated = false;
	frameActuelle = 0;
}


void Arrow::LoadAllTextures()
{
	LoadGLTextures("arrow", "arrow_01.png");
	LoadGLTextures("arrow", "arrow_02.png");
	LoadGLTextures("arrow", "arrow_03.png");
	LoadGLTextures("arrow", "arrow_active_01.png");
	LoadGLTextures("arrow", "arrow_active_02.png");
	LoadGLTextures("arrow", "arrow_active_03.png");
}



void Arrow::Draw()
{
	if (direction == 'l')
	{
		if (activated)
		{
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
				glBindTexture(GL_TEXTURE_2D, arrow[frame + 3]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_pos.x, m_pos.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_pos.x + 1, m_pos.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_pos.x + 1, m_pos.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_pos.x, m_pos.y + 1);	glEnd();
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
				glBindTexture(GL_TEXTURE_2D, arrow[frame]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_pos.x, m_pos.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_pos.x + 1, m_pos.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_pos.x + 1, m_pos.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_pos.x, m_pos.y + 1);	glEnd();
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
				glBindTexture(GL_TEXTURE_2D, arrow[frame + 3]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_pos.x, m_pos.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_pos.x + 1, m_pos.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_pos.x + 1, m_pos.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_pos.x, m_pos.y + 1);	glEnd();
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
				glBindTexture(GL_TEXTURE_2D, arrow[frame]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_pos.x, m_pos.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_pos.x + 1, m_pos.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_pos.x + 1, m_pos.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_pos.x, m_pos.y + 1);	glEnd();
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
				glBindTexture(GL_TEXTURE_2D, arrow[frame + 3]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_pos.x, m_pos.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_pos.x + 1, m_pos.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_pos.x + 1, m_pos.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_pos.x, m_pos.y + 1);	glEnd();
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
				glBindTexture(GL_TEXTURE_2D, arrow[frame]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_pos.x, m_pos.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_pos.x + 1, m_pos.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_pos.x + 1, m_pos.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_pos.x, m_pos.y + 1);	glEnd();
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
				glBindTexture(GL_TEXTURE_2D, arrow[frame + 3]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_pos.x, m_pos.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_pos.x + 1, m_pos.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_pos.x + 1, m_pos.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_pos.x, m_pos.y + 1);	glEnd();
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
				glBindTexture(GL_TEXTURE_2D, arrow[frame]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_pos.x, m_pos.y); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_pos.x + 1, m_pos.y); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_pos.x + 1, m_pos.y + 1);	glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_pos.x, m_pos.y + 1);	glEnd();
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				glutPostRedisplay();
			}
		}
	}

}

void Arrow::activation()
{
	activated = true;
}

Arrow::~Arrow()
{
}
