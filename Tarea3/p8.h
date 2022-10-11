#ifndef PROG3_TAREA3_P8_H
#define PROG3_TAREA3_P8_H
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

template <template <class...> class Cont = vector>
Cont<string> filter_codes(string filename, const char ctr) {
    fstream file(filename, ios::in);
    bool forw = false;

    // almacenar los codigos sin orden
    Cont<string> strings;
    string line;
    while(getline(file, line)) {
        if (line[0] == ctr)
            strings.push_back(line);
    }

    // ordenar por letra y numero
    sort(begin(strings), end(strings));
    return strings;
}

#endif //PROG3_TAREA3_P8_H