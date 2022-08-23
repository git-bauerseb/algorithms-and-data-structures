#ifndef SORTING_H
#define SORTING_H

#include "common.h"

// Insertionsort
// Chapter 2 - Section 1
template<typename T>
void insertionSort(T* const arr, int size) {
    for (int j = 1; j < size; j++) {
        int key = arr[j];
        int i = j - 1;
        // Insert arr[j] into sorted arr[0], ..., arr[j-1]
        while (i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i--;
        }

        arr[i+1] = key;
    }
}

// Chapter 2 - Section 3
// Modified to use no sentinel element but additional checks
template<typename T>
void merge(T* const arr, int p, int q, int r) {
    // Include 'q' into first array
    int n1 = q - p + 1;
    int n2 = r - q;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[p+i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[q+j+1];
    }

    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++) {

        if (i == n1) {
            arr[k] = R[j];
            j = j + 1;
        } else if (j == n2) {
            arr[k] = L[i];
            i = i + 1;
        } else if (L[i] < R[j]) {
            arr[k] = L[i];
            i = i + 1;
        } else {
            arr[k] = R[j];
            j = j + 1;
        }
    }

    delete[] L;
    delete[] R;
}

/*
    Problem 2-1, b)

    Uses insertion sort to merge two sublists, if
    their size less than k
*/
template<typename T>
void modifiedMerge(T* const arr, int p, int q, int r, int k) {
    if (r - p < k) {
        insertionSort(arr + p, r-p+1);
    } else {
        merge<int>(arr, p, q, r);
    }
}

/*
    Uses modified merge to merge two sublists
*/
template<typename T>
void modifiedMergeSort(T* const arr, int p, int r, int k) {
    if (p < r) {
        int q = std::floor((p+r) / 2);

        modifiedMergeSort<T>(arr, p, q, k);
        modifiedMergeSort<T>(arr, q+1, r, k);
        modifiedMerge<T>(arr, p, q, r, k);
    }
}

template<typename T>
void mergeSort(T* const arr, int p, int r) {
    if (p < r) {
        // Compute middle element
        int q = std::floor((p+r) / 2);

        mergeSort<T>(arr, p, q);
        mergeSort<T>(arr, q+1, r);
        merge<T>(arr, p, q, r);
    }
}

template<typename T>
int countInversions(T* const arr, int p, int q, int r) {
    // Include 'q' into first array
    int n1 = q - p + 1;
    int n2 = r - q;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[p+i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[q+j+1];
    }

    int i = 0;
    int j = 0;
    int inversions = 0;
    for (int k = p; k <= r; k++) {
        if (i == n1) {
            arr[k] = R[j];
            j = j + 1;
        } else if (j == n2) {
            arr[k] = L[i];
            i = i + 1;
        } else if (L[i] < R[j]) {
            arr[k] = L[i];
            i = i + 1;
        } else {
            inversions += (n1 - i);
            arr[k] = R[j];
            j = j + 1;
        }
    }

    delete[] L;
    delete[] R;

    return inversions;
}


/*
    Determines the number of inversions in an array.
    O(n lg n)
*/
template<typename T>
int inversions(T* const arr, int p, int r) {
    if (p < r) {
        int q = std::floor((p+r) / 2);

        int a = inversions(arr, p, q);
        int b = inversions(arr, q+1, r);
        int c = countInversions(arr, p, q, r);

        return a + b + c; 
    }

    return 0;
}

// Exercise 2.1-2
template<typename T>
void insertionSortNonDecreasing(T* const arr, int size) {
    for (int j = 1; j < size; j++) {
        int key = arr[j];
        int i = j - 1;
        // Insert arr[j] into (non-decreasing) sorted arr[j-1], ... arr[0]
        while(i >= 0 && arr[i] < key) {
            arr[i+1] = arr[i];
            i--;
        }

        arr[i+1] = key;
    }
}

// Exercise 2.3-4
// b: upper bound on the index of the subarray
void recursiveInsertionSort(int* A, int size, int n) {
    if (n > 0) {
        recursiveInsertionSort(A, size, n-1);
        int elem = A[n];

        int j = n-1;

        while (A[j] > elem && j >= 0) {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = elem;
    }
}

#endif