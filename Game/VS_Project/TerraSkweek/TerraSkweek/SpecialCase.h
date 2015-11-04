#ifndef SPECIALCASE_H
#define SPECIALCASE_H

#include "Weapon.h"



class SpecialCase
{
protected : 
	Position m_pos; 
	int currentFrame;
	vector<GLuint> animation;
	bool animated;


public:
	virtual void Somthg();
	bool Draw();
	void SetAnimated(bool);
	bool IsAnimated();
	Position GetPos();
	int LoadGLTexture(string);
	SpecialCase(int, int, string);
	~SpecialCase();
};

#endif
