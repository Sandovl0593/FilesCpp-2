#ifndef PROG3_TAREA3_P3_H
#define PROG3_TAREA3_P3_H
#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <template <class ...> class Cont>
list<int> delete_range(Cont<int> cont, vector<int> del) {
    list<int> result(begin(cont), end(cont));
    for (int s: del)  result.remove(s);
    return result;
}

template <template <class ...> class Cont>
list<int> delete_range(Cont<int> cont, int del) {
    list<int> result(begin(cont), end(cont));
    result.remove(del);
    return result;
}


#endif //PROG3_TAREA3_P3_H