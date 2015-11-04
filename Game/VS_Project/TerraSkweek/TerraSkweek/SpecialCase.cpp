#include "SpecialCase.h"




bool SpecialCase::Draw()
{
	const int speed = 400;

	if (animated) {

		currentFrame = (currentFrame + 1) % speed;
		unsigned int frame = currentFrame * (animation.size()) / speed;

		glPushMatrix();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, animation[frame]);
		glBegin(GL_QUADS);
		glColor3d(1.0, 1.0, 1.0);
		glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x, m_pos.y);
		glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x + 1, m_pos.y);
		glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x + 1, m_pos.y + 1);
		glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x, m_pos.y + 1);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glutPostRedisplay();

		// when the animation is complete, convert entirely
		if (frame >= (animation.size() - 1)) {

			cout << "anim ended" << endl;
			return 1;
		}
		else {
			return 0;
		}
	}
	else {

		glPushMatrix();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, animation[0]);
		glBegin(GL_QUADS);
		glColor3d(1.0, 1.0, 1.0);
		glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x, m_pos.y);
		glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x + 1, m_pos.y);
		glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x + 1, m_pos.y + 1);
		glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x, m_pos.y + 1);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glutPostRedisplay();
		return 0;

	}

}

void SpecialCase::SetAnimated(bool anim)
{
	animated = anim;
}

bool SpecialCase::IsAnimated()
{
	return animated;
}

Position SpecialCase::GetPos()
{
	return m_pos;
}

int SpecialCase::LoadGLTexture(string name)
{

	GLuint essai = SOIL_load_OGL_texture
		(
			name.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	animation.push_back(essai); // Add to the texture vector

	if (animation.at(animation.size() - 1) == 0)
		return false;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	return true;       // Return Success
}

SpecialCase::SpecialCase(int x, int y, string directory)
{
	currentFrame = 0;
	float posX = x + 0.0;
	float posY = y + 0.0;
	m_pos = {posX, posY};
	animation.resize(0);

}




SpecialCase::~SpecialCase()
{
}
