#include "MapTile.h"

void MapTile::_create(suze sizex_, suze sizey_)
{
	if(_sizex * _sizey == 0) return;
	_sizex = sizex_;
	_sizey = sizey_;
	_map = new Tile[_sizex * _sizey];
}

void MapTile::_delete()
{
	delete[] _map;
	_sizex = 0;
	_sizey = 0;
}

void MapTile::updatecliff()
{
	for(suze x = 0;x <_sizex;x++)
	{
		for(suze y = 0; y < _sizey; y++)
		{
			std::vector<float> list;
			for(char dx = -1; dx < 2; dx++)
				for(char dy = -1; dy < 2; dy++)
					if(isinmap(x+dx,y+dy))
						list.push_back(_map[(x + dx) + (y + dy) * _sizex].height());
			_map[x + y * _sizex].generatecliff((float *)list.data(),list.size());
		}
	}
}

bool MapTile::isinmap(suze x_, suze y_)
{
	return (0<= x_) && (x_ < _sizex) && (0 <= y_) && (x_ < _sizey);
}

Tile &MapTile::operator[](size index_)
{
	if(!(0 <= index_ && index_ < size(_sizex) * _sizey))
	{
		_delete();
		printf("%s: Index is out of range", __FUNCTION__);
		abort();
	}
	return _map[index_];
}
