#include <iostream>
#include <chrono>
#include "FilePPM.h"
#include "Perlin.h"
#include "Tile.h"
#include "MapTile.h"
int main()
{
	//auto beg = std::chrono::system_clock::now(), end = std::chrono::system_clock::now();
	int size = 8;
	//Perlin p;
	//srand(0);

	//beg = std::chrono::system_clock::now();
	//float *ar = p.generate2d(size, size);
	//float *arr = p.noise2d(size, size, ar, 10, 1.5);
	//end = std::chrono::system_clock::now();
	//std::cout << "Generation: " <<(float)std::chrono::duration_cast<std::chrono::microseconds>(end-beg).count()/1000.0f << "ms\n";

	//MapTile m(size, size);

	//beg = std::chrono::system_clock::now();
	//m.updateheight(arr, size * size);
	//delete[] arr;
	//end = std::chrono::system_clock::now();
	//std::cout << "Update height: " << (float)std::chrono::duration_cast<std::chrono::microseconds>(end - beg).count() / 1000.0f << "ms\n";

	//beg = std::chrono::system_clock::now();
	//m.updatecliff();
	//end = std::chrono::system_clock::now();
	//std::cout << "Update cliff: " << (float)std::chrono::duration_cast<std::chrono::microseconds>(end - beg).count() / 1000.0f << "ms\n";

	//for(int x = 0; x < size; x++)
	//	for(int y = 0; y < size; y++)
	//		m[x + y * size].water() = rand()%256 * 16;

	//FilePPM ppm(size, size);
	//beg = std::chrono::system_clock::now();
	//for(int x = 0; x < size; x++)
	//	for(int y = 0; y < size; y++)
	//	{
	//		ppm.dot(x, y) = m[x + y * size].torgb();
	//	}
	//ppm.save("before.ppm");

	//int iter = 100;

	//for(int i = 0; i < iter; i++)
	//{
	//	beg = std::chrono::system_clock::now();
	//	m.updateonedirwater();
	//	end = std::chrono::system_clock::now();
	//	std::cout << "Update water: " << (float)std::chrono::duration_cast<std::chrono::microseconds>(end - beg).count() / 1000.0f << "ms x" << i << "\n";
	//}
	//	
	//beg = std::chrono::system_clock::now();
	//for(int x = 0; x < size; x++)
	//	for(int y = 0; y < size; y++)
	//	{
	//		ppm.dot(x, y) = m[x+y*size].torgb();
	//	}
	//ppm.save("after.ppm");
	//end = std::chrono::system_clock::now();
	//std::cout << "Update picture: " << (float)std::chrono::duration_cast<std::chrono::microseconds>(end - beg).count() / 1000.0f << "ms\n";

	int mult = 4;
	Perlin p;
	srand(0);
	float *ar = p.generate1d(size);
	float *arr = p.noise1d(size, ar, 2, 1.5);
	MapTile m(size, 1);
	m.updateheight(arr, size);
	delete[] arr;

	for(int x = 0; x < size; x++)
			m[x].water() = rand() % 256;

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < m[i].height() / mult; j++)
		{
			std::cout << '#';
		}
		for(int j = 0; j < m[i].water() / mult; j++)
		{
			std::cout << '*';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	m.updateonedirwater();
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < m[i].height() / mult; j++)
		{
			std::cout << '#';
		}
		for(int j = 0; j < m[i].water() / mult; j++)
		{
			std::cout << '*';
		}
		std::cout << '\n';
	}
	return 0;
}