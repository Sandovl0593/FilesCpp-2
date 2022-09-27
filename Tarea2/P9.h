#ifndef PROG3_TAREA2_P9_H
#define PROG3_TAREA2_P9_H
#include <iostream>
using namespace std;

template <typename T, int size>
void init_array(T (&arr)[size], T init=0) {
    auto j= init;
    for (int i=0; i<size; i++)  arr[i] = 0;
    
    for (int i=0; i<size; i++) {
        if ((arr[i]) || arr[i] == 0)    arr[i] = j;
        j++;
    }
}

template <typename T, typename U, int size>
void init_array(T (&arr)[size], U init, U step) {
    T j= init;
    for (int i=0; i<size; i++)  arr[i] = 0;
    
    for (int i=0; i<size; i++) {
        if (!(arr[i]) || arr[i] == 0)    arr[i] = j;
        j+=step;
    }
}

template <typename T, typename U, int size>
void init_array(T (&arr)[size], U init, U end, U step) {
    T j= init;
    for (int i=0; i<size; i++)  
        if (arr[i] < 0) arr[i] = 0;

    for (int i=0; i<size; i++) {
        if (!(arr[i]) || arr[i] == 0)    arr[i] = j;
        if (j<=end)         j+=step;
    }
}


#endif //PROG3_TAREA2_P9_H