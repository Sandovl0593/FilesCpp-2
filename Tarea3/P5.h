#ifndef PROG3_TAREA3_P5_H
#define PROG3_TAREA3_P5_H
#include <iostream>
#include <utility>
#include <tuple>
using namespace std;

template <class ... Type>
tuple<Type&...> unpack(Type&... types) {
    tuple<Type&...> pack(types...);
    return pack;
}


#endif //PROG3_TAREA3_P5_H