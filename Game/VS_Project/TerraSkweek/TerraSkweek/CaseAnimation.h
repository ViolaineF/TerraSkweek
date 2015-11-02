#ifndef CASEANIMATION_H
#define CASEANIMATION_H

#include "Weapon.h"



class CaseAnimation
{
private : 
	Position m_pos; 
	int currentFrame;
	vector<GLuint> convertAnim;


public:
	bool Draw();
	int LoadGLTexture(string);
	CaseAnimation(int, int, string);
	~CaseAnimation();
};

#endif
