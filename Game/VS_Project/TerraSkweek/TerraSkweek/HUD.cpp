#include "HUD.h"



HUD::HUD(int Lv)
{
	
	Level = Lv;
	if (Level == 1)
	{
		LevelScore = 0;
		timer = 210;
	}
	else if (Level == 2)
	{
		LevelScore = 0;
		timer = 210;
	}
	else if (Level == 3)
	{
		LevelScore = 0;
		timer = 210;
	}
	else if (Level == 4)
	{
		LevelScore = 0;
		timer = 210;
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
	LoadGLTextures("nbrs", "HUD/S9.png");				//	9
	LoadGLTextures("infos", "HUD/Score.png");			//	0
	LoadGLTextures("infos", "HUD/Life.png");
	LoadGLTextures("infos", "HUD/loose.png");			//	2
	LoadGLTextures("icons", "HUD/LifeIco.png");			//	0
	LoadGLTextures("icons", "weapon_01.png");
	LoadGLTextures("icons", "weapon_02.png");
	LoadGLTextures("icons", "weapon_03.png");
	LoadGLTextures("icons", "weapon_04.png");			//	4

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

void HUD::PrintImg(float i, float j, float width, float height, vector<GLuint> vecTex ,int textureIt)
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

void HUD::PrintLife(float i, float j, float width, float height, int textureIt, float saturation)
{
	glEnable(GL_TEXTURE_2D); // Start textures
	glBindTexture(GL_TEXTURE_2D, icons[textureIt]);
	glBegin(GL_QUADS);

	glColor4d(saturation, saturation, saturation, saturation);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(i, j);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(i + height, j);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(i + height, j + width);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j + width);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void HUD::displayScore(int score, float life, int weapon)
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

//	resolution = resolution / glutGet(GLUT_WINDOW_WIDTH);

//Draw SCORE : 0000000


	PrintImg(2000.0/glutGet(GLUT_WINDOW_WIDTH), 0, resolution / glutGet(GLUT_WINDOW_WIDTH), 5* resolution / glutGet(GLUT_WINDOW_WIDTH), infos, 0);
	int i = 0;
	int j = 0;
	int s_I = score % 10;
	int s_X = score / 10 % 10;
	int s_C = score / 100 % 10;
	int s_M = score / 1000 % 10;
	int s_XM = score / 10000 % 10;
	int s_XXM = score / 100000 % 10;
	int s_XXXM = score / 1000000 % 10;


	cout << "s_I " << s_I << endl;
	cout << "s_X " << s_X << endl;
	cout << "s_C " << s_I << endl;
	cout << "s_M " << s_I << endl;
	cout << "s_XM " << s_I << endl;
	cout << "s_XXM " << s_I << endl;
	/*
	scoreTab[0] = LevelScore;
	if (s_I > 9)
	{
		scoreTab[1] ++;
		scoreTab[0] = 0;
		LevelScore = 9;
	}
	else if (s_X > 9)
	{
		scoreTab[1] = 0;
		scoreTab[2]++;
		LevelScore = 9;
	}
	else if (s_C > 9)
	{
		scoreTab[2] = 0;
		scoreTab[3] ++;
		LevelScore = 9;
	}
	else if (s_M > 9)
	{
		scoreTab[3] = 0;
		scoreTab[4] ++;
		LevelScore = 9;
	}
	else if (s_XM > 9)
	{
		scoreTab[4] = 0;
		scoreTab[5] ++;
		LevelScore = 9;
	}
	else if (s_XXM > 9)
	{
		scoreTab[5] = 0;
		scoreTab[6] ++;
		LevelScore = 9;
	}

	

	for (i = 0; i < 7; i++)
	{
		PrintImg(16000 / glutGet(GLUT_WINDOW_WIDTH) - i*0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), nbrs, 1);
	}
	*/
	PrintImg(16000 / glutGet(GLUT_WINDOW_WIDTH) - 1 * 0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), nbrs, s_C);
	PrintImg(16000 / glutGet(GLUT_WINDOW_WIDTH) - 2 * 0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), nbrs, s_I);
	PrintImg(16000 / glutGet(GLUT_WINDOW_WIDTH) - 3 * 0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), nbrs, s_X);
	PrintImg(16000 / glutGet(GLUT_WINDOW_WIDTH) - 4 * 0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), nbrs, s_C);
	PrintImg(16000 / glutGet(GLUT_WINDOW_WIDTH) - 5 * 0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), nbrs, s_M);
	PrintImg(16000 / glutGet(GLUT_WINDOW_WIDTH) - 6 * 0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), nbrs, s_XM);
	PrintImg(16000 / glutGet(GLUT_WINDOW_WIDTH) - 7 * 0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), nbrs, s_XXM);
	PrintImg(16000 / glutGet(GLUT_WINDOW_WIDTH) - 7 * 0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), nbrs, s_XXXM);


	// Draw Life icon

	PrintImg(22000 / glutGet(GLUT_WINDOW_WIDTH), 0, resolution / glutGet(GLUT_WINDOW_WIDTH), 3* resolution / glutGet(GLUT_WINDOW_WIDTH), infos, 1);
	float PaddingLife = 26000.0;
	float val_life = life / 50;

		if (life == 150)
	{
		PrintLife(PaddingLife / glutGet(GLUT_WINDOW_WIDTH), 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, 1.0);
		PrintLife(PaddingLife / glutGet(GLUT_WINDOW_WIDTH) + 0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, 1.0);
		PrintLife(PaddingLife / glutGet(GLUT_WINDOW_WIDTH) + 1, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, 1.0);
	}

	else if (life < 150 && life > 100)
	{
		PrintLife(PaddingLife / glutGet(GLUT_WINDOW_WIDTH) , 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, 1.0);
		PrintLife(PaddingLife / glutGet(GLUT_WINDOW_WIDTH) + 0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, 1.0);
		PrintLife(PaddingLife / glutGet(GLUT_WINDOW_WIDTH) + 1, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, val_life/3);
	}

	else if (life < 100 && life > 50)
	{
		PrintLife(PaddingLife / glutGet(GLUT_WINDOW_WIDTH) , 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, 1.0);
		PrintLife(PaddingLife / glutGet(GLUT_WINDOW_WIDTH) + 0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, val_life / 2);
		PrintLife(PaddingLife / glutGet(GLUT_WINDOW_WIDTH) + 1, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, 0.0);
	}

	else if (life < 50 && life > 0)
	{
		PrintLife(PaddingLife / glutGet(GLUT_WINDOW_WIDTH) , 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, val_life);
		PrintLife(PaddingLife / glutGet(GLUT_WINDOW_WIDTH) + 0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, 0.0);
		PrintLife(PaddingLife / glutGet(GLUT_WINDOW_WIDTH) + 1, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, 0.0);
	}

	else
	{
		PrintLife(18, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, 0.0);
		PrintLife(19, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, 0.0);
		PrintLife(20, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), 0, 0.0);
	}

	// Draw Timer
	ClockDuration = (clock() - Clock) / (double)CLOCKS_PER_SEC;
	if (!timer <= 0)
		timer = 180 - ClockDuration;

	PrintImg(34000 / glutGet(GLUT_WINDOW_WIDTH), 0, resolution / glutGet(GLUT_WINDOW_WIDTH), 3*resolution / glutGet(GLUT_WINDOW_WIDTH), infos, 1);

	t_unite = timer % 10;
	t_dizaine = timer / 10 % 10;
	t_centaine = timer / 100 % 10;

	PrintImg(39000 / glutGet(GLUT_WINDOW_WIDTH), 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), nbrs, t_centaine);
	PrintImg(39000 / glutGet(GLUT_WINDOW_WIDTH) + 0.5, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), nbrs, t_dizaine);
	PrintImg(39000 / glutGet(GLUT_WINDOW_WIDTH) + 1, 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), nbrs, t_unite);


	if(timer <= 0)
		PrintImg(12, 4, 6* resolution / glutGet(GLUT_WINDOW_WIDTH), 6* resolution / glutGet(GLUT_WINDOW_WIDTH), infos, 2);

	// Draw Weapon icon

	switch (weapon)
	{
	case 0: PrintImg(45000 / glutGet(GLUT_WINDOW_WIDTH), 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), icons, 0);
		break;
	case 1: PrintImg(45000 / glutGet(GLUT_WINDOW_WIDTH), 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), icons, 1);
		break;
	case 2: PrintImg(45000 / glutGet(GLUT_WINDOW_WIDTH), 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), icons, 2);
		break;
	case 3: PrintImg(45000 / glutGet(GLUT_WINDOW_WIDTH), 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), icons, 3);
		break;
	case 4: PrintImg(45000 / glutGet(GLUT_WINDOW_WIDTH), 0, resolution / glutGet(GLUT_WINDOW_WIDTH), resolution / glutGet(GLUT_WINDOW_WIDTH), icons, 4);
		break;
	}

}

