#ifndef I2A_POLYNOMIAL_H
#define I2A_POLYNOMIAL_H

/*
    Evaluate a polynomial with the given coefficients using
    Horner's rule. The coefficients are expected to be stored
    in reverse, e.g.

    a3 * x^3 + a2 * x^2 + a1 * x^1 + a0 -> [a0, a1, a2, a3] 
*/
int hornerEvaluation(int* coeff, int size, int x) {
    int y = 0;

    for (int i = size-1; i >= 0; i--) {
        y = coeff[i] + x * y;
    }

    return y;
}

/*
    Naive evaluation of the polynomial.
*/
int naivePolyEvaluation(int* coeff, int size, int x) {
    int y = 0;

    for (int i = 0; i < size; i++) {
        int xPow = 1;
        for (int k = 0; k < i; k++) {
            xPow *= x;
        }

        y = coeff[i] * xPow + y;
    }

    return y;
}

#endif