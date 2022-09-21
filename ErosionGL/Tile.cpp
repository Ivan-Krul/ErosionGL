#include "Tile.h"

Tile::Tile(unsigned char height_, unsigned char cliff_)
{
    _height = height_;
    _cliff = cliff_;
}

Tile::Tile(RGB maincol_, RGB cliffcol_)
{
    _maincol = maincol_;
    _cliffcol = cliffcol_;
}

unsigned char &Tile::height()
{
    return _height;
}

unsigned char &Tile::cliff()
{
    return _cliff;
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
    // задання скелі
    col.r = float(_cliffcol.r - _maincol.r) / 256.0f * _cliff + _maincol.r;
    col.g = float(_cliffcol.g - _maincol.g) / 256.0f * _cliff + _maincol.g;
    col.b = float(_cliffcol.b - _maincol.b) / 256.0f * _cliff + _maincol.b;
    // градієнт висоти
    col.r = float(_height) / 256.0f * float(col.r);
    col.g = float(_height) / 256.0f * float(col.g);
    col.b = float(_height) / 256.0f * float(col.b);
    return col;
}
