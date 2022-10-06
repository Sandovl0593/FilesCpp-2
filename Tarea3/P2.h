#ifndef PROG3_TAREA3_P2_H
#define PROG3_TAREA3_P2_H
#include <iostream>
#include <vector>
using namespace std;

template <template <class ...> class Cont>
vector<int> sum_range(Cont<int> cont, Cont<int> divder) {
    vector<int> result;

    // size of cont
    int size= 0;
    auto eval = begin(cont);
    while (eval != end(cont)) { size++; eval = next(eval, 1); }

    // size of divder
    int sub_size = 0; 
    auto eval2 = begin(divder);
    while (eval2 != end(divder)) { sub_size++;  eval2 = next(eval2, 1); }
    int vects = size/sub_size;

    // itering
    auto at = begin(divder);
    auto it = begin(cont);
    for (int i=1; i<=vects; i++) {
        while (it != next(begin(cont), i*sub_size)) {
            result.push_back(*it+ *at);
            advance(it, 1);   advance(at, 1);
        }
        at = begin(divder);
    }
    for (; it != next(begin(cont), size); advance(it, 1)) {
        result.push_back(*it+ *at);
        advance(at, 1);
    }
    return result;
}

#endif //PROG3_TAREA3_P2_H