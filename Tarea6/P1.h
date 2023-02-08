#ifndef PROG3_ADAPTADORES_P1_H
#define PROG3_ADAPTADORES_P1_H
#include <stack>
#include <list>
using namespace std;

template <typename T>
stack<T> merge_stacks(stack<T> a, stack<T> b) {
    list<T> unorder;
    bool interc = true;
    while (!a.empty() || !b.empty()) {
        if (interc) {
            if (!b.empty()) {
                unorder.push_front(b.top());   b.pop();
            }
        } else {
            if (!a.empty()) {
                unorder.push_front(a.top());   a.pop();
            }
        } interc = !interc;
    } 
    stack<T> resp;
    for (const auto& i: unorder)   resp.push(i);
    return resp;
}

#endif //PROG3_ADAPTADORES_P1_H