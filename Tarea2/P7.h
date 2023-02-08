#ifndef PROG3_TAREA2_P7_H
#define PROG3_TAREA2_P7_H
#include <iostream>
#include <map>
#include <array>
using namespace std;

template <template <class ...> class Container, typename T>
ostream& operator<<(ostream& os, Container<T>& lst) {
    int it = 0;
    os << "{";
    for (auto &i: lst) {
        it++;  os << i;
        if (it < lst.size())  os << ", ";
    }
    os << "}";
    return os;
}


template <typename T, size_t size>
ostream& operator<<(ostream& os, array<T, size>& arr) {
    int it = 0;
    os << "{";
    for (auto &i: arr) {
        it++;  os << i;
        if (it < size)  os << ", ";
    }  
    os << "}";
    return os;
}


template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& map) { 
    int it = 0;
    os << "{";
    for (auto &pair: map) {
        os << "{" << pair.first << ": " << pair.second << "}";
        it++;
        if (it < map.size())   os << ", ";
    }
    os << "}";
    return os;
}

#endif //PROG3_TAREA2_P7_H