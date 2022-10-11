#ifndef PROG3_TAREA3_P6_H
#define PROG3_TAREA3_P6_H
#include <iostream>
#include <vector>
#include <tuple>
#include <list>
using namespace std;

template <class... Cont>
vector<vector<int>> zip(Cont...conts) {
    int subsize = sizeof...(conts);
    auto pack = {conts...};
    using T = typename decltype(pack)::value_type;
    vector<T> expanded{pack};

    vector<vector<int>> result;
    int vectors = 0;
    auto eval = begin(expanded[0]);
    while (eval != end(expanded[0])) { vectors++; eval = next(eval, 1); }

    for (int i=0; i<vectors; i++) {
        vector<int> sub_vec(subsize);
        for (int j=0; j<subsize; j++) {
            sub_vec[j] = *next(begin(expanded[j]), i);
        } result.push_back(sub_vec);
    }  return result;
}

#endif //PROG3_TAREA3_P6_H