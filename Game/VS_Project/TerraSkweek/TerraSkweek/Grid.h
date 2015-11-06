#ifndef GRID_H
#define GRID_H

#include <typeinfo>
#include "HUD.h"
#include "Player.h"
#include "TNT.h"
#include "Arrow.h"
#include "Corruptor_Corruption.h"
#include "Crimera_Crimson.h"
#include "DemonEye_Forest.h"
#include "Devourer_Corruption.h"
#include "FaceMonster_Crimson.h"
#include "Gastopod_Hallow.h"
#include "Pixie_Hallow.h"
#include "Slime_Corruption.h"
#include "Slime_Crimson.h"
#include "Slime_Forest.h"
#include "Unicorn_Hallow.h"
#include "Zombie_Forest.h"
#include "SpecialCase.h"
#include "SimpleConversion.h"
#include "SemiConverted.h"
#include "CrackedFloor.h"
#include "MobSpawner.h"

class Grid
{
private:
	string m_biome;
	int m_screen;
	int m_selected;
	int m_score;
	int m_timer;
	int m_rows;
	int m_lignes;
	int map[20][20];
	Position p_prev_pos;
	unsigned int m_spawnerIndex;
	unsigned int m_maxMobs;
	vector<GLuint> textures;
	vector<SpecialCase*> vecCaseAnimated;
	vector<SpecialCase*> vecSpawner;
	vector<Enemy*> vecEnemies;
	vector<TNT*> vecTNT;
	vector<Arrow*> vecArrow;
	vector<Weapon*> vecWeapons;
	AudioFile sfx_e_death{ "Ennemy_death.wav", 1 };
	AudioFile sfx_e_fire{ "ennemy_shoot.wav", 1 };
	AudioFile sfx_loot{ "Powerup.wav", 1 };
	AudioFile sfx_gap{ "timer_explosion.wav", 1 };
	AudioFile sfx_bullet_hit{ "explosion.wav", 1 };
	AudioFile sfx_hit{ "Hit_Hurt.wav", 1 };


public:
	int Map(int, int); // return map values
	void SetMap(int, int, int);
	void LoadAllTextures();
	int LoadGLTextures(string);
	void PrintImg(float, float, float, float, int);
	void DisplayMap();
	void ChangeMap(int);
	void DrawSpecialCases();
	void DrawEnemies();
	void MoveAllEnemies();

	void SpawnMob();

	void NewFire(int, char, Position);
	void MoveAllFires();
	void DrawAllFires();

	void SaveGame(string);
	void LoadGame(string);
	void NewGame(string);

	void Redim(int, int); //not used RN
	int HUD_Score();
	void Pause();
	void EndGame();

	Grid(string);
	~Grid();
};


#endif