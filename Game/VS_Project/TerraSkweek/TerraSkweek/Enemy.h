#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
//#include "Player.h"

class Enemy : public Entity
{
protected :
	bool afraid;
	bool m_freeze;
	int m_damage;
	bool m_random; // Move randomly when the player is transparent enough
	int m_randomIt; // Allow the enemy to follow a direction for a given number of moves before choosing a new random one
	int currentFrame; // Needed to play the animations
	vector<GLuint>	run;
	vector<GLuint>	death;
	vector<GLuint>	freeze;

public:
	Enemy();
	Enemy(Position);

	int LoadGLTextures(string, string);
	virtual void LoadAllTextures();

	bool Move(Position, float);
	int GetDamage();
	void Draw();

	void SetFreeze(bool);
	bool IsFreezed();

	~Enemy();
};

#endif


