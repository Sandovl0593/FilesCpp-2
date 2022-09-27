#ifndef PROG3_TAREA2_P1_H
#define PROG3_TAREA2_P1_H
#include <iostream>
using namespace std;

template <typename Type = string> 
Type input(string expr="") {
    Type inp;
    cout << expr; cin >> inp;
    return inp;
}


#endif //PROG3_TAREA2_P1_H