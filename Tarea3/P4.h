#ifndef PROG3_TAREA3_P4_H
#define PROG3_TAREA3_P4_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <template <class ...> class Cont>
vector<int> delete_duplicated(Cont<int> cont) {
    vector<int> result(begin(cont), end(cont));

    auto ende = end(result);
    for (auto it = begin(result); it != ende; ++it) {
        ende = remove(it +1, ende, *it);
    }
 
    result.erase(ende, end(result));
    return result;
}

#endif //PROG3_TAREA3_P4_H