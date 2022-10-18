#ifndef PROG3_TAREA3_P9_H
#define PROG3_TAREA3_P9_H
#include <iostream>
#include <vector>
#include <utility>
#include <typeinfo>
#include <memory>
#include <initializer_list>
using namespace std;

template <typename T>
struct is_unique_ptr: false_type {};

template <typename T>
struct is_unique_ptr<unique_ptr<T>>: true_type {};

// pair<int, int>* new_ptr(unique_ptr<pair<int, int>> value) {
//     pair<int, int>* fred = new pair<int, int>(value->first, value->second);
//     return fred;
// }

template <typename T, int sz>
class fixed_stack {
    int size_ac = sz;
public:
    vector<T> list;
    fixed_stack() {}
    fixed_stack(initializer_list<T> lst): list(lst) {}
        // this -> tope = new_ptr<T>(list, sz, sz);

    fixed_stack<T, sz> operator=(initializer_list<T> lst) {
        fixed_stack<T, sz> res(lst);
        return res;
    }

    T& top() { return list.back(); }
    void pop() {
        size_ac--;
        list.pop_back();
        // tope = *next(begin(list), sz-1);
    }

    bool push(T val) {
        if (sz == size_ac)   return false;
        size_ac++;
        list.push_back((typeid(val) == typeid(unique_ptr<pair<int, int>>))? move(val):val);
        // list.push_back(val);
        return true;
        // tope = *next(begin(list), sz-1);
    }
    bool empty() { return  list.empty(); }
    int size() { return list.size(); }

    auto gbegin() { return list.begin(); }

    ~fixed_stack() { list.clear(); }
};

template <int sz>
class fixed_stack_pusher {
    fixed_stack<int, sz> contain;
    vector<int>::iterator elem;
public:
    fixed_stack_pusher(fixed_stack<int, sz> stack): contain(stack) {
        this -> elem = contain.gbegin();
    }
    vector<int>::iterator operator() (fixed_stack<int, sz> stack) { return elem; }

    fixed_stack_pusher operator++() { advance(elem, 1);  return *this; }
    auto operator*() { return *elem; }

};

#endif //PROG3_TAREA3_P9_H