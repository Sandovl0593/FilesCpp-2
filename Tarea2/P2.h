#ifndef PROG3_TAREA2_P2_H
#define PROG3_TAREA2_P2_H
#include <iostream>
#include <vector>

template <typename T, typename D>
void print(T beg, T end, std::ostream& output, D delim) {
    T it= beg;
    for (; it != next(end, -1); it++)
        output << *it << delim;
    if (beg != end)
        output << *it;
}


#endif //PROG3_TAREA2_P2_H