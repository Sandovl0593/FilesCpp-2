#ifndef PROG3_TAREA3_P9_H
#define PROG3_TAREA3_P9_H
#include <iostream>
#include <vector>
#include <typeinfo>
#include <memory>
#include <initializer_list>
#include <algorithm>
using namespace std;

template<class T>
T new_ptr(vector<T> list, int size, int size_ant) {
    T tope = *next(begin(list), size_ant-1);
    if (typeid(tope).name() == "St10unique_ptrISt4pairIiiESt14default_deleteIS1_EE") {
        T new_top = make_unique(*next(begin(list), size-1));
        tope = move(new_top);
    } return tope;
}

template <typename T, int sz>
class fixed_stack {
    T tope;
public:
    vector<T> list;
    fixed_stack() {}
    fixed_stack(initializer_list<T> lst): list(lst) {
        this -> tope = new_ptr<T>(list, sz, sz);
    }

    fixed_stack<T, sz> operator=(initializer_list<T> lst) {
        fixed_stack<T, sz> res(lst);
        return res;
    }

    T top() { return tope; }
    void pop() {
        int size_an = sz;
        list.pop_back();
        tope = new_ptr(list, sz, size_an);
        // tope = *next(begin(list), sz-1);
    }

    bool push(T value) {
        int size_an = sz;
        list.push_back(value);
        if (sz < list.size()) {
            list.pop_back();  return false;
        } 
        tope = new_ptr(list, sz, size_an);
        // tope = *next(begin(list), sz-1);
        return true;
    }
    bool empty() { return  list.empty(); }
    int size() { return list.size(); }
};

template <typename T, int sz>
class fixed_stack_pusher {
    vector<int>::iterator elem;
public:
    fixed_stack_pusher(fixed_stack<T, sz> stack) {
        this -> elem = stack.list.begin();
    }
};

/*template <typename T, int sz>
class fixed_stack {
    T tope;
    vector<T> refer;
    int size_ac = sz;
public:
    vector<T> list;
    fixed_stack() {}
    fixed_stack(initializer_list<T> lst): list(lst), refer(lst) {
        this -> tope = *next(begin(refer), sz-1);
    }

    fixed_stack<T, sz> operator=(initializer_list<T> lst) {
        fixed_stack<T, sz> res(lst);
        return res;
    }

    T top() { return tope; }
    void pop() {
        list.pop_back(); size_ac--;
        tope = *next(begin(refer), size_ac-1);
    }

    bool push(T value) { 
        list.push_back(value);
        refer.push_back(value);
        size_ac++;
        if (sz < list.size()) {
            list.pop_back();
            size_ac--;  return false;
        } 
        tope = *next(begin(refer), size_ac-1);
        return true;
    }
    bool empty() { return  list.empty(); }
    int size() { return list.size(); }
};*/

#endif //PROG3_TAREA3_P9_H