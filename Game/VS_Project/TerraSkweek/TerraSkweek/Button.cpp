#include "Button.h"


Button::Button(double d)
{
	dim = d;
	b_pos.x = 0;
	b_pos.y = 0;
	b_pos.z = 0;
	over = false;
}


void Button::LoadAllTextures(string name)
{
	LoadGLTextures("Art/UI/" + name + "_idle.png"); // Idle sprite
	LoadGLTextures("Art/UI/" + name + "_over.png"); // Over sprite
}

int Button::LoadGLTextures(string name)
{
		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		state.push_back(essai); // Add to the texture vector
		if (state.at(state.size() - 1) == 0)
			return false;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return true;       // Return Success
}


Position Button::GetPos()
{
	return b_pos;
}

void Button::SetPos(Position a)
{
	b_pos = a;
}

void Button::OnOver()
{
	over = true;
}

void Button::Draw(float width, float height)
{

	glEnable(GL_TEXTURE_2D); // Start textures
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if (over)
		glBindTexture(GL_TEXTURE_2D, state[1]);
	else
		glBindTexture(GL_TEXTURE_2D, state[0]);		
	glBegin(GL_QUADS);

	glColor4d(1.0, 1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(b_pos.x, b_pos.y);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(b_pos.x + height, b_pos.y);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(b_pos.x + height, b_pos.y + width);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(b_pos.x, b_pos.y + width);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	over = false;

}


Button::~Button()
{
}
