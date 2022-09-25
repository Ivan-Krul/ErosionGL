#pragma once
#include "RGB.h"
#include <stdlib.h>
#include <algorithm>
class Tile
{
	RGB _maincol = { 29, 196, 74 };
	RGB _cliffcol = { 237, 245, 122 };
	RGB _watercol = { 0, 0, 255 };
	unsigned char _height = 0;
	unsigned char _cliff = 0;
	unsigned char _water = 0;
public:
	Tile() = default;
	Tile(unsigned char height_);
	Tile(unsigned char height_, unsigned char water_);
	Tile(RGB maincol_, RGB cliffcol_);
	void generatecliff(float *tile_, unsigned char size_);
	unsigned char &height();
	unsigned char &cliff();
	unsigned char &water();
	unsigned int sumheight();
	RGB maincol();
	RGB cliffcol();
	RGB torgb();
};
