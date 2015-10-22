#include "Weapon.h"



bool operator==(const Position &a, const Position &b)
{
	//return (a.x == b.x && a.y==b.y && a.z==b.z);
	float margin = 0.2;
	return (a.x <= (b.x+margin) && a.x >= (b.x-margin) && a.y <= (b.y + margin) && a.y >= (b.y - margin) && a.z == b.z);

}
bool operator!=(const Position &a, const Position &b)
{
	return !(a==b);
}

Weapon::Weapon()
{
}

void Weapon::DrawSprite(Position)
{
}

void Weapon::DrawFire()
{
}

int Weapon::LoadGLTextures(string name)
{
	//GLuint essai = SOIL_load_OGL_texture
	//	(
	//		name.c_str(),
	//		SOIL_LOAD_AUTO,
	//		SOIL_CREATE_NEW_ID,
	//		SOIL_FLAG_INVERT_Y
	//		);

	//textures.push_back(essai); // Add to the texture vector

	//if (textures.at(textures.size() - 1) == 0)
	//	return false;

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;       // Return Success
}


Weapon::~Weapon()
{
}
