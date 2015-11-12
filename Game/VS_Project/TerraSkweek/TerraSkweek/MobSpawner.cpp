#include "MobSpawner.h"



bool MobSpawner::Draw()
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
		glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x - m_spriteSize, m_pos.y - m_spriteSize);
		glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x + m_spriteSize, m_pos.y - m_spriteSize);
		glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x + m_spriteSize, m_pos.y + m_spriteSize);
		glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x - m_spriteSize, m_pos.y + m_spriteSize);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glutPostRedisplay();

		// when the animation is complete, convert entirely
		if (frame >= (animation.size() - 1)) {
			animated = false;
			return 0;
		}
		return 1;
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
		glTexCoord2f(1.0f, 1.0f); glVertex2d(m_pos.x - m_spriteSize, m_pos.y - m_spriteSize);
		glTexCoord2f(0.0f, 1.0f); glVertex2d(m_pos.x + m_spriteSize, m_pos.y - m_spriteSize);
		glTexCoord2f(0.0f, 0.0f); glVertex2d(m_pos.x + m_spriteSize, m_pos.y + m_spriteSize);
		glTexCoord2f(1.0f, 0.0f); glVertex2d(m_pos.x - m_spriteSize, m_pos.y + m_spriteSize);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glutPostRedisplay();
		return 0;

	}

}

MobSpawner::MobSpawner(float x, float y, string directory) : SpecialCase(x, y, directory)
{
	animated = false; 

	string fullDirectory = "Art/" + directory;

	LoadGLTexture(fullDirectory + "/0.png");
	LoadGLTexture(fullDirectory + "/1.png");
	LoadGLTexture(fullDirectory + "/2.png");
	LoadGLTexture(fullDirectory + "/3.png");
	LoadGLTexture(fullDirectory + "/4.png");
	LoadGLTexture(fullDirectory + "/5.png");
	LoadGLTexture(fullDirectory + "/6.png");
	LoadGLTexture(fullDirectory + "/7.png");
	LoadGLTexture(fullDirectory + "/7.png");
	LoadGLTexture(fullDirectory + "/6.png");
	LoadGLTexture(fullDirectory + "/5.png");
	LoadGLTexture(fullDirectory + "/4.png");
	LoadGLTexture(fullDirectory + "/3.png");
	LoadGLTexture(fullDirectory + "/2.png");
	LoadGLTexture(fullDirectory + "/1.png");
	LoadGLTexture(fullDirectory + "/0.png");
}


MobSpawner::~MobSpawner()
{
}
