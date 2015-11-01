#include "HUD.h"



HUD::HUD()
{
	if (Level == 1)
		LevelScore = 20;
	else if (Level == 1)
		LevelScore = 20;
	else if (Level == 2)
		LevelScore = 20;
	else if (Level == 3)
		LevelScore = 20;
	else if (Level == 4)
		LevelScore = 20;
}


void HUD::displayScore(int life, int weapon)
{
	if (life == 0)
	{
//		lose
//		onScreen = true;
//		screen = 7;
	}

//	if (LevelScore == 0 && Level == 0)
//	{
//		totalScore = totalScore + 50 * frag;
//		previousScore = totalScore;
//		totalScore = 0;
//		crashB.Teleport(11, 14);
//		Level++;
//		screen = 5;
//		onScreen = true;
//	}
//	else if (LevelScore == 0 && Level == 1)
//	{
//		totalScore = totalScore + previousScore + 50 * frag;
//		previousScore = totalScore;
//		totalScore = 0;
//		screen = 6;
//		onScreen = true;
//	}
//	if (onScreen)
//		ScreenManager();

//	else if (onScreen == false)
//	{
		//			CheckLife();
//	}


//______________________ Afficher SCORE : 0000

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, hudTex[10]);
	glBegin(GL_QUADS);
	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(1, 1);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(5, 1);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(5, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(1, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	int i = 0;
	int j = 0;

	scoreTab[0] = LevelScore;
	if (scoreTab[0] > 0)
	{
		scoreTab[1] ++;
		scoreTab[0] = 0;
		LevelScore = 9;
	}

	else if (scoreTab[1] < 0)
	{
		scoreTab[1] = 0;
		scoreTab[2]++;
		LevelScore = 9;
	}

	else if (scoreTab[2] > 0)
	{
		scoreTab[2] = 0;
		scoreTab[3] ++;
		LevelScore = 9;
	}

	for (i = 0; i < 4; i++)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, hudTex[scoreTab[i]]);
		glBegin(GL_QUADS);
		glColor3d(1.0, 1.0, 1.0);
		glTexCoord2f(0.0f, 0.0f); glVertex2d(8 - i, 1);
		glTexCoord2f(1.0f, 0.0f); glVertex2d(9 - i, 1);
		glTexCoord2f(1.0f, 1.0f); glVertex2d(9 - i, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex2d(8 - i, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	//______________________ Afficher LIFE : ...	

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, hudTex[11]);
	glBegin(GL_QUADS);
	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(12, 1);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(15, 1);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(15, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(12, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	for (i = 0; i < life; i++)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, hudTex[13]);
		glBegin(GL_QUADS);
		glColor3d(1.0, 1.0, 1.0);
		glTexCoord2f(0.0f, 0.0f); glVertex2d(15 + i, 1);
		glTexCoord2f(1.0f, 0.0f); glVertex2d(16 + i, 1);
		glTexCoord2f(1.0f, 1.0f); glVertex2d(16 + i, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex2d(15 + i, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);

	}
}

void HUD::LoadAllTextures()
{
	LoadGLTextures("HUD/S0.png");				//	0
	LoadGLTextures("HUD/S1.png");
	LoadGLTextures("HUD/S2.png");
	LoadGLTextures("HUD/S3.png");
	LoadGLTextures("HUD/S4.png");
	LoadGLTextures("HUD/S5.png");				//	5
	LoadGLTextures("HUD/S6.png");
	LoadGLTextures("HUD/S7.png");
	LoadGLTextures("HUD/S8.png");
	LoadGLTextures("HUD/S9.png");
	LoadGLTextures("HUD/Score.png");			//	10
	LoadGLTextures("HUD/Life.png");
	LoadGLTextures("HUD/weapon.png");
	LoadGLTextures("HUD/LifeIco.png");
}

int HUD::LoadGLTextures(std::string name)
{
	GLuint essai = SOIL_load_OGL_texture
		(
			name.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	hudTex.push_back(essai); // Add to the texture vector

	if (hudTex.at(hudTex.size() - 1) == 0)
		return false;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;       // Return Success
}
