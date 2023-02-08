#ifndef PROG3_TAREA2_P8_H
#define PROG3_TAREA2_P8_H
#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

template <typename Val, typename ...Ty>
bool are_same() {
    vector<bool> types;
    // cada parametro comparar con el primero
    (types.push_back(is_same<Val, Ty>::value),...);
    for (const auto& type: types)
       if (!type)   return false;
    return true;
}

#endif //PROG3_TAREA2_P8_H