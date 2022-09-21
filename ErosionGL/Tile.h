#pragma once
#include "RGB.h"
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
	unsigned char &height();
	unsigned char &cliff();
	RGB maincol();
	RGB cliffcol();
	RGB torgb();
};

