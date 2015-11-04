#include "CrackedFloor.h"



void CrackedFloor::Somthg()
{

}

CrackedFloor::CrackedFloor(int x, int y , string directory) : SpecialCase(x, y, directory)
{

	animated = false;

	string fullDirectory = "Art/" + directory;

	LoadGLTexture(fullDirectory + "/1.png");
	LoadGLTexture(fullDirectory + "/2.png");
	LoadGLTexture(fullDirectory + "/3.png");
	LoadGLTexture(fullDirectory + "/4.png");
	LoadGLTexture(fullDirectory + "/5.png");

}


CrackedFloor::~CrackedFloor()
{
}
