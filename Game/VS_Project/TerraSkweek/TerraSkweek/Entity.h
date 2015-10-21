#ifndef ENTITY_H
#define ENTITY_H

#include "Weapon.h"

class Entity
{
private:
	Position m_pos;
	int m_life;
	int m_def;
	int m_dir;
	float m_speed;
	AudioFile s_hurt;
	AudioFile s_death;
	Weapon m_weapon;
	std::vector<GLuint>	idle;

public:
	Entity();
	Entity(Position, int, int, int, Weapon, AudioFile, AudioFile);
	int LoadGLTextures(string, string);
	void Draw();
	void SwitchDir(int);
	int GetDir();
	void SetLife(int);
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Teleport(Position);
	Position GetPos();
	void Attack();
	void Death();


	~Entity();
};

#endif

