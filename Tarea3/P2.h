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
    
    // auto it = begin(cont);
    // while (it != next(begin(cont), size-1)) {
    //     for (int dv: divder) {
    //         result.push_back(*it + dv);
    //         if (it != next(begin(cont), size-1))   it= next(it, 1);
    //         else                                   break;
    //     }
    // } return result;

    int sub_size = 0; 
    auto eval2 = begin(divder);
    while (eval2 != end(divder)) { sub_size++;  eval2 = next(eval2, 1); }
    auto vects = size/sub_size;
    
    auto it = begin(cont);
    for (int i=1; i<=vects; i++) {
        vector<int> sub;
        while (it < next(begin(cont), i*sub_size)) {
            sub.push_back(*it);   it++;
        }
        result.push_back(sub);
    }
    for (; it != next(begin(cont), size); it++)  result[vects-1].push_back(*it);
    return result;
}

#endif //PROG3_TAREA3_P2_H