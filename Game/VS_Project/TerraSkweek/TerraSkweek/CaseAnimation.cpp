#include "CaseAnimation.h"



bool CaseAnimation::Draw(bool animated)
{
	const int speed = 1200;

	if (animated) {

		currentFrame = (currentFrame + 1) % speed;
		unsigned int frame = currentFrame * (convertAnim.size()) / speed;

		glPushMatrix();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, convertAnim[frame]);
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
		if (frame >= (convertAnim.size() - 1)) {

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
		glBindTexture(GL_TEXTURE_2D, convertAnim[0]);
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

Position CaseAnimation::GetPos()
{
	return m_pos;
}

int CaseAnimation::LoadGLTexture(string name)
{

	GLuint essai = SOIL_load_OGL_texture
		(
			name.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	convertAnim.push_back(essai); // Add to the texture vector

	if (convertAnim.at(convertAnim.size() - 1) == 0)
		return false;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	return true;       // Return Success
}

CaseAnimation::CaseAnimation(int x, int y, string directory)
{
	currentFrame = 0;
	float posX = x + 0.0;
	float posY = y + 0.0;
	m_pos = {posX, posY};
	convertAnim.resize(0);

	string fullDirectory = "Art/" + directory; 

	LoadGLTexture(fullDirectory + "/1.png");
	LoadGLTexture(fullDirectory + "/2.png");
	LoadGLTexture(fullDirectory + "/3.png");
	LoadGLTexture(fullDirectory + "/4.png");
	LoadGLTexture(fullDirectory + "/5.png");
	LoadGLTexture(fullDirectory + "/6.png");
	LoadGLTexture(fullDirectory + "/7.png");


}


CaseAnimation::~CaseAnimation()
{
}
