#include <iostream>
#include "FilePPM.h"
#include "Perlin.h"
#include "Tile.h"

int main()
{
    int size = 256;

    Perlin p;
    srand(time(NULL));
    float *ar = p.generate2d(size, size);
    float *arr = p.noise2d(size, size, ar, 9,1.5);
    Tile *tile = new Tile[size*size];

    FilePPM ppm(size, size);
    for(int x = 0; x < size; x++)
        for(int y = 0; y < size; y++)
        {
            tile[x + y * size].cliff() = 0;
            tile[x + y * size].height() = arr[x + y * size] * 256;
            ppm.dot(x, y) = tile[x + y * size].torgb();
        }
    ppm.save("2d.ppm");

    delete[] arr;
    delete[] tile;
    return 0;
}