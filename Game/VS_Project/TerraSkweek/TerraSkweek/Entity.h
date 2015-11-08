#ifndef ENTITY_H
#define ENTITY_H

#include "Weapon.h"

class Entity
{
protected :
	Position m_pos;
	int currentFrame;
	int m_life;
	int m_def;
	char m_dir;
	float m_speed;
	AudioFile s_hurt;
	AudioFile s_death;
	Weapon m_weapon;
	bool m_firing;
	bool m_death;
	float m_spriteSize;

public:
	Entity();
	Entity(Position, int, int, char, Weapon, AudioFile, AudioFile);

	void SwitchDir(char);
	char GetDir();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Teleport(Position);

	void SetSpeed(float);

	int GetLife();
	int GetWeapon();

	bool IsDead();
	void SetLife(int);

	Position GetPos();

	void Attack();
	//void Death();


	~Entity();
};

#endif

