#ifndef PROG3_TAREA2_P3_H
#define PROG3_TAREA2_P3_H
#include <iostream>
using namespace std;

template <typename It>
auto sumarizar(It beg, It end, double num) {
    auto suma = num;
    for (It it=beg; it!=end; it++)
        suma += *it;
    return suma;
}


#endif //PROG3_TAREA2_P3_H