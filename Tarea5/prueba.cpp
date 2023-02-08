#include <iostream>
#include <vector>
#include "P1.h"
#include "P2.h"
#include "P3.h"
#include "P4.h"
using namespace std;

int main() {
    linked_list_t<int> ll;
    // cantidad
    int nhilos = {};
    cin >> nhilos;
    // Hilos
    vector <thread> vhilos(nhilos);
    for (int i = 0; i < nhilos - nhilos/4; ++i) {
        vhilos[i] = thread([&ll, i] { ll.push_front(i); });
    }
    for (int i = nhilos - nhilos/4; i < nhilos; ++i) {
        // cout << ll.arr[0] << endl;
        vhilos[i] = thread([&ll] { ll.pop_front(); }); 
    }
    for (auto& hilo: vhilos) {
        hilo.join();
        cout << *ll.begin() << endl;
    }
    // Resultado


    cout << ll.size() << endl;
}