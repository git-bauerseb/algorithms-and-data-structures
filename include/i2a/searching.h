#ifndef I2A_SEARCHING_H
#define I2A_SEARCHING_H

#include "sorting.h"
#include "common.h"

// Exercise 2.3-5
// Assumes the array is sorted otherwise will fail.
int binarySearch(int* A, int size, int value) {
    int l = 0;
    int h = size - 1;

    while (l <= h) {
        int piv = std::floor((h + l) / 2);

        if (value == A[piv]) {
            return piv;
        }

        // Search in left half
        if (value < A[piv]) {
            h = piv - 1;
        } else {
            l = piv + 1;
        }
    }

    return -1;
}

// Exercise 2.3-7
bool sumTwo(int* A, int size, int x) {

    // Sort array in O(n lg n)
    mergeSort(A, 0, size);

    for (int i = 0; i < size; i++) {
        int tmp = x - A[i];
        int idx = binarySearch(A, size, tmp);
    
        // If value found, then x is sum of two elements
        if (idx >= 0) {
            return true;
        }
    }

    return false;
}

#endif