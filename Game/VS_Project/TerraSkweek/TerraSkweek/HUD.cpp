#include "HUD.h"



HUD::HUD()
{
	if (Level == 1)
	{
		LevelScore = 20;
		timer = 210;
	}
	else if (Level == 2)
	{
		LevelScore = 20;
		timer = 210;
	}
	else if (Level == 3)
	{
		LevelScore = 20;
		timer = 210;
	}
	else if (Level == 4)
	{
		LevelScore = 20;
		timer = 210;
	}
}



void HUD::PrintImg(int i, int j, int width, int height, vector<GLuint> vecTex ,int textureIt)
{
	glEnable(GL_TEXTURE_2D); // Start textures
	glBindTexture(GL_TEXTURE_2D, vecTex[textureIt]);
	glBegin(GL_QUADS);

	glColor4d(1.0, 1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(i, j);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(i + height, j);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(i + height, j + width);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j + width);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void HUD::PrintLife(int i, int j, int width, int height, int textureIt, float life)
{
	float sat = 1.0 / life;
	glEnable(GL_TEXTURE_2D); // Start textures
	glBindTexture(GL_TEXTURE_2D, icons[textureIt]);
	glBegin(GL_QUADS);

	glColor4d(sat, sat, sat, sat);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(i, j);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(i + height, j);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(i + height, j + width);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j + width);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void HUD::displayScore(float life, int weapon)
{

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


//Draw SCORE : 0000000

	PrintImg(1, 0, 1, 5, infos, 0);
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

	else if (scoreTab[3] > 0)
	{
		scoreTab[3] = 0;
		scoreTab[4] ++;
		LevelScore = 9;
	}

	else if (scoreTab[4] > 0)
	{
		scoreTab[4] = 0;
		scoreTab[5] ++;
		LevelScore = 9;
	}

	else if (scoreTab[5] > 0)
	{
		scoreTab[5] = 0;
		scoreTab[6] ++;
		LevelScore = 9;
	}

	else if (scoreTab[6] > 0)
	{
		scoreTab[6] = 0;
		scoreTab[7] ++;
		LevelScore = 9;
	}

	for (i = 0; i < 4; i++)
	{
		PrintImg(8 - i, 0, 1, 1, nbrs, 1);
	}

	//______________________ Afficher LIFE : ...	

	/**/
	PrintImg(14, 0, 1, 3, infos, 1);

	float val_life = life / 50;

	if (life == 150)
	{
		PrintLife(17, 0, 1, 1, 0, 1.0);
		PrintLife(18, 0, 1, 1, 0, 1.0);
		PrintLife(19, 0, 1, 1, 0, 1.0);
	}

	else if (life < 150 && life > 100)
	{
		PrintLife(17, 0, 1, 1, 0, 1.0);
		PrintLife(18, 0, 1, 1, 0, 1.0);
		PrintLife(19, 0, 1, 1, 0, val_life/3);
	}

	else if (life < 100 && life > 50)
	{
		PrintLife(17, 0, 1, 1, 0, 1.0);
		PrintLife(18, 0, 1, 1, 0, val_life / 2);
		PrintLife(19, 0, 1, 1, 0, 0.0);
	}

	else if (life < 50 && life > 0)
	{
		PrintLife(17, 0, 1, 1, 0, val_life);
		PrintLife(18, 0, 1, 1, 0, 0.0);
		PrintLife(19, 0, 1, 1, 0, 0.0);
	}

	else
	{
		PrintLife(17, 0, 1, 1, 0, 0.0);
		PrintLife(18, 0, 1, 1, 0, 0.0);
		PrintLife(19, 0, 1, 1, 0, 0.0);
	}

	

	switch (weapon)
	{
	case 0: PrintImg(22, 0, 1, 1, icons, 1);
		break;
	case 1: PrintImg(22, 0, 1, 1, icons, 2);		
		break;
	case 2: PrintImg(22, 0, 1, 1, icons, 3);		
		break;
	case 3: PrintImg(22, 0, 1, 1, icons, 4);		
		break;
	}

}

void HUD::LoadAllTextures()
{
	LoadGLTextures("nbrs", "HUD/S0.png");				//	0
	LoadGLTextures("nbrs", "HUD/S1.png");
	LoadGLTextures("nbrs", "HUD/S2.png");
	LoadGLTextures("nbrs", "HUD/S3.png");
	LoadGLTextures("nbrs", "HUD/S4.png");
	LoadGLTextures("nbrs", "HUD/S5.png");				//	5
	LoadGLTextures("nbrs", "HUD/S6.png");
	LoadGLTextures("nbrs", "HUD/S7.png");
	LoadGLTextures("nbrs", "HUD/S8.png");
	LoadGLTextures("nbrs", "HUD/S9.png");
	LoadGLTextures("infos", "HUD/Score.png");			//	10
	LoadGLTextures("infos", "HUD/Life.png");
//	LoadGLTextures("infos", "HUD/weapon.png");
	LoadGLTextures("icons", "HUD/LifeIco.png");
	LoadGLTextures("icons", "weapon_01.png");
	LoadGLTextures("icons", "weapon_02.png");
	LoadGLTextures("icons", "weapon_03.png");
	LoadGLTextures("icons", "weapon_04.png");

}

int HUD::LoadGLTextures(string type, string nameIncomplete)
{
	string name = "Art/" + nameIncomplete;

	if (type == "infos")
	{
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		infos.push_back(essai); // Add to the texture vector

		if (infos.at(infos.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}

	else if (type == "nbrs")
	{
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		nbrs.push_back(essai); // Add to the texture vector

		if (nbrs.at(nbrs.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}

	else if (type == "icons")
	{
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		icons.push_back(essai); // Add to the texture vector

		if (icons.at(icons.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}
}
