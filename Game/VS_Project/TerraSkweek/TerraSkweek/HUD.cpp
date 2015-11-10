#include "HUD.h"

//----------------------- REF TO EXTERN VARIABLES
extern int windowWidth;
extern int windowHeight;
extern const int TextWidth;

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

//	resolution = resolution / windowWidth;

//Draw SCORE : 0000000

	float dim = resolution*windowWidth*0.035;

	PrintImg(0.5*dim, 0, dim, 5*dim, infos, 0);
	int i = 0;
	int j = 0;
	int s_I = score % 10;
	int s_X = score / 10 % 10;
	int s_C = score / 100 % 10;
	int s_M = score / 1000 % 10;
	int s_XM = score / 10000 % 10;
	int s_XXM = score / 100000 % 10;
	int s_XXXM = score / 1000000 % 10;


	//cout << "s_I " << s_I << endl;
	//cout << "s_X " << s_X << endl;
	//cout << "s_C " << s_I << endl;
	//cout << "s_M " << s_I << endl;
	//cout << "s_XM " << s_I << endl;
	//cout << "s_XXM " << s_I << endl;

	float offset = 0.75*dim;
	float start = 9.5*dim;

	PrintImg(start, 0, dim, dim, nbrs, s_I);
	PrintImg(start - offset, 0, dim, dim, nbrs, s_X);
	PrintImg(start - 2*offset, 0, dim, dim, nbrs, s_C);
	PrintImg(start - 3*offset, 0, dim, dim, nbrs, s_M);
	PrintImg(start - 4*offset, 0, dim, dim, nbrs, s_XM);
	PrintImg(start - 5*offset, 0, dim, dim, nbrs, s_XXM);
	PrintImg(start - 6*offset, 0, dim, dim, nbrs, s_XXXM);


	// Draw Life icon
	float startLife = start + 2.5*offset;

	PrintImg(startLife, 0, dim, 3*dim, infos, 1);
	float PaddingLife = startLife+5*offset;
	float val_life = life / 50;


		if (life == 150)
	{
		PrintLife(PaddingLife, 0, dim, dim, 0, 1.0);
		PrintLife(PaddingLife + offset, 0, dim, dim, 0, 1.0);
		PrintLife(PaddingLife + 2*offset, 0, dim, dim, 0, 1.0);
	}

	else if (life < 150 && life > 100)
	{
		PrintLife(PaddingLife , 0, dim, dim, 0, 1.0);
		PrintLife(PaddingLife + offset, 0, dim, dim, 0, 1.0);
		PrintLife(PaddingLife + 2*offset, 0, dim, dim, 0, val_life/3);
	}

	else if (life < 100 && life > 50)
	{
		PrintLife(PaddingLife , 0, dim, dim, 0, 1.0);
		PrintLife(PaddingLife + offset, 0, dim, dim, 0, val_life / 2);
		PrintLife(PaddingLife + 2*offset, 0, dim, dim, 0, 0.0);
	}

	else if (life < 50 && life > 0)
	{
		PrintLife(PaddingLife , 0, dim, dim, 0, val_life);
		PrintLife(PaddingLife + offset, 0, dim, dim, 0, 0.0);
		PrintLife(PaddingLife + 2*offset, 0, dim, dim, 0, 0.0);
	}

	else
	{
		PrintLife(18, 0, dim, dim, 0, 0.0);
		PrintLife(19, 0, dim, dim, 0, 0.0);
		PrintLife(20, 0, dim, dim, 0, 0.0);
	}

	// Draw Timer
	ClockDuration = (clock() - Clock) / (double)CLOCKS_PER_SEC;
	if (!timer <= 0)
		timer = 180 - ClockDuration;

	startTimer = PaddingLife + 5 * offset;
	
	PrintImg(startTimer, 0, dim, 3*dim, infos, 1);

	t_unite = timer % 10;
	t_dizaine = timer / 10 % 10;
	t_centaine = timer / 100 % 10;

	PrintImg(startTimer + 5*offset, 0, dim, dim, nbrs, t_centaine);
	PrintImg(startTimer + 6*offset, 0, dim, dim, nbrs, t_dizaine);
	PrintImg(startTimer + 7*offset, 0, dim, dim, nbrs, t_unite);


	if(timer <= 0)
		PrintImg(12, 4, 6* dim, 6* dim, infos, 2);

	// Draw Weapon icon

	float startWeaponIcon = startTimer + 10 * offset;

	switch (weapon)
	{
	case 0: PrintImg(startWeaponIcon, 0, dim, dim, icons, 0);
		break;
	case 1: PrintImg(startWeaponIcon, 0, dim, dim, icons, 1);
		break;
	case 2: PrintImg(startWeaponIcon, 0, dim, dim, icons, 2);
		break;
	case 3: PrintImg(startWeaponIcon, 0, dim, dim, icons, 3);
		break;
	case 4: PrintImg(startWeaponIcon, 0, dim, dim, icons, 4);
		break;
	}

}

