#include "Menu.h"

extern Grid lvl;
extern int windowWidth;
extern int windowHeight;
extern const float res;
bool inGame;
extern Player player;
Menu::Menu()
{
	screenID = 0;
	inGame = false;

	
	Position b1_pos{ 3,3,0 };
	Position b2_pos{ 5,3,0 };
	Position bJungle_pos{ 3,3,0 };
	Position bCorruption_pos{ 7,11,0 };
	Position bCrimson_pos{ 11,10,0 };
	Position bHallow_pos{ 15,5,0 };

	b_newGame.SetPos(b1_pos);
	b_loadGame.SetPos(b2_pos);


}


void Menu::LoadAllTextures()
{
	string directory = "Art/UI/";

	//--------------BASE TEXTURES
	LoadGLTextures("button", directory + "new_game_idle.png"); // 0
	LoadGLTextures("button", directory + "new_game_over.png"); // 1
	LoadGLTextures("button", directory + "load_game_idle.png"); // 2
	LoadGLTextures("button", directory + "load_game_over.png"); // 3

	LoadGLTextures("UI", directory + "title.png"); // 0
	LoadGLTextures("UI", directory + "water.png"); // 1
	LoadGLTextures("UI", directory + "Islands.png"); // 2
}

int Menu::LoadGLTextures(string type, string name)
{
	if (type == "UI")
	{
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		UI.push_back(essai); // Add to the texture vector

		if (UI.at(UI.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}
}

void Menu::Display()
{
	float dim = res*windowWidth*0.035;

	switch (screenID) 
	{

	case 0:


		// Draw title

		PrintImg(dim*2, 0, dim, dim*3.97, UI, 0);

		// Draw new game button

		if (b_newGame.GetPos() == player.GetPos())
		{
			b_newGame.OnOver();
			b_newGame.Draw();
			if (click)
				screenID = 1;
		}
		else
			b_newGame.Draw();

		// Draw load game button
		if (b_loadGame.GetPos() == player.GetPos())
		{
			b_loadGame.OnOver();
			b_loadGame.Draw();
			if (click)
				screenID = 1;
		}
		else
			b_loadGame.Draw();
		break;


	case 1:

		for (int i = 0; i < 10; i++)
		{
			PrintImg(0, 0, dim / 10 + i, dim / 10, UI, 1);
		}
		PrintImg(0, 0, 0.831*dim /1.5, 0.507*dim /1.5, UI, 2);
		break;

	}

}

void Menu::PrintImg(float i, float j, float width, float height, vector<GLuint> vecTex, int textureIt)
{
	glEnable(GL_TEXTURE_2D); // Start textures
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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

void Menu::Clicking()
{
	click = true;
}

void Menu::Pause()
{
//	clickPause = true;
}

Menu::~Menu()
{
}


