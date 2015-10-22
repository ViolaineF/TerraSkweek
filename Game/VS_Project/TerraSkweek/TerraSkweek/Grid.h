#ifndef GRID_H
#define GRID_H

#include "Player.h"
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
	int map[10][10];
	vector<GLuint>	textures;
	vector<Enemy*> vecEnemies;
	//vector<Player> vecPlayers;

public:
	int Map(int, int); // return map values
	void SetMap(int, int, int);
	void LoadAllTextures();
	int LoadGLTextures(string);
	void PrintImg(int, int, int, int, int);
	void DisplayMap();

	void DrawEnemies();
	void MoveAllEnemies();

	void SaveGame(string);
	void LoadGame(string);
	void NewGame(string);

	void Redim(int, int); //not used RN
	void HUD();
	void Pause();
	void EndGame();

	Grid(string);
	~Grid();
};


#endif