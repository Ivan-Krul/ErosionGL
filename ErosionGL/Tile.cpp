#include "Tile.h"

Tile::Tile(unsigned char height_)
{
	_height = height_;
}

Tile::Tile(unsigned char height_, unsigned char water_)
{
	_height = height_;
	_water = water_;
}

Tile::Tile(RGB maincol_, RGB cliffcol_)
{
	_maincol = maincol_;
	_cliffcol = cliffcol_;
}

void Tile::generatecliff(float *tile_, unsigned char size_)
{
	const float multiply = 0.75;
	float avrg = 0;
	for(int i = 0; i < size_; i++)
		avrg += tile_[i];
	avrg /= size_;
	avrg *= 256;
	_cliff = abs(int(avrg) - int(_height));
}

// спершу шукаємо найнижчу сумарну висоту,...
// потім, після того, як визначили тайл з мілімальною сумарною висотою...
// наливаємо стільки, щоб у 2 тайлів було середнє значення сумарних висот

unsigned char &Tile::height()
{
	return _height;
}

unsigned char &Tile::cliff()
{
	return _cliff;
}

unsigned char &Tile::water()
{
	return _water;
}

unsigned int Tile::sumheight()
{
	return _height + _water;
}

RGB Tile::maincol()
{
	return _maincol;
}

RGB Tile::cliffcol()
{
	return _cliffcol;
}

RGB Tile::torgb()
{
	RGB col = {0,0,0};
	// задання скелі чи додавання води
	if(_water == 0)
	{
		col.r = float(_cliffcol.r - _maincol.r) / 256.0f * _cliff + _maincol.r;
		col.g = float(_cliffcol.g - _maincol.g) / 256.0f * _cliff + _maincol.g;
		col.b = float(_cliffcol.b - _maincol.b) / 256.0f * _cliff + _maincol.b;
	}
	else
	{
		col.r = float(_watercol.r - col.r) / 256.0f * _water + col.r;
		col.g = float(_watercol.g - col.g) / 256.0f * _water + col.g;
		col.b = float(_watercol.b - col.b) / 256.0f * _water + col.b;
	}
	// градієнт висоти
	col.r = float(_height) / 256.0f * float(col.r);
	col.g = float(_height) / 256.0f * float(col.g);
	col.b = float(_height) / 256.0f * float(col.b);
	return col;
}
