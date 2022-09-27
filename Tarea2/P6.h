#ifndef PROG3_TAREA2_P6_H
#define PROG3_TAREA2_P6_H
#include <iostream>
#include <sstream>
using namespace std;

template <typename Ts>
string to_type() { return typeid(Ts).name(); } 

template <typename... Ts, typename T>
int index_of(T value) {
    string str = ((to_type<Ts>()+" ")+...);
    istringstream ss(str);
    int i= 0;  string porc;
    while(getline(ss, porc, ' ')) {
        if (porc == typeid(value).name())
            return i;
        i++;
    } return -1;
}

#endif //PROG3_TAREA2_P6_H