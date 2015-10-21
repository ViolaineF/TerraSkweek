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
	int m_screen;
	int m_selected;
	int m_score;
	int m_timer;

public:
	void SaveGame();
	void LoadGame();
	void NewGame();
	//void DisplayMap();
	void HUD();
	void Pause();
	void EndGame();
	Grid();
	~Grid();
};


#endif