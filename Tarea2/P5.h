#ifndef PROG3_TAREA2_P5_H
#define PROG3_TAREA2_P5_H
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

template <class ...Ts>
auto suma_producto(Ts... args) {
    string expr = ((to_string(args)+" ") + ...);
    int siz = sizeof...(args);
    vector<string> express;
    istringstream ss(expr);  string porc;

    while (getline(ss, porc, ' '))
        express.push_back(porc);

    float suma = 0;
    for (int i=0; i<siz-1; i+=2) {
        suma += (stod(express[i])*stod(express[i+1]));
    }
    if (siz % 2 != 0)  suma += stod(express[siz-1]);
    return suma;
}


#endif //PROG3_TAREA2_P5_H