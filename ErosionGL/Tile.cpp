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
    col = (_cliffcol - _maincol) / 256 * _cliff + _maincol;

    // градієнт висоти
    col.r *= (_height / 256);
    col.g *= (_height / 256);
    col.b *= (_height / 256);
    return col;
}
