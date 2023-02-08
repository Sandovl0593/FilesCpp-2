#include <bits/stdc++.h>
using namespace std;

int foo(int a, int b){
    cout << "Inicializacion: " << endl;
    cout << "Invariante: " << a - (a/b)*b << endl;
    while (b > 0){
        int q = a / b;
        cout << "q: " << a << "/" << b << " = " << q << endl;
        int r = a - q * b;
        cout << "r: " << a << "- " << (q*b) << " = " << r << endl;
        // aqui siempre pasa el valor de b al a.
        a = b;
        // b podria ser o 0 o algun 
        b = r;  
        cout << "Act:  a=" << a << ", b=" << b << endl;
        // siempre acabara b = 0
    } cout << "fin" << endl;
    return a;
}

// a - (a/b)*b = a- a = 0

int main() {
    // en el caso de a = 2 , siempre a es el valor de b y
    // por lo tanto siempre termina con 2 -2 = 0
    cout << foo(2, 10) << endl;
    cout << foo(100, 2) << endl;

    cout << foo(50, 4) << endl;
}