#ifndef I2A_TIMING_H
#define I2A_TIMING_H

#include <chrono>
#include <iostream>
#include <cstdlib>
#include <algorithm>

template<typename T>
static void randomizeArray(T* const arr, int size) {
    // Randomly permutate elements
    for (int i = 0; i < size/2; i++) {
        int idx = std::rand() % size;
        T tmp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = tmp;
    }
}

/*
    Given a collection of data and two algorithms,
    runs both of them on the same data and compares
    their running time.
*/
template<typename C, typename A1, typename A2>
void compareTwoAlSortingAlgorithms(int size, A1& alg1, A2& alg2) {

    C* a = new C[size];

    // Initialize array
    for (int i = 0; i < size; i++) {
        a[i] = i;
    }

    randomizeArray<C>(a, size);

    auto started = std::chrono::high_resolution_clock::now();
    alg1(a, size);
    auto done = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size; i++) {
        if (a[i] != i) {
            std::cerr << "Error in algorithm 1 a[" << i << "] = " << a[i] << "\n";
        }
    }

    std::cout << "[Algorithm 1, Runtime] {Microseconds}: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(done-started).count() << "\n";

    // Randomize for second algorithm
    randomizeArray<C>(a, size);

    started = std::chrono::high_resolution_clock::now();
    alg2(a, size);
    done = std::chrono::high_resolution_clock::now();

    std::cout << "[Algorithm 2, Runtime] {Microseconds}: ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(done-started).count() << "\n";

    // Check result
    for (int i = 0; i < size; i++) {
        if (a[i] != i) {
            std::cerr << "Error in algorithm 2 a[" << i << "] = " << a[i] << "\n";
        }
    }

    delete[] a;
}

#endif