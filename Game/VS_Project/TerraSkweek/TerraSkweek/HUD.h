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
	int timer;
	std::vector<int> scoreTab{ 0,0,0,0 };
	std::vector<GLuint>	nbrs;
	std::vector<GLuint>	infos;
	std::vector<GLuint>	icons;

public:
	void displayScore(int, int);
	void LoadAllTextures();
	void PrintImg(int, int, int, int, vector<GLuint>, int);
	int LoadGLTextures(string, string);
	HUD();
};

