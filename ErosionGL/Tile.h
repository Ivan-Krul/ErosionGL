#pragma once
#include "RGB.h"
#include <stdlib.h>
#include <algorithm>
class Tile
{
	typedef unsigned char byte;
	//RGB _maincol = { 29, 196, 74 };
	//RGB _cliffcol = { 237, 245, 122 };
	RGB _maincol = { 0, 255, 0 };
	RGB _cliffcol = { 0, 255, 0 };
	RGB _watercol = { 0, 0, 255 };
	byte _height = 0;
	byte _cliff = 0;
	byte _water = 0;
public:
	Tile() = default;
	Tile(byte height_);
	Tile(byte height_, byte water_);
	Tile(RGB maincol_, RGB cliffcol_);
	void generatecliff(byte *tile_, byte size_);
	byte &height();
	byte &cliff();
	byte &water();
	unsigned short sumheight();
	RGB maincol();
	RGB cliffcol();
	RGB torgb();
};
