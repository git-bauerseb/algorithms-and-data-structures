#ifndef I2A_COMMON_H
#define I2A_COMMON_H

#include <cmath>
#include <limits>

template<typename T>
class Triple {
    public:
        Triple(T t1, T t2, T t3) : m_t1{t1}, m_t2{t2}, m_t3{t3}
        {}

    T m_t1;
    T m_t2;
    T m_t3;
};


const int MAX_INT = (1 << 28);
const int MIN_INT = -(1 << 28);

#endif