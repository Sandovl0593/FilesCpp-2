#include <iostream>
#include <vector>
#include <list>
#include "P6.h"
using namespace std;

int main() {
    list<int> l1 = { 11, 12, 13 };
    list<int> l2 = { 21, 22, 23 };
    list<int> l3 = { 31, 32, 33 };
    auto r1 = zip(l1, l2, l3);
    for (const auto& row : r1) {
        for (const auto& value : row)
            cout << value << " ";
        cout << endl;
    }
    cout << endl;
    vector<int> v1 = { 11, 12, 13, 14, 15 };
    vector<int> v2 = { 21, 22, 23, 24, 25 };
    vector<int> v3 = { 31, 32, 33, 34, 35 };
    vector<int> v4 = { 41, 42, 43, 44, 45 };
    auto r2 = zip(v1, v2, v3, v4);
    for (const auto& row : r2) {
        for (const auto& value : row)
            cout << value << " ";
        cout << endl;
    }
}