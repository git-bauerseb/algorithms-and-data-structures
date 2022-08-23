#ifndef I2A_RANDOM_H
#define I2A_RANDOM_H

#include <cmath>

/*
    Returns '0' with probability p
    and '1' with probability 1 - p.

    The value p is expected to be given in percent.
*/
int biased_random(float p) {
    int val = rand() % 100;

    return val < (p * 100) ? 0 : 1;
}

/*
    Implement unbiased random number generator that
    outputs '0' with probability 0.5 and '1' with probability
    0.5.
*/
int correct_biased() {
    while (true) {
        int a = biased_random(0.7);
        int b = biased_random(0.7);
    
        if (a > b) {return 0;}
        if (b > a) {return 1;}
    }
}

#endif