#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "texture2D.h"

class Sprite final
{
public:
	Sprite(const Texture2D &texture, int originX, int originY, int width, int height);
	~Sprite();

	Texture2D mTexture;
	float *texCoords;
	int GetWidth() const;
	int GetHeight() const;

private:
	 const int numVertices = 12;
	 int mWidth;
	 int mHeight;
	 
};
#endif