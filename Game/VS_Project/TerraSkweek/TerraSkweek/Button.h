#ifndef BUTTON_H
#define BUTTON_H

#include "weapon.h"

class Button
{
private:
	Position b_pos;
	AudioFile b_click;
	vector<GLuint> state;
	float dim;
	bool over;

public:
	void LoadAllTextures(string);
	int LoadGLTextures(string);
	Position GetPos();
	void SetPos(Position);
	void OnOver();
	void Draw(float, float);
	Button(double);
	~Button();
};

#endif