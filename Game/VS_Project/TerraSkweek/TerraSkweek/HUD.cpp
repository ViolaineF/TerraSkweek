#include "HUD.h"

//----------------------- REF TO EXTERN VARIABLES
extern int windowWidth;
extern int windowHeight;
extern const int TextWidth;
extern bool inGame;
extern int screenID;

HUD::HUD(int Lv)
{
	Level = Lv;
	if (Level == 1)
	{
		LevelScore = 0;
		timer = 180;
	}
	else if (Level == 2)
	{
		LevelScore = 0;
		timer = 180;
	}
	else if (Level == 3)
	{
		LevelScore = 0;
		timer = 180;
	}
	else if (Level == 4)
	{
		LevelScore = 0;
		timer = 180;
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
	LoadGLTextures("infos", "HUD/timer.png");			//	2
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

void HUD::ResetTimer(int a)
{
	Clock = clock();
	timer = a;
	cout << "reset time ";

	
}

void HUD::PrintImg(float i, float j, float width, float height, vector<GLuint> vecTex ,int textureIt)
{
	glEnable(GL_TEXTURE_2D); // Start textures
	glBindTexture(GL_TEXTURE_2D, vecTex[textureIt]);
	glBegin(GL_QUADS);

	glColor4d(1.0, 1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(i - width/2.0f, j - height / 2.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(i + width / 2.0f, j - height / 2.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(i + width / 2.0f, j + height / 2.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(i - width / 2.0f, j + height / 2.0f);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void HUD::PrintLife(float i, float j, float width, float height, int textureIt, float saturation)
{
	glEnable(GL_TEXTURE_2D); // Start textures
	glBindTexture(GL_TEXTURE_2D, icons[textureIt]);
	glBegin(GL_QUADS);

	glColor4d(saturation, saturation, saturation, saturation);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(i - width /2, j - height /2);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(i + width /2, j - height /2);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(i + width /2, j + height /2);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(i - width /2, j + height /2);

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

//	resolution = resolution / windowWidth;

//Draw SCORE : 0000000

	float vMargin = (windowHeight * 5) / 100.0;
	float ratio = 4.0;
	float height = (windowWidth * 4) / 100.0;
	float width = height*ratio;

	PrintImg((windowWidth * 10) / 100.0, vMargin, width, height, infos, 0); // Score
	int i = 0;
	int j = 0;
	int s_I = score % 10;
	int s_X = score / 10 % 10;
	int s_C = score / 100 % 10;
	int s_M = score / 1000 % 10;
	int s_XM = score / 10000 % 10;
	int s_XXM = score / 100000 % 10;
	int s_XXXM = score / 1000000 % 10;


	float offset = (windowWidth * 2) / 100.0;
	float start = (windowWidth * 32) / 100.0;
	ratio = 1.0;
	width = height*ratio;

	PrintImg(start, vMargin, width, height, nbrs, s_I); // Numbers of the score 
	PrintImg(start - offset, vMargin, width, height, nbrs, s_X);
	PrintImg(start - 2*offset, vMargin, width, height, nbrs, s_C);
	PrintImg(start - 3*offset, vMargin, width, height, nbrs, s_M);
	PrintImg(start - 4*offset, vMargin, width, height, nbrs, s_XM);
	PrintImg(start - 5*offset, vMargin, width, height, nbrs, s_XXM);
	PrintImg(start - 6*offset, vMargin, width, height, nbrs, s_XXXM);


	// Draw Life text
	float startLife = start + (windowWidth * 13) / 100.0;
	ratio = 3.0;
	width = height*ratio;

	PrintImg(startLife, vMargin, width, height, infos, 1);

	// Draw Life icons
	float PaddingLife = startLife + (windowWidth * 8) / 100.0;
	float val_life = life / 50;
	ratio = 1.0;
	width = height*ratio;


		if (life == 150)
	{
		PrintLife(PaddingLife, vMargin, width, height, 0, 1.0);
		PrintLife(PaddingLife + offset, vMargin, width, height, 0, 1.0);
		PrintLife(PaddingLife + 2*offset, vMargin, width, height, 0, 1.0);
	}

	else if (life < 150 && life > 100)
	{
		PrintLife(PaddingLife , vMargin, width, height, 0, 1.0);
		PrintLife(PaddingLife + offset, vMargin, width, height, 0, 1.0);
		PrintLife(PaddingLife + 2*offset, vMargin, width, height, 0, val_life/3);
	}

	else if (life < 100 && life > 50)
	{
		PrintLife(PaddingLife , vMargin, width, height, 0, 1.0);
		PrintLife(PaddingLife + offset, vMargin, width, height, 0, val_life / 2);
		PrintLife(PaddingLife + 2*offset, vMargin, width, height, 0, 0.0);
	}

	else if (life < 50 && life > 0)
	{
		PrintLife(PaddingLife , vMargin, width, height, 0, val_life);
		PrintLife(PaddingLife + offset, vMargin, width, height, 0, 0.0);
		PrintLife(PaddingLife + 2*offset, vMargin, width, height, 0, 0.0);
	}

	else
	{
		PrintLife(18, vMargin, width, height, 0, 0.0);
		PrintLife(19, vMargin, width, height, 0, 0.0);
		PrintLife(20, vMargin, width, height, 0, 0.0);
	}

	// Draw Timer
	ClockDuration = (clock() - Clock) / (double)CLOCKS_PER_SEC;
	if (!timer <= 0)
		timer = 180 - ClockDuration;

	startTimer = PaddingLife + 2*offset + (windowWidth * 13) / 100.0;
	ratio = 4.0;
	width = height*ratio;
	
	PrintImg(startTimer, vMargin, width, height, infos, 2);

	// Draw Timer numbers
	ratio = 1.0;
	width = height*ratio;

	t_unite = timer % 10;
	t_dizaine = timer / 10 % 10;
	t_centaine = timer / 100 % 10;

	PrintImg(startTimer + 5*offset, vMargin, width, height, nbrs, t_centaine);
	PrintImg(startTimer + 6*offset, vMargin, width, height, nbrs, t_dizaine);
	PrintImg(startTimer + 7*offset, vMargin, width, height, nbrs, t_unite);


	// Draw YOU LOOSE image
	ratio = 1.0;
	width = height*ratio;

	if (timer <= 0) {
		inGame = false;
		screenID = 6;
	}

		

	// Draw Weapon icon
	ratio = 1.0;
	width = height*ratio;

	float startWeaponIcon = startTimer + 12*offset;

	switch (weapon)
	{
	case 0: PrintImg(startWeaponIcon, vMargin, width, height, icons, 0);
		break;
	case 1: PrintImg(startWeaponIcon, vMargin, width, height, icons, 1);
		break;
	case 2: PrintImg(startWeaponIcon, vMargin, width, height, icons, 2);
		break;
	case 3: PrintImg(startWeaponIcon, vMargin, width, height, icons, 3);
		break;
	case 4: PrintImg(startWeaponIcon, vMargin, width, height, icons, 4);
		break;
	}

}

