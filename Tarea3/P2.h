#ifndef PROG3_TAREA3_P2_H
#define PROG3_TAREA3_P2_H
#include <iostream>
#include <vector>
using namespace std;

template <template <class ...> class Cont>
vector<int> sum_range(Cont<int> cont, Cont<int> divder) {
    vector<int> result;
    int size= 0;
    auto eval = begin(cont);
    while (eval != end(cont)) { 
        size++;   eval = next(eval, 1);
    }
    
    auto it = begin(cont);
    while (it != next(begin(cont), size-1)) {
        for (int dv: divder) {
            result.push_back(*it + dv);
            if (it != next(begin(cont), size-1))   it= next(it, 1);
            else                                   break;
        }
    } return result;
}

#endif //PROG3_TAREA3_P2_H