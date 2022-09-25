#include <iostream>
#include "FilePPM.h"
#include "Perlin.h"
#include "Tile.h"

int main()
{
    int size = 512;
    Perlin p;
    srand(0);
    float *ar = p.generate2d(size, size);
    float *arr = p.noise2d(size, size, ar, 8,1.25);
    Tile *tile = new Tile[size*size];
    float *buf;

    FilePPM ppm(size, size);
    for(int x = 0; x < size; x++)
        for(int y = 0; y < size; y++)
        {
            int sizee = 0;
            for(int dx = -1; dx < 2; dx++)
                for(int dy = -1; dy < 2; dy++)
                    if(0 <= (dx + x) && (dx + x) < size && 0 <= (dy + y) && (dy + y) < size)
                        sizee++;
            buf = new float[sizee];
            int a = 0;
            for(int dx = -1; dx < 2; dx++)
                for(int dy = -1; dy < 2; dy++)
                    if(0 <= (dx + x) && (dx + x) < size && 0 <= (dy + y) && (dy + y) < size)
                    {
                        if(!(a < sizee)) break;
                        buf[a] = arr[(x + dx) + (y + dy) * size];
                        a++;
                    }
            tile[x + y * size].generatecliff(buf,sizee);
            tile[x + y * size].height() = arr[x + y * size] * 256;
            if(rand()%16 == 0)
                tile[x + y * size].water() = rand()%16;
            ppm.dot(x, y) = tile[x + y * size].torgb();
            delete[] buf;
        }
    ppm.save("2d.ppm");
    delete[] arr;
    delete[] tile;
    return 0;
}