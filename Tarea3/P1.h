#ifndef PROG3_TAREA3_P1_H
#define PROG3_TAREA3_P1_H
#include <iostream>
#include <vector>
using namespace std;

template <typename It>
bool operator<(It it1, It it2) { return *it1 < *it2; }

template <template <class ...> class Cont>
vector<vector<int>> split_range(Cont<int> conten, int num) {
    int size = 0; 
    auto eval = begin(conten);
    while (eval != end(conten)) { size++;  eval = next(eval, 1); }
    int sub_size = size/num;

    auto it = begin(conten);
    vector<vector<int>> result;
    for (int i=1; i<=num; i++) {
        vector<int> sub;
        while (it < next(begin(conten), i*sub_size)) {
            sub.push_back(*it);   it++;
        }
        result.push_back(sub);
    }
    for (; it != next(begin(conten), size); it++)  result[num-1].push_back(*it);
    return result;
}

#endif //PROG3_TAREA3_P1_H