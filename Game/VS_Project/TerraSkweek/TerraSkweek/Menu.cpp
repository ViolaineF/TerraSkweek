#include "Menu.h"

extern Grid lvl;
extern int windowWidth;
extern int windowHeight;
extern const float res;
bool inGame;
extern Player player;
extern float dim = res*windowWidth*0.035;
;

//Position b1_pos{ res * windowWidth / 5.93 * (dim / 2), res * windowHeight / 8,0 };

//Position b1_pos{ dim * 5.9 , res * windowHeight / 8, 0 };
Position b1_pos{ 5,5,0 };
Position b2_pos{ 5,6,0 };

Position bJungle_pos{ 1,2,0 };
Position bCorruption_pos{ 2,5,0 };
Position bCrimson_pos{ 5,6,0 };
Position bHallow_pos{ 8,3,0 };

Menu::Menu()
{
	screenID = 0;
	inGame = false;

	b_newGame.SetPos(b1_pos);
	b_loadGame.SetPos(b2_pos);	
	
	b_jungle.SetPos(b1_pos);
	b_corruption.SetPos(b2_pos);
	b_crimson.SetPos(b1_pos);
	b_hallow.SetPos(b2_pos);

}


void Menu::LoadAllTextures()
{
	string directory = "Art/UI/";
	b_newGame.LoadAllTextures("new_game");
	b_loadGame.LoadAllTextures("load_game");
	b_jungle.LoadAllTextures("jungle");
	b_corruption.LoadAllTextures("corruption");
	b_crimson.LoadAllTextures("crimson");
	b_hallow.LoadAllTextures("hallow");

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
	dim = res*windowWidth*0.035;
	float ratio;

	switch (screenID)
	{
	case 0:
		// 	TITLE
		ratio = 3.97;
		// PrintImg(res * windowWidth / 3.97 * (dim / 2), res * windowHeight / 3, dim, dim*3.97, UI, 0);
//		PrintImg(res * windowWidth / ratio * (dim / 2), res * windowHeight / 3, dim, dim*ratio, UI, 0);
		PrintImg(5, 1, dim, dim*ratio, UI, 0);

		// dim*3.97/2

		// Draw new game button
		// Update Ratio of button 1
		ratio = 5.93;
		if (b_newGame.GetPos() == player.GetPos())
		{
			b_newGame.OnOver();
			b_newGame.Draw(b1_pos.x, b1_pos.y, dim, dim*ratio);

			if (click) 
			{
				screenID = 1;
			}
		}
		else
//			b_newGame.Draw(res * windowWidth / ratio * (dim / 2), res * windowHeight / 8, dim, dim*ratio);
			b_newGame.Draw(b1_pos.x, b1_pos.y, dim, dim*ratio);


		// Update Ratio of button 2
		ratio = 6.66;
		// Draw load game button
		if (b_loadGame.GetPos() == player.GetPos())
		{
			b_loadGame.OnOver();
			b_loadGame.Draw(b2_pos.x, b2_pos.y, dim, dim*ratio);

			if (click)
			{
				screenID = 1;
			}
		}
		else
			b_loadGame.Draw(b2_pos.x, b2_pos.y, dim, dim*ratio);
		break;


	case 1:
		// 	MAP
		// Draw Water Sprite

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				PrintImg(0, 0, dim, dim + j, UI, 1);
			}
		}

		// Draw load Jungle Island button
		// Update Ratio 
		ratio = 0.97;

		if (b_jungle.GetPos() == player.GetPos())
		{
			b_jungle.OnOver();
			b_jungle.Draw(bJungle_pos.x, bJungle_pos.y, 5 * dim, 5 * dim*ratio);

			if (click) 
			{
				lvl.ChangeMap(1);
				player.Teleport({ 10, 10, 0 });
				screenID = 0;
				inGame = true;
			}
		}
		else
			b_jungle.Draw(bJungle_pos.x, bJungle_pos.y, 5 * dim, 5 * dim*ratio);

		// Draw load Corruption Island button
		// Update Ratio 
		ratio = 1;
		if (b_corruption.GetPos() == player.GetPos())
		{
			b_corruption.OnOver();
			b_corruption.Draw(bCorruption_pos.x, bCorruption_pos.y, 5 * dim, 5 * dim*ratio);

			if (click)
			{
				lvl.ChangeMap(2);
				player.Teleport({ 10, 10, 0 });
				screenID = 0;	
				inGame = true;
			}
		}
		else
			b_corruption.Draw(bCorruption_pos.x, bCorruption_pos.y, 5 * dim, 5 * dim*ratio);

		// Draw load Crimson Island button
		// Update Ratio 
		ratio = 1;
		if (b_crimson.GetPos() == player.GetPos())
		{
			b_crimson.OnOver();
			b_crimson.Draw(bCrimson_pos.x, bCrimson_pos.y, 5 * dim, 5 * dim*ratio);

			if (click)
			{
				lvl.ChangeMap(3);
				player.Teleport({ 10, 10, 0 });
				screenID = 0;				
				inGame = true;
			}
		}
		else
			b_crimson.Draw(bCrimson_pos.x, bCrimson_pos.y, 5 * dim, 5 * dim*ratio);
			
		// Draw load Crimson Island button
		// Update Ratio 
		ratio = 0.99;
		if (b_hallow.GetPos() == player.GetPos())
		{
			b_hallow.OnOver();
			b_hallow.Draw(bHallow_pos.x, bHallow_pos.y, 5 * dim, 5 * dim*ratio);

			if (click)
			{
				lvl.ChangeMap(4);
				player.Teleport({ 10, 10, 0 });
				screenID = 0;				
				inGame = true;
			}
		}
		else
			b_hallow.Draw(bHallow_pos.x, bHallow_pos.y, 5 * dim, 5 * dim*ratio);
		break;

	case 2:
		// LOAD GAME

		break;

	case 3:
		// PAUSE
		break;


	}
	click = false;


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
	if (inGame)
	{
		p_prev_pos = player.GetPos();
		player.Teleport({ 5,5,0 });

		inGame = false;
		screenID = 3;
		//	clickPause = true;
	}
	else
	{
		player.Teleport(p_prev_pos);
		inGame = true;
//		screenID = 3;
	}

}

Menu::~Menu()
{
}


