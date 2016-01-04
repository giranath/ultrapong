//
//  RNG.cpp
//  Prototype_1
//
//  Created by Nathan on 2013-01-03.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#include "Randomizer.h"

    
Randomizer::Randomizer() {
    this->setSeed((unsigned int)time(NULL));
}

Randomizer::Randomizer(unsigned int seed) {
    this->setSeed(seed);
}

int Randomizer::random() {
    int nb = rand();
    
    return nb;
}

int Randomizer::random(int max, int min) {
    int nb = random();
    
    return (nb % ((max + 1) - min) + min);
}

float Randomizer::frandom() {
    return (float)( rand()/(double)RAND_MAX );
}

float Randomizer::frandom(float max, float min) {
    float nb = frandom();
    
    return nb * (max-min) + min;
}