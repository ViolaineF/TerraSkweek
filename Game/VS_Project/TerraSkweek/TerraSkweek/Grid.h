#ifndef GRID_H
#define GRID_H

#include <typeinfo>
#include "HUD.h"
#include "Player.h"
#include "TNT.h"
#include "Arrow.h"
#include "DemonEye_Forest.h"
#include "Slime_Forest.h"
#include "Bunny_Forest.h"
#include "SpecialCase.h"
#include "SimpleConversion.h"
#include "SemiConverted.h"
#include "CrackedFloor.h"
#include "MobSpawner.h"
#include "UpCase.h"

using namespace std;

class Grid
{
private:
	int m_tiles;
	int m_screen;
	int m_selected;
	int m_score;
	int m_timer;
	int m_rows;
	int m_lignes;
	int map[20][20];
	unsigned int m_spawnerIndex;
	unsigned int m_maxMobs;
	vector<GLuint> textures;
	vector<SpecialCase*> vecCaseAnimated;
	vector<SpecialCase*> vecSpawner;
	vector<SpecialCase*> vecUpCase;
	vector<Enemy*> vecEnemies;
	vector<TNT*> vecTNT;
	vector<Arrow*> vecArrow;
	vector<Weapon*> vecWeapons;

	AudioFile bgm_menu{ "Menu_bgm.wav", 0 };
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
	void ClearMap();
	void ChangeMap(int);

	void LoadObjectsOnMap();

	void DrawSpecialCases();
	void DrawUpCase();

	void DrawEnemies();
	void MoveAllEnemies();
	void SpawnMob();
	void SetEnemiesSpeed(float);

	void NewFire(int, char, Position);
	void MoveAllFires();
	void DrawAllFires();

	void SaveGame(string);
	void LoadGame(string);
	void NewGame(string);

	void Redim(int, int); //not used RN
	int HUD_Score();
	void EndGame();

	Grid(string);
	~Grid();
};


#endif