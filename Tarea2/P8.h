#ifndef PROG3_TAREA2_P8_H
#define PROG3_TAREA2_P8_H
#include <iostream>
#include <vector>
#include <typeinfo>
#include <sstream>
using namespace std;

template <typename Ts>
string to_type() { return typeid(Ts).name(); } 

template <typename... Ts>
bool are_same() {
    string srt = ((to_type<Ts>()+" ")+...);
    vector<string> express;
    istringstream ss(srt); string parc;
    while(getline(ss, parc, ' '))
        express.push_back(parc);
    
    string type_eval = express[0];
    for (const string& i: express) {
        if (i != type_eval)
            return false;
    } return true;
}

#endif //PROG3_TAREA2_P8_H