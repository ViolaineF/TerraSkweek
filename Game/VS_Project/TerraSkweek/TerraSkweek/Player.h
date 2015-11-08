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
	vector<GLuint>	p_UI;
	bool m_moving;
	float opacity;
	bool m_powderbag;
	bool m_invincible;
	bool m_mouseMode;
	bool m_stillMoving;

public:
	void setOpacity(float);
	//bool IsVisible();

	void LoadAllTextures();
	int LoadGLTextures(string, string);

	void Draw(bool);
	void SetMoving(bool);
	void SetStillMoving(bool);
	bool IsStillMoving();
	bool IsMoving();

	void SetWeapon(int);
	bool IsFiring();

	void SetPowderBag(bool);
	bool HasPowderBag();

	void SetInvincible(bool);
	bool IsInvincible();

	Player();
	~Player();
};

#endif