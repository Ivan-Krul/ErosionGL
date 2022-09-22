#pragma once
#include "RGB.h"
#include <stdlib.h>
class Tile
{
	RGB _maincol = { 29, 196, 74 };
	RGB _cliffcol = { 237, 245, 122 };
	unsigned char _height;
	unsigned char _cliff;
public:
	Tile() = default;
	Tile(unsigned char height_, unsigned char cliff_);
	Tile(RGB maincol_, RGB cliffcol_);
	void generatecliff(float *tile_, unsigned char size_);
	unsigned char &height();
	unsigned char &cliff();
	RGB maincol();
	RGB cliffcol();
	RGB torgb();
};
