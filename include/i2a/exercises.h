#ifndef I2A_EXERCISES_H
#define I2A_EXERCISES_H

#include <cmath>

#include "common.h"

void ex_4_1_5(int* A, int length) {

    int max_sum = MIN_INT;
    int curr_sum = 0;

    int start = 0;
    int end = 0;

    int best_start = 0;
    int best_end = 0;

    for (int i = 0; i < length - 1; i++) {
        curr_sum = std::max(0, curr_sum + A[i]);

        if (curr_sum == 0) {
            start = i;
        }

        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            best_start = start + 1;
            best_end = i;
        }
    }

    printf("Start: A[%d] = %d\nEnd: A[%d] = %d\nSum: %d", best_start, A[best_start],
        best_end, A[best_end], max_sum);
}

#endif