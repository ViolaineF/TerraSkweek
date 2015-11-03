#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <time.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string>
#include <vector>
#include <ctype.h>
#include "GL\glut.h"
#include "SOIL\SOIL.h"

using namespace std;

class HUD
{
private:
	int Level;
	int LevelScore = 0, totalScore = 0, previousScore = 0, frag = 0;
	int timer = 180;
	int t_unite = timer % 10;
	int t_dizaine = timer / 10 % 10;
	int t_centaine = timer / 100 % 10;
	vector<int> timerTab{ 1,8,0};
	vector<int> scoreTab{ 0,0,0,0,0,0,0};
	vector<GLuint> nbrs;
	vector<GLuint> infos;
	vector<GLuint> icons;

public:
	void displayScore(float, int);
	void LoadAllTextures();
	void PrintImg(int, int, int, int, vector<GLuint>, int);
	void PrintLife(int, int, int, int, int, float);
	void checkTimer(int);
	int LoadGLTextures(string, string);
	HUD();
};

