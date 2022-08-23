# Chapter 4

## Exercises

### 4.1-1

The largest negative element is returned

E.g.: For
    -5 -9 -192 -42 -85 -1 -172 -19

the algorithm returns -1


### 4.1-2

Algorithm on paper and implemented

### 4.1-4

To allow empty subarray, first execute the normal algorithm. If the returned sum is negative then an empty subarray has a larger maximum sum. So return an empty array. Else, return the result of the original computation.

### 4.1-5

Observations:
    - A maximum subarray always starts with a positive number, because if not then excluding the negative number yields a greater sum

    - Thus, everytime the current maximum sum falls below 0, starting over is best

    for i = 1 to A.length do
        current = max(0, current + A[i])

        