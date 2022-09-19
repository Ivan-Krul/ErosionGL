#include "FilePPM.h"

FilePPM::FilePPM(unsigned short x_, unsigned short y_)
{
	_x = x_;
	_y = y_;
	_pic.resize((unsigned int)_x * (unsigned int)_y);
}

void FilePPM::clear()
{
	RGB def = { 0x101010 };
	for(int i = 0; i < _pic.size(); i++)
		_pic[i] = def;
}

RGB &FilePPM::dot(unsigned short x_, unsigned short y_)
{
	assert(x_ < _x);
	assert(y_ < _y);
	return _pic[x_ + y_ * _x];
}

unsigned short FilePPM::sizex()
{
	return _x;
}

unsigned short FilePPM::sizey()
{
	return _y;
}

void FilePPM::save(std::string dir_)
{
	std::ofstream fout;
	fout.open(dir_, std::ios::out);
	fout << "P3\n";
	fout << _x << ' ' << _y << '\n';
	fout << 255 << '\n';
	
	for(int i = 0; i < _pic.size(); i++)
	{
		fout << (short)_pic[i].r << ' ' << (short)_pic[i].g << ' ' << (short)_pic[i].b;
		if(i % 3 == 0 && i != 0) fout << '\n';
		else fout << ' ';
	}

	fout.close();
}

void FilePPM::save_e(std::string dir_)
{
	std::ofstream fout;
	fout.open(dir_, std::ios::out | std::ios::binary);
	fout << "P3 E\n";
	fout << _x << ' ' << _y << '\n';

	for(int i = 0; i < _pic.size(); i++)
		fout << _pic[i].r << _pic[i].g << _pic[i].b;
}

bool FilePPM::load(std::string dir_)
{
	std::ifstream fin;
	fin.open(dir_);
	if(!fin.is_open()) return false;

	std::string s;
	fin >> s;
	fin >> _x >> _y;
	fin >> s;

	_pic.clear();
	_pic.resize(_x * _y);
	for(int i = 0; i < _pic.size(); i++)
		fin >> _pic[i].r >> _pic[i].g >> _pic[i].b;

	fin.close();
	return true;
}

bool FilePPM::load_d(std::string dir_)
{
	std::ifstream fin;
	fin.open(dir_, std::ios::binary | std::ios::in);
	if(!fin.is_open()) return false;

	std::string s;
	fin >> s >> s;
	fin >> _x >> _y;

	char buf[3];

	_pic.clear();
	_pic.resize(_x * _y);
	for(int i = 0; i < _pic.size(); i++)
	{
		fin.read(buf,3);
		_pic[i].r = buf[0];
		_pic[i].g = buf[1];
		_pic[i].b = buf[2];
	}

	fin.close();
	return true;
}
