#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

int main() {
    // iterador random
    vector<int> v = {10,20,30,40};
    auto it1 = begin(v);

    // iterador bidireccional
    list<int> l = {10,20,30,40};
    auto it2 = begin(l);
    *++it2;  *++it2;
    // iterador 

    // distancia de dos posiciones
    auto dist = distance(begin(l), it2);
    // Rvalue de avanzar o retroceder una posicion
    auto nex = next(it2, 1);
    auto first = prev(it2, 3);
    // void para avanzar una posicion
    advance(it2, dist);
}