#include "Menu.h"

extern Grid lvl;

Menu::Menu()
{
	//------------------LOADING UI TEXTURES

}



void Menu::LoadAllTextures()
{
	string directory = "Art/UI";

	//--------------BASE TEXTURES
	LoadGLTextures("button", directory + "new_game_idle.png"); // 0
	LoadGLTextures("button", directory + "new_game_over.png"); // 1
	LoadGLTextures("button", directory + "load_game_idle.png"); // 2
	LoadGLTextures("button", directory + "load_game_over.png"); // 3

	LoadGLTextures("UI", directory + "title.png"); // 1
	LoadGLTextures("UI", directory + "water.png"); // 2
	LoadGLTextures("UI", directory + "Islands.png"); // 3
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

	else if (type == "button")
	{
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		button.push_back(essai); // Add to the texture vector

		if (button.at(button.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
	}

}

void Menu::Display()
{

}

Menu::~Menu()
{
}


