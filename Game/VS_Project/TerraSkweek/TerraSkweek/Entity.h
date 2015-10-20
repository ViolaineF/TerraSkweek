#ifndef ENTITY_H
#define ENTITY_H

#include "Weapon.h"

class Entity
{
private:
	position m_pos;
	int m_life;
	int m_def;
	int m_dir;
	AudioFile s_hurt;
	AudioFile s_death;
	Weapon m_weapon;
	std::vector<GLuint>	idle;

public:
	Entity();
	int LoadGLTextures(string);
	void Draw();
	void SetLife();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Teleport(position);
	void GetPos();
	void Attack();
	void Death();
	void DefineEntity(position, int, int, int, Weapon, AudioFile, AudioFile);

	~Entity();
};

#endif

