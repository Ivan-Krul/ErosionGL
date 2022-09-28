#pragma once
#include "Tile.h"
#include <vector>
class MapTile
{
	typedef unsigned long soze;
	typedef unsigned short suze;
	typedef unsigned char byte;
	typedef struct
	{
		suze x, y;
	} point;
	point _size;
	Tile *_map;
	void _create(suze sizex_, suze sizey_);
	void _delete();
public:
	MapTile(suze sizex_, suze sizey_)
	{
		_create(sizex_, sizey_);
	}
	void updatecliff();
	bool isinmap(suze x_, suze y_);
	void updateheight(float *arr_, soze size_);
	void updateonedirwater();
	void updategravitywater();
	Tile &operator[](soze index_);
	point size();
	~MapTile()
	{
		_delete();
	}
};

