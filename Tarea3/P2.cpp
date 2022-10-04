#include <iostream>
#include <sstream>
#include <list>
#include <forward_list>
#include "P2.h"
using namespace std;


int main() {
    stringstream os;
    list<int> l1 = { 1, 2, 3, 4, 5 };
    list<int> l2 = { 10, 20 };
    auto res1 = sum_range(l1, l2);
    for (const auto& item : res1)
        cout << item << " ";
    cout << endl;
    forward_list<int> fl1 = { 10, 20, 30, 40, 50, 60, 70, 80 };
    forward_list<int> fl2 = { 4, 8, 7};
    auto res2 = sum_range(fl1, fl2);
    for (const auto& item : res2)
        cout << item << " ";
} 