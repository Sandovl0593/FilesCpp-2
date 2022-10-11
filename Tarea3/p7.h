#ifndef PROG3_TAREA3_P7_H
#define PROG3_TAREA3_P7_H
#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <class Cont>
list<int> rotate_range(Cont cont, int pos) {
    int size = 0;
    auto eval = begin(cont);
    while (eval != end(cont)) { size++; eval = next(eval, 1); }

    if (pos < 0) {
        list<int> resu(next(begin(cont), abs(pos)), end(cont));
        for (int i=0; i<abs(pos); i++)
            resu.push_back(*next(begin(cont), i));
        return resu;
    }

    list<int> resu(begin(cont), next(begin(cont), size-pos));
    for (int i=0; i<pos; i++)
        resu.push_front(*next(begin(cont), size-1-i));
    return resu;
}

#endif //PROG3_TAREA3_P7_H