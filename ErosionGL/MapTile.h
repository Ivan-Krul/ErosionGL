#pragma once
#include "Tile.h"
#include <vector>
class MapTile
{
	typedef unsigned long size;
	typedef unsigned short suze;
	suze _sizex = 0;
	suze _sizey = 0;
	Tile *_map;
	void _create(suze sizex_, suze sizey_);
	void _delete();
public:
	MapTile(suze sizex_, suze sizey_)
	{
		_create( sizex_,  sizey_);
	}
	void updatecliff();
	bool isinmap(suze x_,suze y_);
	Tile &operator[](size index_);
	~MapTile()
	{
		_delete();
	}
};

