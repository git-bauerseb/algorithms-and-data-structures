#include <iostream>
#include <cstring>
#include <vector>
// #include "../include/i2a/sorting.h"
// #include "../include/i2a/dynamic_programming.h"

#include "../include/i2a/optim.h"
#include "../include/i2a/exercises.h"
#include "../include/i2a/random.h"
#include "../include/i2a/elem_structures.h"


void maximum_subarray_test() {

    int price[17] = {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};

    int diffs[16];

    for (int i = 1; i < 17; i++) {
        diffs[i-1] = price[i] - price[i-1];
    }
    
    Triple<int> res1 = maximum_subarray(diffs, 0, 15);
    Triple<int> res2 = kadane_maximum_subarray(diffs, 16);
    Triple<int> res3 = quadratic_maximum_subarray(diffs, 16);

    printf("CLRS::Implementation\nStart: %d\nEnd: %d\nSum: %d\n", res1.m_t1, res1.m_t2, res1.m_t3);
    printf("CLRS::Exercise::4.1-2\nStart: %d\nEnd: %d\nSum: %d\n", res3.m_t1, res3.m_t2, res3.m_t3);
    printf("CLRS::Exercise::4.1-5\nStart: %d\nEnd: %d\nSum: %d\n", res2.m_t1, res2.m_t2, res2.m_t3);
}


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

    /*
    int prices[5] = {1, 6, 9, 13, 14};

    int max_profit1 = recursiveCutRod(prices, 5);
    int max_profit2 = memoizedCutRod(prices, 5);
    int max_profit3 = bottomUpCutRod(prices, 5);

    std::cout << max_profit3 << "\n";
    */

    // Longest common subsequence
    /*
    char X[] = "HelloWorld";
    char Y[] = "lloW";

    int m = std::strlen(X);
    int n = std::strlen(Y);

    longestCommonSubSeq(X,Y,m,n);
    */

    /*
    int price[17] = {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};

    int diffs[16];

    for (int i = 1; i < 17; i++) {
        diffs[i-1] = price[i] - price[i-1];
    }
    
    Triple<int> res = maximum_subarray(diffs, 0, 15);

    std::cout << "Index [low]: " << res.m_t1 << "\n";
    std::cout << "Index [high]: " << res.m_t2 << "\n";
    std::cout << "Sum : " << res.m_t3 << "\n";

    res = kadane_maximum_subarray(diffs,16);

    std::cout << "Index [low]: " << res.m_t1 << "\n";
    std::cout << "Index [high]: " << res.m_t2 << "\n";
    std::cout << "Sum : " << res.m_t3 << "\n";
    */
    
    // maximum_subarray_test();
    /*
    int price[17] = {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};
    int diffs[16];

    for (int i = 1; i < 17; i++) {
        diffs[i-1] = price[i] - price[i-1];
    }

    ex_4_1_5(diffs, 17);
    */

    /*
    srand(time(NULL));

    int zeros = 0;
    int ones = 1;

    int samples = 100;

    for (int i = 0; i < samples; i++) {
        int val = correct_biased();
        zeros += (1 - val);
        ones += val;
    }

    std::cout << (float)zeros / samples << "\n";
    std::cout << (float)ones / samples << "\n";
    */

    /*
    Stack<int> q{};

    q.push(41);
    q.push(4);
    q.push(1459);
    q.push(194);
    q.push(815);
    q.push(81);
    q.push(239);
    q.push(8);
    q.push(19);
    q.push(11);

    while (!q.is_empty()) {
        std::cout << q.pop() << "\n";
    }
    */

    using namespace i2a::structures;

    DLList<int> l{1,2,3,4,5,6};


    auto lambda = [&](DLList<int>::DLNode& node) {
            std::cout << node.key << "\n";
        };

    l.traverse<decltype(lambda)>(lambda);

    return 0;
}