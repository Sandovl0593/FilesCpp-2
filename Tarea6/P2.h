#ifndef PROG3_ADAPTADORES_P2_H
#define PROG3_ADAPTADORES_P2_H
#include <stack>
#include <list>
using namespace std;

template <typename T>
stack<T> join_stacks(stack<T> a, stack<T> b) {
    list<T> unorder;
    while (!b.empty()) {
        unorder.push_front(b.top());   b.pop();
    }
    while (!a.empty()) {
        unorder.push_front(a.top());   a.pop();
    }
    stack<T> resp;
    for (const auto& i: unorder)   resp.push(i);
    return resp;
}

#endif //PROG3_ADAPTADORES_P2_H