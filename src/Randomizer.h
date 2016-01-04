//
//  RNG.h
//  Prototype_1
//
//  Created by Nathan on 2013-01-03.
//  Copyright (c) 2013 Nathan. All rights reserved.
//

#ifndef __Prototype_1__RNG__
#define __Prototype_1__RNG__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Randomizer {
    private:
        unsigned int _seed;
    public:
        Randomizer();
        Randomizer(unsigned int seed);
        
        void setSeed(unsigned int seed) {_seed = seed; srand(_seed);}
        unsigned int getSeed() {return _seed;}
        
        int random();
        int random(int max, int min = 0);
        
        float frandom();
        float frandom(float max, float min = 0.0f);
    
};

#endif /* defined(__Prototype_1__RNG__) */
