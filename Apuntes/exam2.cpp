#include <bits/stdc++.h>
using namespace std;

template <class T> class Foo {
public:
    Foo() { cout <<"Plantilla original" << endl; }
};

template <> class Foo<int> {
public:
    Foo() { cout <<"Plantilla especialiada" << endl; }
};


/* 
    fold variables con una clase plantilla Ts...
*/

// template <class ... Ts>
// auto print(Ts ... args) {
//     string expr = ((to_string(args)) + ...); // concatenacion de args
//     cout << expr << endl;
// }

// ejercicio 1
template<class... Ts>
auto promedio(Ts... args) {
    float s = (args +...);
    return s/(sizeof...(args));
}

//ejercicio 2
template<class... Ts>
auto norma2(Ts...args) {
    float s = ( (args*args) +...);
    return pow(s, 0.5);
}

// ejercicio 3
template<class... Ts>
auto foo(Ts...args) {
    // return (args + (args%2==0)?...: -...);
    return (args-...);
}

// ejercicio 4
template <class T> T Max(T a, T b) { return a > b ? a:b; }

template<class T, class... Ts>
auto Max(T a, T b, Ts...args) {
    return Max(Max(a,b), args...);
}



int main() {
    // Foo<double> obj1;
    // Foo<int> obj2;

    // ejercicio 1
    cout << promedio(1, 2, 3, 4, 5) << endl;
    // ejerciio 2
    cout << norma2(6, 8) << endl;
    // ejercicio 3
    cout << foo(3, 4, 5, 6) << endl;
    //ejercicio 4
    cout << Max(3, 4, 1, 9) << endl;
}
