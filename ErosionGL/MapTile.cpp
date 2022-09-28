#include "MapTile.h"

void MapTile::_create(suze sizex_, suze sizey_)
{
	_size = { sizex_,sizey_ };
	_map = new Tile[_size.x * _size.y];
}

void MapTile::_delete()
{
	delete[] _map;
	_size = {0,0};
}

void MapTile::updatecliff()
{
	std::vector<unsigned char> list;
	list.reserve(9);
	for(suze x = 0;x <_size.x;x++)
	{
		for(suze y = 0; y < _size.y; y++)
		{
			list.clear();
			for(short dx = -1; dx < 2; dx++)
				for(short dy = -1; dy < 2; dy++)
					if(isinmap( x + dx,y + dy))
						list.push_back(_map[(x + dx) + (y + dy) * _size.x].height());
			_map[x + y * _size.y].generatecliff(list.data(),list.size());
		}
	}
}

bool MapTile::isinmap(suze x_, suze y_)
{
	return (0<= x_) && (x_ < _size.x) && (0 <= y_) && (y_ < _size.y);
}

void MapTile::updateheight(float *arr_, soze size_)
{
	for(soze index = 0; index < size_; index++)
	{
		_map[index].height() = arr_[index] * 256.0f;
	}
}

void MapTile::updateonedirwater()
{
	Tile *map = new Tile[_size.x * _size.y];
	soze minindex = 0;
	soze curindex = 0;
	for(soze i = 0; i < _size.x * _size.y; i++)
	{
		map[i].height() = _map[i].height();
		map[i].cliff() = _map[i].cliff();
		map[i].water() = 0;
	}
	for(suze x = 0; x < _size.x; x++)
	{
		for(suze y = 0; y < _size.y; y++)
		{
			// спершу шукаємо найнижчу сумарну висоту,...
			// потім, після того, як визначили тайл з мілімальною сумарною висотою...
			// наливаємо стільки, щоб у 2 тайлів було середнє значення сумарних висот
			curindex = x + y * _size.x;
			minindex = x + y * _size.x;
			for(char dx = -1; dx < 2; dx++)
				for(char dy = -1; dy < 2; dy++)
					if(isinmap(x + dx, y + dy))
						if(_map[minindex].sumheight() > _map[(x + dx) + (y + dy) * _size.x].sumheight())
							minindex = (x + dx) + (y + dy) * _size.x;
			if(curindex == minindex)
			{ 
				map[curindex].water() = _map[curindex].water();
				continue;
			}
			if(_map[curindex].water() == 0) continue;
			// ми маємо T0 і T1
			// у нас є багато випадків, як ми можемо переливати воду, а саме:
			//  - коли у Т0.земля є настільки високим, що аж свою воду помістить до іншого тайла (Т0.земля > T1.сума)
			//  - коли у Т0.земля є не настільки високим, що може помістити частину води (Т0.земля > T1.земля)
			//  - коли у Т0.земля недостатньо висоти, що аж компенсується великими запасами води (Т0.сума > T1.висота)
			// також можна і провернути і на зворотній бік
			short dh0_s1 = _map[curindex].height() - _map[minindex].sumheight();
			if(dh0_s1 <= _map[curindex].water())
			{
				map[minindex].water() += _map[curindex].water();
				continue;
			}
			short water1 = _map[minindex].water();
			short water0 = _map[curindex].water();
			if(dh0_s1 < 0)
			{
				short maxheight = __max(_map[minindex].height(), _map[curindex].height());
				water0 -= maxheight;
				short avrgwater = water0 + water1;
				avrgwater /= 2;
				water0 = avrgwater + maxheight;
				water1 = avrgwater;
			}
			else
			{
				water1 += dh0_s1;
				water0 -= dh0_s1;
				water0 -= water0 / 2;
				water1 += water0;
			}
			map[curindex].water() += water0;
			map[minindex].water() += water1;
			//short dh0_h1 = _map[curindex].height() - _map[minindex].height();
			
		}
	}
	delete[] _map;
	_map = map;
}

Tile &MapTile::operator[](soze index_)
{
	if(!(0 <= index_ && index_ < soze(_size.x) * _size.y))
	{
		_delete();
		printf("%s: Index is out of range", __FUNCTION__);
		abort();
	}
	return _map[index_];
}

MapTile::point MapTile::size()
{
	return _size;
}
