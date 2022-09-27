#ifndef PROG3_TAREA2_P7_H
#define PROG3_TAREA2_P7_H
#include <iostream>
#include <vector>
#include <map>
#include <array>
using namespace std;

// void print(string resp) { cout << resp; }
ostream& operator<<(ostream& os, string value);

template <typename Container>
ostream& operator<<(ostream& os, Container value) {
    string resp = "{";
    for (const auto &i: value)  resp += to_string(i)+", ";
    resp[resp.size()-2] = '}';
    os << resp;
    return os;
}

// template <template <class...> class Type, typename T> 
// ostream& operator<< <Type<T>>(ostream& os1, Type<T> value){
//     string resp = "{";
//     for (const auto &i: value)  resp += to_string(i)+", ";
//     resp[resp.size()-2] = '}';
//     os1 << resp;
//     return os1;
// }

// template <typename T, int size> 
// ostream& operator<< <array<T, size>>(ostream& os, array<T, size> value){
//     string resp = "{";
//     for (const auto &i: value)  resp += to_string(i)+", ";
//     resp[resp.size()-2] = '}';
//     os << resp;
//     return os;
// }

template <typename T, typename U>
ostream& operator<< <map<T, U>>(ostream& os, map<T, U> value){
    string resp = "{";
    for (const auto &p: value) {
        string s(1, p.first);
        resp += '{' + s + ": " + to_string(p.second) + "}, ";
    }
    resp[resp.size()-2] = '}';
    os << resp;
    return os;
}

#endif //PROG3_TAREA2_P7_H