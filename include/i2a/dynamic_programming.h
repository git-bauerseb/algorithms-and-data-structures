#ifndef I2A_DYNAMIC_PROGRAMMING_H
#define I2A_DYNAMIC_PROGRAMMING_H

#include <limits>
#include <cmath>
#include <utility>

/*
    Chapter 15-1
    Solves the cut rod problem by simple recursive algorithm and no dynamic programming.
    Running time is exponential.
*/
int recursiveCutRod(int * p, int n) {
    if (n == 0) {
        return 0;
    }

    int q = std::numeric_limits<int>::min();

    for (int i = 0; i < n; i++) {
        q = std::max(q, p[i] + recursiveCutRod(p, n - i - 1));
    }

    return q;
}

int memoizedCutRodAux(int* p, int n, int* r) {

    if (n == 0) {
        return 0;
    }

    if (r[n] >= 0) {
        return r[n];
    }

    int q = std::numeric_limits<int>::min();
    for (int i = 1; i <= n; i++) {
        q = std::max(q, p[i-1] + memoizedCutRodAux(p, n-i, r));
    }

    r[n] = q;
    return q;
}

int memoizedCutRod(int* p, int n) {
    int* r = new int[n+1];

    for (int i = 0; i <= n; i++) {
        r[i] = std::numeric_limits<int>::min();
    }

    int profit = memoizedCutRodAux(p, n, r);
    delete[] r;

    return profit;
}

int bottomUpCutRod(int* p, int n) {
    int* r = new int[n+1];
    r[0] = 0;

    for (int j = 1; j <= n; j++) {
        int q = std::numeric_limits<int>::min();
        for (int i = 0; i < j; i++) {
            q = std::max(q, p[i] + r[j-i-1]);
        }

        r[j] = q;
    }

    delete[] r;
    return r[n];
}

std::pair<int*, int*> extendedBottomUpCutRod(int* p, int n) {
    int* r = new int[n+1];
    int* s = new int[n+1];

    for (int j = 1; j <= n; j++) {
        int q = std::numeric_limits<int>::min();
        for (int i = 0; i < j; i++) {
            if (q < p[i] + r[j-1-1]) {
                q = std::max(q, p[i] + r[j-i-1]);
                s[j] = i;
            }
        }

        r[j] = q;
    }

    return std::pair<int*, int*>{r,s};
}

void printCutRodSolution(int* p, int n) {
    std::pair<int*, int*> pair = extendedBottomUpCutRod(p, n);

    while (n > 0) {
        std::cout << pair.second[n] << "\n";
        n = n - pair.second[n];
    }
}

/*
    Chapter 15.4 - Longest common subsequence
*/
void longestCommonSubSeq(char* x, char* y, int m, int n) {

    int c[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                c[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
        }
    }

    int index = c[m][n];

    char seq[index + 1];
    seq[index] = '\0';

    int i = m;
    int j = n;
    while (i > 0 && j > 0) {
        if (x[i-1] == y[j-1]) {
            seq[index - 1] = x[i-1];
            i--;
            j--;
            index--;
        } else if (c[i-1][j] > c[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    // Print out longest common subsequence
    std::cout << seq << "\n";
}

#endif