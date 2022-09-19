#include "Perlin.h"


float *Perlin::generate1d(unsigned int size_)
{
    float *out = new float[size_];
    for(int x = 0; x < size_; x++)
        out[x] = (float)rand() / (float)RAND_MAX;

    return out;
}
float *Perlin::generate2d(unsigned int sizex_, unsigned int sizey_)
{
    float *out = new float[sizex_ * sizey_];
    for(int x = 0; x < sizex_ * sizey_; x++)
        out[x] = (float)rand() / (float)RAND_MAX;

    return out;
}
float *Perlin::noise1d(unsigned int count_, float *seed_, int octav_, float bias_)
{
    float * out = new float[count_];
    for(int x = 0; x < count_; x++)
    {
        float noise = 0.0f;
        float scale = 1.0f;
        float scale_acc = 0.0f;
        for(int o = 0; o < octav_; o++)
        {
            int pitch = count_ >> o;
            int sample1 = (x / pitch) * pitch;
            int sample2 = (sample1 + pitch) % count_;

            float blend = float(x - sample1) / float(pitch);
            float sample = (1.0f - blend) * seed_[sample1] + blend * seed_[sample2];
            noise += sample * scale;
            scale_acc += scale;
            scale = scale / bias_;
        }
        out[x] = noise / scale_acc;
    }
    delete[] seed_;
    return out;
}
float *Perlin::noise2d(unsigned int countX_, unsigned int countY_, float *seed_, int octav_, float bias_)
{
    float *out = new float[countX_*countY_];
    for(int x = 0; x < countX_; x++)
        for(int y = 0; y < countY_; y++)
        {
            float noise = 0.0f;
            float scale = 1.0f;
            float scale_acc = 0.0f;
            for(int o = 0; o < octav_; o++)
            {
                int pitch = countX_ >> o;
                int sample1x = (x / pitch) * pitch;
                int sample1y = (y / pitch) * pitch;

                int sample2x = (sample1x + pitch) % countX_;
                int sample2y = (sample1y + pitch) % countX_;

                float blendx = float(x - sample1x) / float(pitch);
                float blendy = float(y - sample1y) / float(pitch);

                float sampleT = (1.0f - blendx) * seed_[sample1y*countX_+sample1x] + blendx * seed_[sample1y * countX_ + sample2x];
                float sampleB = (1.0f - blendx) * seed_[sample2y * countX_ + sample1x] + blendx * seed_[sample2y * countX_ + sample2x];

                noise += (blendy*(sampleB - sampleT)+sampleT) * scale;
                scale_acc += scale;
                scale = scale / bias_;
            }
            out[y*countX_ + x] = noise / scale_acc;
        }
    delete[] seed_;
    return out;
}

