#include "Menu.h"

extern const int TextWidth;
extern Grid lvl;
extern int windowWidth;
extern int windowHeight;
bool inGame;
extern Player player;
extern string m_biome;
extern HUD hud;



Menu::Menu()
{
	screenID = 0;
	inGame = false;

	b_newGame.SetPos({0,0,0});
	b_loadGame.SetPos({ 0,0,0 });
	b_continue.SetPos({ 0,0,0 });
	b_quit.SetPos({ 0,0,0 });

	b_jungle.SetPos({0,0,0});
	b_corruption.SetPos({ 0,0,0 });
	b_crimson.SetPos({ 0,0,0 });
	b_hallow.SetPos({ 0,0,0 });
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
	LoadGLTextures("UI", directory + "water.png"); // 1
	LoadGLTextures("UI", directory + "loading.png"); // 2
	LoadGLTextures("UI", directory + "instructions.png"); // 3	
	LoadGLTextures("UI", directory + "victory.png"); // 4
	LoadGLTextures("UI", directory + "defeat.png"); // 5

	LoadStoryTextures("story1", 161);

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
		else if (i >= 10 && i < 100)
		{
			LoadGLTextures("story", directory + "screen00" + id_pictures + ".png");
			cout << directory + "screen00" + id_pictures + ".png";

		}
		else if (i >= 100)
		{
			LoadGLTextures("story", directory + "screen0" + id_pictures + ".png");
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
	float ratio;
	float width;
	float height;
	//float heightPrev;
	float paddingV;
	//float paddingH;

	int sp = 100;
	curtF = (curtF + 1) % sp;
	int fr = curtF / sp;


	float bjunglPosX = windowWidth / 5.5f;
	float bPosYHaut = windowHeight / 7.0f;
	float bPosYBas = windowHeight / 2.0f;

	b_jungle.SetPos({ bjunglPosX,bPosYHaut,0 });
	b_corruption.SetPos({  bjunglPosX,bPosYBas,0 });
	b_crimson.SetPos({ 3* bjunglPosX,bPosYBas,0 });
	b_hallow.SetPos({ 4* bjunglPosX,bPosYHaut,0 });



	switch (screenID)
	{
//_________________________________________________________

	case 0:
		// 	TITLE
		ratio = 3.97;
		width = (windowWidth*40)/100.0;
		height = width/ratio;
		paddingV = windowHeight / 12;

		PrintImg((windowWidth/2) - (width/2), paddingV , height, width, UI, 0);		

		// Draw new game button
		// Update Ratio of button 1
		ratio = 5.93;
		width = (windowWidth * 20) / 100.0;
		height = width / ratio;

		b_newGame.SetPos({ (windowWidth / 2) - (width / 2), paddingV + 5.0f*height,0 });
		

		if ((b_newGame.GetPos().x) < player.GetPos().x && player.GetPos().x < (b_newGame.GetPos().x + width) // Horizontal zone
			&& 
			(b_newGame.GetPos().y) < player.GetPos().y && player.GetPos().y < (b_newGame.GetPos().y+ height)) // vertical zone
		{
			b_newGame.OnOver();
			b_newGame.Draw(height, width);


			if (click) 
			{
				ratio = 2;
				height = width / ratio;
				paddingV = windowHeight / 3;
				// Loading message
//				PrintImg((windowWidth / 2) - (width / 2), paddingV, height, width, UI, 2);

				screenID = 4;

			}
		}
		else

			b_newGame.Draw(height, width);


		// Update Ratio of button 2
		ratio = 6.66;
		width = (windowWidth * 20) / 100.0;
		height = width / ratio;

		b_loadGame.SetPos({ (windowWidth / 2) - (width / 2), paddingV + 8.0f*height,0 });

		// Draw load game button
		if ((b_loadGame.GetPos().x) < player.GetPos().x && player.GetPos().x < (b_loadGame.GetPos().x + width)
			&&
			(b_loadGame.GetPos().y) < player.GetPos().y && player.GetPos().y < (b_loadGame.GetPos().y + height))
		{
			b_loadGame.OnOver();
			b_loadGame.Draw(height, width);

			if (click)
			{
				screenID = 2;
			}
		}
		else
			b_loadGame.Draw( height, width);
		break;

//_________________________________________________________

	case 1:
		// 	MAP
		// Draw Water Sprite
		//for (int i = 0; i < 20; i++){
		//	for (int j = 0; j < 20; j++){
		//		PrintImg(0, 0, dim, dim + j, UI, 1);
		//	}
		//}

		// Draw load Jungle Island button
		// Update Ratio 
		ratio = 0.97;
		width = (windowWidth * 18) / 100.0;
		height = width / ratio;

		if ((b_jungle.GetPos().x) < player.GetPos().x && player.GetPos().x < (b_jungle.GetPos().x + width) // Horizontal zone
			&&
			(b_jungle.GetPos().y) < player.GetPos().y && player.GetPos().y < (b_jungle.GetPos().y + height)) // vertical zone
		{
			b_jungle.OnOver();
			b_jungle.Draw(height, width);

			if (click) 
			{
				screenID = 4;

				lvl.ChangeMap(1);
				inGame = true;
				hud.ResetTimer(180);
			}
		}
		else
			b_jungle.Draw (height, width);

		// Draw load Corruption Island button
		// Update Ratio 
		ratio = 1;
		height = width / ratio;

		if ((b_corruption.GetPos().x) < player.GetPos().x && player.GetPos().x < (b_corruption.GetPos().x + width) // Horizontal zone
			&&
			(b_corruption.GetPos().y) < player.GetPos().y && player.GetPos().y < (b_corruption.GetPos().y + height)) // vertical zone
		{
			b_corruption.OnOver();
			b_corruption.Draw(height, width);

			if (click)
			{
				screenID = 4;
				lvl.ChangeMap(2);
				inGame = true;
				hud.ResetTimer(180);

			}
		}
		else
			b_corruption.Draw(height, width);

		// Draw load Crimson Island button
		// Update Ratio 
		ratio = 1;
		height = width / ratio;

		if ((b_crimson.GetPos().x) < player.GetPos().x && player.GetPos().x < (b_crimson.GetPos().x + width) // Horizontal zone
			&&
			(b_crimson.GetPos().y) < player.GetPos().y && player.GetPos().y < (b_crimson.GetPos().y + height)) // vertical zone
		{
			b_crimson.OnOver();
			b_crimson.Draw(height, width);

			if (click)
			{
				screenID = 4;
				lvl.ChangeMap(3);
				inGame = true;
				hud.ResetTimer(180);
			}
		}
		else
			b_crimson.Draw(height, width);
			
		// Draw load Crimson Island button
		// Update Ratio 
		ratio = 0.99;
		height = width / ratio;


		if ((b_hallow.GetPos().x) < player.GetPos().x && player.GetPos().x < (b_hallow.GetPos().x + width) // Horizontal zone
			&&
			(b_hallow.GetPos().y) < player.GetPos().y && player.GetPos().y < (b_hallow.GetPos().y + height)) // vertical zone
		{
			b_hallow.OnOver();
			b_hallow.Draw(height, width);

			if (click)
			{
				screenID = 4;
				lvl.ChangeMap(4);
				inGame = true;
				hud.ResetTimer(180);
			}
		}
		else
			b_hallow.Draw(height, width);
		break;

//_________________________________________________________

	case 2:
		// LOAD GAME
		screenID = 1;

		break;

//_________________________________________________________

	case 3:
		// PAUSE

		// 	HELP
		ratio = 1.97;
		width = (windowWidth * 40) / 100.0;
		height = width / ratio;
		paddingV = windowHeight / 9;

		PrintImg((windowWidth / 2) - (width / 2), paddingV, height, width, UI, 3);



		// Draw new game button
		// Update Ratio of button 1
		ratio = 0.15;
		width = (windowWidth * 10) / 100.0;
		height = width / ratio;
		paddingV = windowHeight / 8;


		b_continue.SetPos({ (windowWidth / 2) - (width / 2), paddingV + 1.0f*height,0 });


		if ((b_continue.GetPos().x) < player.GetPos().x && player.GetPos().x < (b_continue.GetPos().x + width) // Horizontal zone
			&&
			(b_continue.GetPos().y) < player.GetPos().y && player.GetPos().y < (b_continue.GetPos().y + height)) // vertical zone
		{
			b_continue.OnOver();
			b_continue.Draw(width, height);

			if (click)
			{
				player.Teleport(p_prev_pos);
				inGame = true;
				screenID = 3;
			}
		}
		else
			b_continue.Draw(width, height);


		// Update Ratio of button 2
		ratio = 0.43;
		width = (windowWidth * 10) / 100.0;
		height = width / ratio;
		paddingV = windowHeight / 8;

		b_quit.SetPos({ (windowWidth / 2) - (width / 2), paddingV + 1.2f*height,0 });

		// Draw load game button
		if ((b_quit.GetPos().x) < player.GetPos().x && player.GetPos().x < (b_quit.GetPos().x + width) // Horizontal zone
			&&
			(b_quit.GetPos().y) < player.GetPos().y && player.GetPos().y < (b_quit.GetPos().y + height)) // vertical zone
		{
			b_quit.OnOver();
			b_quit.Draw(width, height);

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
			b_quit.Draw(width, height);
		break;

//_________________________________________________________

	case 4:
		// Story Screen
		DisplayStory(story.size());
		break;

	case 5:
		// Victory Screen
		sp = 100;
		curtF = (curtF + 1) % sp;
		fr = curtF / sp;


		ratio = 3.00;
		width = (windowWidth * 40) / 100.0;
		height = width / ratio;
		paddingV = windowHeight / 10;

		PrintImg((windowWidth / 2) - (width / 2), paddingV, height, width, UI, 3);

		if (fr == 100) {
			screenID = 1;
			fr = 0;
		}
		break;

	case 6:
		// Defeat Screen

		sp = 100;
		curtF = (curtF + 1) % sp;
		fr = curtF / sp;

		ratio = 3.00;
		width = (windowWidth * 40) / 100.0;
		height = width / ratio;
		paddingV = windowHeight / 10;

		PrintImg((windowWidth / 2) - (width / 2), paddingV, height, width, UI, 3);


		if (fr == 100) {
			screenID = 1;
			fr = 0;
		}
		break;
	}
	click = false;

}


void Menu::DisplayStory(int n_pictures)
{
	const int vitesse = 800;
	currentFrame = (currentFrame + 1) % vitesse;
	unsigned int frame = currentFrame * n_pictures / vitesse;

	const float center = (windowWidth / 2);
	const float sizeStory = (windowHeight * 90) / 100;
	const float Xmin = center - sizeStory/2 ;
	const float Xmax = center + sizeStory/2;
	const float Ymin = center - sizeStory / 2;
	const float Ymax = center + sizeStory / 2;

	glPushMatrix();
	// Story Screen
	glEnable(GL_TEXTURE_2D); // Start textures
	glBindTexture(GL_TEXTURE_2D, story[frame]);
	glBegin(GL_QUADS);

	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(Xmin, Ymin);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(Xmax, Ymin);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(Xmax, Ymax);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(Xmin, Ymax);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	if (frame == n_pictures - 1) {
		cout << "frame = " << frame;
		screenID = 1;
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
		player.Teleport({ 300,300,0 });

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


