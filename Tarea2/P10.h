#ifndef PROG3_TAREA2_P10_H
#define PROG3_TAREA2_P10_H
#include <iostream>
#include <algorithm>
using namespace std;


template <typename Container>
class searcher {
    Container arr_r;
public:
    searcher(Container& arr): arr_r(arr) {
        sort(arr_r.begin(), arr_r.end());
        sort(arr.begin(), arr.end());
    }

    friend int operator<<(searcher<Container> arrt, int num) {
        for (int i=0; i<arrt.arr_r.size(); i++) {
            if (arrt.arr_r[i] == num)
                return i;
        } return -1;
    }

    searcher<Container> operator=(Container& arr) {
        searcher<Container> result(arr);
        return result;
    }
};


#endif //PROG3_TAREA2_P10_H