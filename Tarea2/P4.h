#ifndef PROG3_TAREA2_P4_H
#define PROG3_TAREA2_P4_H
#include <iostream>
using namespace std;


template <class T, typename U= int> class smart_ptr {
    T* valor;
public:
    smart_ptr() {}
    smart_ptr(T val) {  valor = new T(val); }
    smart_ptr(U val1, U val2) {  valor = new T(val1, val2);  }

    // smart_ptr(const smart_ptr<T>& obj) {
    //     T* val = new T(obj.valor);
    //     this -> valor = val;
    // }

    friend T operator*(smart_ptr<T> ptr) { return *ptr.valor; }

    T* operator->() { return valor; }

    friend ostream& operator<<(ostream& os, T* ptr) {
        os << *ptr; return os;
    }

    // friend ostream& operator<<(ostream& os, smart_ptr<T> ptr) {
    //     os << *ptr.valor << endl; return os;
    // }

    ~smart_ptr() {}
};


template <class T> 
smart_ptr<T> make_smart_ptr(T val) {
    smart_ptr<T> new_(val);
    return new_;
}

template <class T, typename U>
smart_ptr<T> make_smart_ptr(U val1, U val2) {
    smart_ptr<T> new_(val1, val2);
    return new_;
}

class point {
    int x;
    int y;
public:
    point(int x, int y): x{x}, y{y} {}
    point() = default;

    friend ostream& operator<< (ostream& os, const point& p) {
        os << "{" << p.x <<", " << p.y << "}";
        return os;
    }

    int get_x() { return x; }
    int get_y() { return y; }
};


#endif //PROG3_TAREA2_P4_H