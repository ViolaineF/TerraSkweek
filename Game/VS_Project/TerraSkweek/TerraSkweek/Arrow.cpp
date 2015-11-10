#include "Arrow.h"

Arrow::Arrow()
{
	activated = false;
}

Arrow::Arrow(float a, float b, bool c, char d)
{
	m_pos = { a, b, c };
	m_drop = true; // Because it's not moving nor animated
	direction = d;
	activated = false;
	m_middle = 0.34;
	LoadAllTextures();
}


void Arrow::LoadAllTextures()
{
	LoadGLTextures("arrow", "arrow_01.png");
	LoadGLTextures("arrow", "arrow_active_01.png");
}


void Arrow::Draw()
{
	if (direction == 'l')
	{
		if (activated)
		{
			glPushMatrix();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, arrow[1]);
			glBegin(GL_QUADS);
			glColor3d(1.0, 1.0, 1.0);
			glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
			glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x + 2*m_middle, m_pos.y - m_middle);
			glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x + 2 * m_middle, m_pos.y + 2 * m_middle);
			glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y + 2 * m_middle);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
			glutPostRedisplay();

		}
		else
		{			
			glPushMatrix();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, arrow[0]);
			glBegin(GL_QUADS);
			glColor3d(1.0, 1.0, 1.0);
			glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle);
			glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x + 2 * m_middle, m_pos.y - m_middle);
			glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x + 2 * m_middle, m_pos.y + 2 * m_middle);
			glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x - m_middle, m_pos.y + 2 * m_middle);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
			glutPostRedisplay();
		}
	}

	if (direction == 'r')
	{
		if (activated)
		{
			glPushMatrix();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, arrow[1]);
			glBegin(GL_QUADS);
			glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
			glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle); glTexCoord2f(1.0f, 1.0f);
			glVertex2d(m_pos.x + 2 * m_middle, m_pos.y - m_middle);
			glTexCoord2f(1.0f, 0.0f);
			glVertex2d(m_pos.x + 2 * m_middle, m_pos.y + 2 * m_middle);
			glTexCoord2f(0.0f, 0.0f);
			glVertex2d(m_pos.x - m_middle, m_pos.y + 2 * m_middle);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
			glutPostRedisplay();
		}
		else
		{
			glPushMatrix();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, arrow[0]);
			glBegin(GL_QUADS);
			glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
			glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle); glTexCoord2f(1.0f, 1.0f);
			glVertex2d(m_pos.x + 2 * m_middle, m_pos.y - m_middle); glTexCoord2f(1.0f, 0.0f);
			glVertex2d(m_pos.x + 2 * m_middle, m_pos.y + 2 * m_middle);
			glTexCoord2f(0.0f, 0.0f);
			glVertex2d(m_pos.x - m_middle, m_pos.y + 2 * m_middle);	glEnd();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
			glutPostRedisplay();

		}
	}

	if (direction == 'u')
	{
		if (activated)
		{
			glPushMatrix();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, arrow[1]);
			glBegin(GL_QUADS);
			glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
			glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle); glTexCoord2f(1.0f, 1.0f);
			glVertex2d(m_pos.x + 2 * m_middle, m_pos.y - m_middle); glTexCoord2f(1.0f, 0.0f);
			glVertex2d(m_pos.x + 2 * m_middle, m_pos.y + 2 * m_middle);
			glTexCoord2f(0.0f, 0.0f);
			glVertex2d(m_pos.x - m_middle, m_pos.y + 2 * m_middle);	glEnd();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
			glutPostRedisplay();

		}
		else
		{
			glPushMatrix();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, arrow[0]);
			glBegin(GL_QUADS);
			glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
			glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle); glTexCoord2f(1.0f, 1.0f);
			glVertex2d(m_pos.x + 2 * m_middle, m_pos.y - m_middle); glTexCoord2f(1.0f, 0.0f);
			glVertex2d(m_pos.x + 2 * m_middle, m_pos.y + 2 * m_middle);
			glTexCoord2f(0.0f, 0.0f);
			glVertex2d(m_pos.x - m_middle, m_pos.y + 2 * m_middle);	glEnd();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
			glutPostRedisplay();
		}
	}

	if (direction == 'd')
	{
		if (activated)
		{
				glPushMatrix();
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, arrow[1]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_pos.x + 2 * m_middle, m_pos.y - m_middle); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_pos.x + 2 * m_middle, m_pos.y + 2 * m_middle);
				glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_pos.x - m_middle, m_pos.y + 2 * m_middle);	glEnd();
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				glutPostRedisplay();

		}
		else
		{
				glPushMatrix();
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, arrow[0]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
				glVertex2d(m_pos.x - m_middle, m_pos.y - m_middle); glTexCoord2f(1.0f, 1.0f);
				glVertex2d(m_pos.x + 2 * m_middle, m_pos.y - m_middle); glTexCoord2f(1.0f, 0.0f);
				glVertex2d(m_pos.x + 2 * m_middle, m_pos.y + 2 * m_middle);
				glTexCoord2f(0.0f, 0.0f);
				glVertex2d(m_pos.x - m_middle, m_pos.y + 2 * m_middle);	glEnd();
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				glutPostRedisplay();
	
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
