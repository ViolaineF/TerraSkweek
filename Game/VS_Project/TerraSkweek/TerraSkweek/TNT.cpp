#include "TNT.h"


TNT::TNT()
{
	activated = false;
	exploded = false;
	endTNT = false;
	frameActuelle = 0;
}

TNT::TNT(int a, int b, bool c)
{
	m_posSprite.x = a;
	m_posSprite.y = b;
	m_posSprite.z = c;
	activated = false;
	exploded = false;
	endTNT = false;
	frameActuelle = 0;
}


	/*
	//______________________ TNT_01

		int tx = tntBox_01.checkpositionX(), ty = tntBox_01.checkpositionY();

		if ((tx == cx) && (ty == cy))
		{
			tntBox_01.activation();
			if (a1==false) 
			{
				Sfx_TNT.PlayMySound();
				a1 = true;
			}	
		}
		bool explosion1 = tntBox_01.checkExp();
		if (explosion1)
		{
			if (((cx > tx + 1) || (cx < tx - 1)) && ((cy > ty + 1) || (cy < ty - 1)))
			{
				explosion1 = false;
			}
			else if (((cx == tx + 1) && ((cy == ty + 1)))
				|| ((cx == tx + 1) && (cy == ty))
				|| ((cx == tx + 1) && (cy == ty - 1))
				|| ((cx == tx) && (cy == ty + 1))
				|| ((cx == tx) && (cy == ty))
				|| ((cx == tx) && (cy == ty - 1))
				|| ((cx == tx - 1) && (cy == ty + 1))
				|| ((cx == tx - 1) && (cy == ty))
				|| ((cx == tx - 1) && (cy == ty - 1))) 
			{
				crashB.mort();
				crashB.Teleport(11, 14);
			}
		}
}
*/

void TNT::LoadAllTextures()
{
	LoadGLTextures("tnt", "2corrupted/river_01.jpg");
	LoadGLTextures("tnt", "converted_river_01.jpg");
	LoadGLTextures("tnt", "TNT_01.png");
	LoadGLTextures("tnt", "TNT_01.png");
	LoadGLTextures("tnt", "TNT_01.png");
}


void TNT::Draw()
{

	if (activated && exploded == false && endTNT == false)
	{
		DrawSprite(m_posSprite);
		const int vitesse = 3700;
		frameActuelle = (frameActuelle + 1) % vitesse;
		int frame = frameActuelle * 4 / vitesse;

		if (frame < 3)
		{
			glPushMatrix();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, tnt[4 - frame]);
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
			exploded = true;
		}
	}
	else if (activated == false && exploded == false && endTNT == false)
	{
		glPushMatrix();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, tnt[0]);
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
	else if (activated && exploded && endTNT == false)
	{
		const int vitesse = 700;
		frameActuelle = (frameActuelle + 1) % vitesse;
		int frame = frameActuelle * 5 / vitesse;

		if (frame < 4)
		{
			glPushMatrix();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D, tnt[0 + frame]);
			glBegin(GL_QUADS);
			glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
			glVertex2d(m_posSprite.x - 1, m_posSprite.y - 1); glTexCoord2f(1.0f, 1.0f);
			glVertex2d(m_posSprite.x + 2, m_posSprite.y - 1); glTexCoord2f(1.0f, 0.0f);
			glVertex2d(m_posSprite.x + 2, m_posSprite.y + 2);	glTexCoord2f(0.0f, 0.0f);
			glVertex2d(m_posSprite.x - 1, m_posSprite.y + 2);	glEnd();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
			glutPostRedisplay();
		}
		else
		{
			activated = false;
			exploded = false;
			endTNT = true;
		}
	}
	else
	{
		glPushMatrix();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, tnt[4]);
		glBegin(GL_QUADS);
		glColor3d(1.0, 1.0, 1.0); glTexCoord2f(0.0f, 1.0f);
		glVertex2d(m_posSprite.x - 1, m_posSprite.y - 1); glTexCoord2f(1.0f, 1.0f);
		glVertex2d(m_posSprite.x + 2, m_posSprite.y - 1); glTexCoord2f(1.0f, 0.0f);
		glVertex2d(m_posSprite.x + 2, m_posSprite.y + 2);	glTexCoord2f(0.0f, 0.0f);
		glVertex2d(m_posSprite.x - 1, m_posSprite.y + 2);	glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glutPostRedisplay();
		endTNT = true;
	}
}

bool TNT::checkExp()
{
	return exploded;
}
void TNT::activation()
{
	activated = true;
}
TNT::~TNT()
{
}
