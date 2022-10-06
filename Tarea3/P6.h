#ifndef PROG3_TAREA3_P6_H
#define PROG3_TAREA3_P6_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

template <template <class ...> class... Cont>
list<vector<int>> zip(Cont<int>...conts) {
    int subsize = sizeof...(conts);
    auto eval = begin(cont);
    while (eval != end(cont)) { size++; eval = next(eval, 1); }
}

#endif //PROG3_TAREA3_P6_H