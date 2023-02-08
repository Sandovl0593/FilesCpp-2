#ifndef PROG3_ADAPTADORES_P6_H
#define PROG3_ADAPTADORES_P6_H
#include <stack>
#include <algorithm>
#include <list>
#include <functional>
using namespace std;

template <typename T>
T find_in_stack(stack<T> s, function<bool(T)> cmpr) {
    stack<T> copys = s;
    list<T> elements;
    while(!copys.empty()) {
        elements.push_front(copys.top());
        copys.pop();
    }
    auto find = find_if(begin(elements), end(elements), cmpr);
    return *find;
}

#endif //PROG3_ADAPTADORES_P6_H