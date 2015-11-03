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

	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(i + height, j);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(i + height, j + width);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(i, j + width);

	glEnd();
	glDisable(GL_TEXTURE_2D);


}



void HUD::displayScore(int life, int weapon)
{
	if (life == 0)
	{
//		lose
//		onScreen = true;
//		screen = 7;
	}
	
	switch (weapon)
	{
	case 0:
		PrintImg(1, 1, 1, 5, icons, 1);
		break;
	case 1:
		PrintImg(1, 1, 1, 5, icons, 2);
		break;
	case 2:
		PrintImg(1, 1, 1, 5, icons, 3);
		break;
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

/*
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, infos[0]);
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
	glBindTexture(GL_TEXTURE_2D, infos[2]);
	glBegin(GL_QUADS);
	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(0, 1);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(1, 1);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(1, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(0, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);


	glPushMatrix();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, hudTex[3]);
	glBegin(GL_QUADS);
	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(0, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex2d( + 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(0 + 1,0 + 1);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(0, 0+ 1);



	for (i = 0; i < life; i++)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, infos[13]);
		glBegin(GL_QUADS);
		glColor3d(1.0, 1.0, 1.0);
		glTexCoord2f(0.0f, 0.0f); glVertex2d(1 + i, 1);
		glTexCoord2f(1.0f, 0.0f); glVertex2d(0 + i, 1);
		glTexCoord2f(1.0f, 1.0f); glVertex2d(0 + i, 0);
		glTexCoord2f(0.0f, 1.0f); glVertex2d(1 + i, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
*/
	glPushMatrix();
	PrintImg(1, 1, 1, 5, infos, 0);
	PrintImg(7, 1, 1, 1, icons, 1);
	PrintImg(8, 1, 1, 1, nbrs, 1);
	glPopMatrix();
}

void HUD::LoadAllTextures()
{
	LoadGLTextures("nbrs","HUD/S0.png");				//	0
	LoadGLTextures("nbrs","HUD/S1.png");
	LoadGLTextures("nbrs","HUD/S2.png");
	LoadGLTextures("nbrs","HUD/S3.png");
	LoadGLTextures("nbrs","HUD/S4.png");
	LoadGLTextures("nbrs","HUD/S5.png");				//	5
	LoadGLTextures("nbrs","HUD/S6.png");
	LoadGLTextures("nbrs","HUD/S7.png");
	LoadGLTextures("nbrs","HUD/S8.png");
	LoadGLTextures("nbrs","HUD/S9.png");
	LoadGLTextures("infos","HUD/Score.png");			//	10
	LoadGLTextures("infos","HUD/Life.png");
	LoadGLTextures("infos","HUD/weapon.png");
	LoadGLTextures("icons", "HUD/LifeIco.png");
	LoadGLTextures("icons", "weapon_01.png");
	LoadGLTextures("icons", "weapon_02.png");
	LoadGLTextures("icons", "weapon_03.png");

}

int HUD::LoadGLTextures(string type, string name)
{
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
