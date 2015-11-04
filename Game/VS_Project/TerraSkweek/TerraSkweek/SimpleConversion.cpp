#include "SimpleConversion.h"



SimpleConversion::SimpleConversion(int x, int y, string directory) : SpecialCase(x, y, directory)
{
	animated = true;

	string fullDirectory = "Art/" + directory;

	LoadGLTexture(fullDirectory + "/1.png");
	LoadGLTexture(fullDirectory + "/2.png");
	LoadGLTexture(fullDirectory + "/3.png");
	LoadGLTexture(fullDirectory + "/4.png");
	LoadGLTexture(fullDirectory + "/5.png");
	LoadGLTexture(fullDirectory + "/6.png");
	LoadGLTexture(fullDirectory + "/7.png");
}


SimpleConversion::~SimpleConversion()
{
}
