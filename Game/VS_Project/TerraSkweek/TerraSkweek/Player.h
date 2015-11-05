#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"


class Player : public Entity
{
private : 
	//string m_name;
	vector<GLuint>	idle;
	vector<GLuint>	left;
	vector<GLuint>	up;
	vector<GLuint>	down;
	vector<GLuint>	fire_idle;
	vector<GLuint>	fire_left;
	vector<GLuint>	fire_up;
	vector<GLuint>	fire_down;
	bool m_moving;
	float opacity;
	bool m_powderbag;
	bool m_invincible;

public:
	void setOpacity(float);
	void LoadAllTextures();
	int LoadGLTextures(string, string);

	void Draw();
	void SetMoving(bool);

	void SetWeapon(int);
	bool IsMoving();
	bool IsFiring();

	void SetPowderBag(bool);
	bool HasPowderBag();

	void SetInvincible(bool);
	bool IsInvincible();

	Player();
	~Player();
};

#endif