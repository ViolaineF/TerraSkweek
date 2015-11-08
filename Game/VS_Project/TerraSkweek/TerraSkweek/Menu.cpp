#include "Menu.h"

extern Grid lvl;
extern int windowWidth;
extern int windowHeight;
extern const float res;
bool inGame;
extern Player player;
extern float dim = res*windowWidth*0.035;
extern string m_biome;
extern HUD hud;


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
	b_continue.SetPos(b1_pos);
	b_quit.SetPos(b2_pos);

	b_jungle.SetPos(bJungle_pos);
	b_corruption.SetPos(bCorruption_pos);
	b_crimson.SetPos(bCrimson_pos);
	b_hallow.SetPos(bHallow_pos);
}


void Menu::LoadAllTextures()
{
	string directory = "Art/UI/";
	b_newGame.LoadAllTextures("new_game");
	b_loadGame.LoadAllTextures("load_game");
	b_continue.LoadAllTextures("continue");
	b_quit.LoadAllTextures("quit");

	b_jungle.LoadAllTextures("jungle");
	b_corruption.LoadAllTextures("corruption");
	b_crimson.LoadAllTextures("crimson");
	b_hallow.LoadAllTextures("hallow");

	LoadGLTextures("UI", directory + "title.png"); // 0
	LoadGLTextures("UI", directory + "water.png"); // 1*
	
}

void Menu::LoadStoryTextures(string name, int n_pictures)
{
	string id_pictures;
	string directory = "Art/Story/"+ name +"/";
	for (int i = 0; i < n_pictures; i++)
	{
		id_pictures = to_string(i);

		if (i < 10)
		{
			LoadGLTextures("story", directory + "screen000" + id_pictures + ".png");
			cout << directory + "screen000" + id_pictures + ".png";

		}
		else if (i >= 10)
		{
			LoadGLTextures("story", directory + "screen00" + id_pictures + ".png");
			cout << directory + "screen00" + id_pictures + ".png";

		}
		cout << "tex loaded = " << i << endl;

		continue;
	}
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

	if (type == "story")
	{
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		story.push_back(essai); // Add to the texture vector

		if (story.at(story.size() - 1) == 0)
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
	float width;
	float height;
	float heightPrev;
	float paddingV;

	switch (screenID)
	{
//_________________________________________________________

	case 0:
		// 	TITLE
		ratio = 3.97;
		width = (windowWidth*40)/100.0;
		height = width/ratio;
		paddingV = windowHeight / 12;
		//height1 = (windowWidth*0.05) * (windowHeight*0.0015);
		// PrintImg(res * windowWidth / 3.97 * (dim / 2), res * windowHeight / 3, dim, dim*3.97, UI, 0);
//		PrintImg(res * windowWidth / ratio * (dim / 2), res * windowHeight / 3, dim, dim*ratio, UI, 0);
		PrintImg((windowWidth/2) - (width/2), paddingV , height, width, UI, 0);

		// Update Padding
		paddingV = paddingV + 1.2*height;

		// Draw new game button
		// Update Ratio of button 1
		ratio = 5.93;
		width = (windowWidth * 20) / 100.0;
		height = width / ratio;

		if (b_newGame.GetPos() == player.GetPos())
		{
			b_newGame.OnOver();
			b_newGame.Draw((windowWidth / 2) - (width / 2), paddingV, height, width);

			if (click) 
			{
				screenID = 1;
			}
		}
		else
//			b_newGame.Draw(res * windowWidth / ratio * (dim / 2), res * windowHeight / 8, dim, dim*ratio);
			b_newGame.Draw((windowWidth / 2) - (width / 2), paddingV, height, width);

		// Update Padding
		paddingV = paddingV + 2*height;

		// Update Ratio of button 2
		ratio = 6.66;
		width = (windowWidth * 20) / 100.0;
		height = width / ratio;
		// Draw load game button
		if (b_loadGame.GetPos() == player.GetPos())
		{
			b_loadGame.OnOver();
			b_loadGame.Draw((windowWidth / 2) - (width / 2), paddingV, height, width);

			if (click)
			{
				screenID = 2;
			}
		}
		else
			b_loadGame.Draw((windowWidth / 2) - (width / 2), paddingV, height, width);
		break;

//_________________________________________________________

	case 1:
		// 	MAP
		// Draw Water Sprite
		for (int i = 0; i < 20; i++){
			for (int j = 0; j < 20; j++){
				PrintImg(0, 0, dim, dim + j, UI, 1);
			}
		}

		// Draw load Jungle Island button
		// Update Ratio 
		ratio = 0.97;
		width = (windowWidth * 25) / 100.0;
		height = width / ratio;

		if (b_jungle.GetPos() == player.GetPos())
		{
			b_jungle.OnOver();
			b_jungle.Draw((windowWidth / 4) - (width / 2), windowHeight / 12, height, width);

			if (click) 
			{
				screenID = 4;

				lvl.ChangeMap(1);
				player.Teleport({ 10, 10, 0 });
				LoadStoryTextures("story1", 51);

			}
		}
		else
			b_jungle.Draw((windowWidth / 4) - (width / 2), windowHeight / 12, height, width);

		// Draw load Corruption Island button
		// Update Ratio 
		ratio = 1;
		if (b_corruption.GetPos() == player.GetPos())
		{
			b_corruption.OnOver();
			b_corruption.Draw(bCorruption_pos.x, bCorruption_pos.y, 5 * dim, 5 * dim*ratio);

			if (click)
			{
				screenID = 4;

				lvl.ChangeMap(2);
				player.Teleport({ 10, 10, 0 });
				LoadStoryTextures("story2", 51);

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
				screenID = 4;

				lvl.ChangeMap(3);
				player.Teleport({ 10, 10, 0 });
				LoadStoryTextures("story3", 51);
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
				screenID = 4;

				lvl.ChangeMap(4);
				player.Teleport({ 10, 10, 0 });
				LoadStoryTextures("story4", 51);
			}
		}
		else
			b_hallow.Draw(bHallow_pos.x, bHallow_pos.y, 5 * dim, 5 * dim*ratio);
		break;

//_________________________________________________________

	case 2:
		// LOAD GAME
		screenID = 1;

		break;

//_________________________________________________________

	case 3:
		// PAUSE

		ratio = 3.97;
		// PrintImg(res * windowWidth / 3.97 * (dim / 2), res * windowHeight / 3, dim, dim*3.97, UI, 0);
		//		PrintImg(res * windowWidth / ratio * (dim / 2), res * windowHeight / 3, dim, dim*ratio, UI, 0);
		PrintImg(5, 1, dim, dim*ratio, UI, 0);

		// dim*3.97/2

		// Draw new game button
		// Update Ratio of button 1
		ratio = 5.53;
		if (b_continue.GetPos() == player.GetPos())
		{
			b_continue.OnOver();
			b_continue.Draw(b1_pos.x, b1_pos.y, dim, dim*ratio);

			if (click)
			{
				player.Teleport(p_prev_pos);
				inGame = true;
				screenID = 3;
			}
		}
		else
			//			b_newGame.Draw(res * windowWidth / ratio * (dim / 2), res * windowHeight / 8, dim, dim*ratio);
			b_continue.Draw(b1_pos.x, b1_pos.y, dim, dim*ratio);


		// Update Ratio of button 2
		ratio = 2.32;
		// Draw load game button
		if (b_quit.GetPos() == player.GetPos())
		{
			b_quit.OnOver();
			b_quit.Draw(b2_pos.x, b2_pos.y, dim, dim*ratio);

			if (click)
			{
				lvl.ClearMap();
				lvl.ChangeMap(0);
				cout << "lvl = 0" << endl;
				inGame = false;
				screenID = 0;
			}
		}
		else
			b_quit.Draw(b2_pos.x, b2_pos.y, dim, dim*ratio);
		break;

//_________________________________________________________

	case 4:
		// Story Screen
		DisplayStory(story.size());


	}
	click = false;

}


void Menu::DisplayStory(int n_pictures)
{
	const int vitesse = 200;
	currentFrame = (currentFrame + 1) % vitesse;
	unsigned int frame = currentFrame * n_pictures / vitesse;


	glPushMatrix();
	// Story Screen
	glEnable(GL_TEXTURE_2D); // Start textures
	glBindTexture(GL_TEXTURE_2D, story[frame]);
	glBegin(GL_QUADS);

	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(0, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(0 + 10, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(0 + 10, 0 + 10);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(0, 0 + 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	if (frame == n_pictures - 1) {
		cout << "frame = " << frame;
		screenID = 3;
		inGame = true;
		hud.ResetTimer(180);
		story.clear();
		story.resize(0);
	}


	/*
	for (int i = 0; i = n_pictures; i++)
	{
		glPushMatrix();
		// Story Screen
		glEnable(GL_TEXTURE_2D); // Start textures
		glBindTexture(GL_TEXTURE_2D, story[frame]);
		glBegin(GL_QUADS);

		glColor3d(1.0, 1.0, 1.0);
		glTexCoord2f(1.0f, 1.0f);
		glVertex2d(0, 0);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2d(20, 0);
		glTexCoord2f(0.0f, 0.0f);
		glVertex2d(20, 20);
		glTexCoord2f(1.0f, 0.0f);
		glVertex2d(0, 20);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		/*
		if (i = n_pictures) {
			inGame = true;
			hud.ResetTimer(180);
			story.clear();
			story.resize(0);
		}
		
	}
	*/
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
	}
	else
	{
		player.Teleport(p_prev_pos);
		inGame = true;
		screenID = 3;
	}
}

Menu::~Menu()
{
}


