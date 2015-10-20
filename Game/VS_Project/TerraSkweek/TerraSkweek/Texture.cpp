#include "Texture.h"

Texture::Texture(int n, string name)
{

	for (int i = 0; i < n; i++ ) {
		LoadGLTextures(name);
	}

}

int Texture::LoadGLTextures(std::string name) // Load Bitmaps And Convert To Textures
{
	GLuint essai = SOIL_load_OGL_texture
		(
			name.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	texture.push_back(essai); // Add to the texture vector

	if (texture.at(texture.size() - 1) == 0)
		return false;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;       // Return Success
}