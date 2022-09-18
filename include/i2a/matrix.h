#ifndef I2A_MATRIX_H
#define I2A_MATRIX_H

#include <iostream>
#include <cassert>

#include "common.h"


namespace i2a {

    namespace math {

        class Matrix {

        public:
            Matrix(int rows, int cols) {
                assert(rows > 0 && cols > 0);

                m_rows = rows;
                m_cols = cols;

                m_elements = new int *[rows]();

                for (int i = 0; i < rows; i++) {
                    m_elements[i] = new int[cols]();
                }
            }

            ~Matrix() {
                for (int i = 0; i < m_rows; i++) {
                    delete[] m_elements[i];
                }

                delete[] m_elements;
            }

            int &operator()(int x, int y) const {
                return m_elements[y][x];
            }

            friend std::ostream &operator<<(std::ostream &stream, const Matrix &m);

            static Matrix multiply(const Matrix &a, const Matrix &b);

            // Multiply two matrices that are square and which size is a power of 2
            static Matrix strassenMultiplication(const Matrix &a, const Matrix &b);

        private:
            int **m_elements;
            int m_rows;
            int m_cols;
        };

        std::ostream &operator<<(std::ostream &stream, const Matrix &m) {
            for (int y = 0; y < m.m_rows; y++) {
                for (int x = 0; x < m.m_cols; x++) {
                    stream << m(x, y) << " ";
                }

                if (y < (m.m_rows - 1)) {
                    stream << "\n";
                }
            }

            return stream;
        }

        Matrix Matrix::multiply(const Matrix &a, const Matrix &b) {

            Matrix c(a.m_rows, b.m_cols);

            for (int i = 0; i < c.m_rows; i++) {
                for (int j = 0; j < c.m_cols; j++) {

                    int val = 0;

                    for (int k = 0; k < a.m_cols; k++) {
                        val += a(i, k) * b(k, j);
                    }

                    c(i, j) = val;
                }
            }

            return c;
        }

        static void addSubmatricesInPlace(const Matrix& c,
                                            const Matrix& a,
                                            const Matrix& b,
                                            int size, int cx, int cy) {
            for (int col = 0; col < size; col++) {
                for (int row = 0; row < size; row++) {
                    c(row+cx, col+cy) = a(row,col) + b(row, col);                }
            }
        }

        static void subSubmatricesInPlace(const Matrix& c,
                                          const Matrix& a,
                                          const Matrix& b,
                                          int size, int cx, int cy) {
            for (int col = 0; col < size; col++) {
                for (int row = 0; row < size; row++) {
                    c(row+cx, col+cy) = a(row,col) - b(row, col);
                }
            }
        }

        static Matrix addSubmatrices(const Matrix& a,
                                     const Matrix& b,
                                     int size, int ax, int ay, int bx, int by) {

            Matrix c(size,size);
            for (int col = 0; col < size; col++) {
                for (int row = 0; row < size; row++) {
                    c(row, col) = a(row + ax, col + ay) + b(row + bx, col + by);
                }
            }

            return c;
        }

        static Matrix subSubmatrices(const Matrix& a,
                                    const Matrix& b,
                                    int size, int ax, int ay, int bx, int by) {

            Matrix c(size,size);
            for (int col = 0; col < size; col++) {
                for (int row = 0; row < size; row++) {
                    c(row, col) = a(row + ax, col + ay) - b(row + bx, col + by);
                }
            }

            return c;
        }

        static Matrix multiplyMatricesRecursive(const Matrix &a,
                                                const Matrix &b,
                                                int size, int ax, int ay, int bx, int by) {

            Matrix c(size, size);

            if (size == 1) {
                c(0,0) = a(0,0) * b(0,0);
            } else if (size == 2) {
                c(0,0) = a(ax,ay) * b(bx,by) + a(ax+1,ay) * b(bx, by+1);
                c(1,0) = a(ax,ay) * b(bx+1,by) + a(ax+1,ay) * b(bx+1, by+1);
                c(0,1) = a(ax,ay+1) * b(bx,by) + a(ax+1,ay+1) * b(bx, by+1);
                c(1,1) = a(ax,ay+1) * b(bx+1,by) + a(ax+1,ay+1) * b(bx+1, by+1);
            } else {

                int nsize = size / 2;

                Matrix s1 = subSubmatrices(b,b, nsize, bx + nsize, by, bx + nsize, by + nsize);
                Matrix s2 = addSubmatrices(a,a, nsize, ax, ay, ax + nsize, ay);
                Matrix s3 = addSubmatrices(a,a,nsize,ax, ay+nsize, ax+nsize, ay+nsize);
                Matrix s4 = subSubmatrices(b,b,nsize,bx,by+nsize,bx,by);
                Matrix s5 = addSubmatrices(a,a,nsize, ax,ay,ax+nsize,ay+nsize);
                Matrix s6 = addSubmatrices(b,b,nsize,bx,by,bx+nsize,by+nsize);
                Matrix s7 = subSubmatrices(a,a,nsize,ax+nsize,ay,ax+nsize,ay+nsize);
                Matrix s8 = addSubmatrices(b,b,nsize,bx,by+nsize,bx+nsize,by+nsize);
                Matrix s9 = subSubmatrices(a,a,nsize,ax,ay,ax,ay+nsize);
                Matrix s10 = addSubmatrices(b,b,nsize,bx,by,bx+nsize,by);
                Matrix p1 = multiplyMatricesRecursive(a,s1,nsize,ax,ay,0,0);
                Matrix p2 = multiplyMatricesRecursive(s2,b,nsize,ax,ay,bx+nsize,by+nsize);
                Matrix p3 = multiplyMatricesRecursive(s3,b,nsize,0,0,bx,by);
                Matrix p4 = multiplyMatricesRecursive(a,s4,nsize,ax+nsize,ay+nsize,0,0);
                Matrix p5 = multiplyMatricesRecursive(s5,s6,nsize,0,0,0,0);
                Matrix p6 = multiplyMatricesRecursive(s7,s8,nsize,0,0,0,0);
                Matrix p7 = multiplyMatricesRecursive(s9,s10,nsize,0,0,0,0);
                for (int y = 0; y < nsize; y++) {
                    for (int x = 0; x < nsize; x++) {
                        c(x,y) = p5(x,y) + p4(x,y) - p2(x,y) + p6(x,y);
                        c(x+nsize,y) = p1(x,y) + p2(x,y);
                        c(x,y+nsize) = p3(x,y) + p4(x,y);
                        c(x+nsize, y+nsize) = p5(x,y) + p1(x,y) - p3(x,y) - p7(x,y);
                    }
                }
            }

            return c;
        }

        Matrix Matrix::strassenMultiplication(const Matrix &a, const Matrix &b) {
            assert(a.m_rows == a.m_cols);
            assert(isPowerOfTwo(a.m_rows));

            int n = a.m_rows;
            return multiplyMatricesRecursive(a,b, n,0, 0, 0, 0);
        }
    }
}

#endif //I2A_MATRIX_H