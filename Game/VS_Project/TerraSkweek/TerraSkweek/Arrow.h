#ifndef ARROW_H
#define ARROW_H

#include "Weapon.h"
#include "Player.h"

class Arrow : public Weapon
{

protected:
	bool activated;
	int timer;
	//vector<GLuint>	arrow;
	
public:
	void Draw();
	void activation(bool);
	Arrow();
	Arrow(float, float, bool, char);
	void LoadAllTextures();
	~Arrow();
};

#endif