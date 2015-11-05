#include "Menu.h"





Menu::Menu()
{
	//------------------LOADING UI TEXTURES
	LoadGLTextures("");

}



void Menu::LoadAllTextures()
{
	lvl01.LoadAllTextures();

}

int Menu::LoadGLTextures(string name)
{
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



Menu::~Menu()
{
}


