#ifndef I2A_OPTIM_H
#define I2A_OPTIM_H

#include "common.h"

Triple<int> maximum_crossing_subarray(int* A, int i_low, int i_mid, int i_high) {

    if (i_low == i_high) {
        return Triple<int>{i_low, i_low, A[i_low]};
    }

    int left_sum = MIN_INT;
    int right_sum = MIN_INT;

    int sum = 0;

    int max_left, max_right;

    for (int i = i_mid; i >= i_low; i--) {
        sum += A[i];

        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    sum = 0;

    for (int j = i_mid + 1; j <= i_high; j++) {
        sum += A[j];

        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    Triple<int> t {max_left, max_right, left_sum + right_sum};
    return t;
}

Triple<int> maximum_subarray(int* A, int i_low, int i_high) {
    if (i_high == i_low) {
        Triple<int> t{i_low, i_high, A[i_low]};
        return t;
    } else {
        int mid = std::floor((i_low + i_high) / 2);

        Triple<int> left = maximum_subarray(A, i_low, mid);
        Triple<int> right = maximum_subarray(A, mid + 1, i_high);

        Triple<int> crossing = maximum_crossing_subarray(A, i_low, mid, i_high);

        // Maximum subarray is on left side
        if (left.m_t3 >= right.m_t3 && left.m_t3 >= crossing.m_t3) {
            return left;
        } else if (right.m_t3 >= left.m_t3 && right.m_t3 >= crossing.m_t3) {
            return right;
        }

        return crossing;
    }
}

/*
    Exercise 4.1-5

    Description: Returns a triple containing the start index, end index
                 and the maximum sum of an array.
    Runtime: Theta(n)
*/
Triple<int> kadane_maximum_subarray(int* A, int length) {
    int max = A[0];
    int start = 0;
    int end = 0;
    int m_start = 0;
    int m_end = 0;
    int curr_max = A[0];

    for (int i = 1; i < length; i++) {
        if (A[i] > A[i] + curr_max) {
            curr_max = A[i];
            start = i;
        } else {
            curr_max = curr_max + A[i];
        }

        end = i;
        if (curr_max > max) {
            max = curr_max;
            m_start = start;
            m_end = end;
        }
    }

    return Triple<int>{m_start, m_end, max};
}

/*
    Exercise 4.1-2

    Description: Returns a triple containing the start index, end index
                 and the maximum sum of an array.
    Runtime: Theta(n^2)
*/
Triple<int> quadratic_maximum_subarray(int* A, int length) {

    int curr_sum;
    int max = MIN_INT;

    int start = length - 1;
    int end = length - 1;

    for (int i = length - 1; i >= 0; i--) {
        curr_sum = 0;
        for (int j = i; j >= 0; j--) {
            curr_sum += A[j];

            if (curr_sum > max) {
                start = j;
                end = i;
                max = curr_sum;
            }
        }
    }

    return Triple<int> {start, end, max};
}


#endif