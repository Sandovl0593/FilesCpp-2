#include <bits/stdc++.h>
#include <sstream>
using namespace std;

template <class ... Args>
auto foo(Args ...args) {
    string expr = ((to_string(args)+" ") + ...);
    int siz = sizeof...(args);
    vector<string> express;
    istringstream ss(expr);  string porc;

    while (getline(ss, porc, ' '))
        express.push_back(porc);

    float result = stod(express[0]);
    for (int i=1; i<siz; i++) {
        result -= stod(express[i]);
    }
    return result;
}

int main() {
    // cout << foo(1, 12) << endl;
}