#include <iostream>
// #include "../include/i2a/sorting.h"
#include "../include/i2a/dynamic_programming.h"

int main(int argc, char** argv) {

    /*
    auto plainMergesort = [&](int *a, int size) {
        mergeSort<int>(a, 0, size-1);
    };

    auto newMergesort = [&](int *a, int size) {
        modifiedMergeSort<int>(a, 0, size-1, 32);
    };

    // Compare two algorithms based on sorting 10^6 integers
    compareTwoAlSortingAlgorithms<int, decltype(plainMergesort), decltype(newMergesort)>
        (1'000'000, plainMergesort, newMergesort);
    */

    /*
    // Polynomial
    int coeff[4] = {3, 5, 2, 19};

    int y1 = hornerEvaluation(coeff, 4, 2);
    int y2 = naivePolyEvaluation(coeff, 4, 2);

    std::cout << y1 << "\n";
    std::cout << y2 << "\n";
    */

    /*
    int arr[5] = {5,4,3,2,1};
    std::cout << inversions<int>(arr, 0, 4) << "\n";
    */

    int prices[5] = {1, 6, 9, 13, 14};

    int max_profit1 = recursiveCutRod(prices, 5);
    int max_profit2 = memoizedCutRod(prices, 5);
    int max_profit3 = bottomUpCutRod(prices, 5);

    std::cout << max_profit3 << "\n";
    

    return 0;
}