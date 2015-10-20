#ifndef TEXTURE_H
#define TEXTURE_H


#include <string>
#include <vector>
#include "GL\glut.h"
#include "SOIL\SOIL.h"
using namespace std; 

class Texture
{
private:
	std::vector<GLuint>	texture;

public:
	Texture(int, string);
	int LoadGLTextures(string);
};

#endif

