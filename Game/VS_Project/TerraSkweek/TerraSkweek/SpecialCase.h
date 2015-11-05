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
	float m_spriteSize;
	char m_type;


public:
	virtual bool Draw();
	void SetAnimated(bool);
	bool IsAnimated();
	Position GetPos();
	char GetType();
	int LoadGLTexture(string);
	SpecialCase(int, int, string);
	SpecialCase(Position, string);
	~SpecialCase();
};

#endif
