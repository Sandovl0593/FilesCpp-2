#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void sub_exam1() {
    // iterador random
    vector<int> v = {10,20,30,40};
    auto it1 = begin(v);

    // iterador bidireccional
    list<int> l = {10,20,30,40};
    auto it2 = begin(l);
    *++it2;  *++it2;
    // iterador 

    // distancia de dos posiciones
    auto dist = distance(begin(l), it2);
    // L-value de avanzar o retroceder una posicion
    auto nex = next(it2, 1);
    auto first = prev(it2, 3);
    // void para avanzar una posicion
    advance(it2, dist);
}

void sub_exam2() {
    list<int> ls = {3,2,2,4,3,1,2,1,4,3,2,1};

    // func. lambda:  parametros por defecto y SOLO un parametro referencial
    auto five_div = [base= 5] (auto x) { return x % base = 0; };
    /*  para funciones de return auto, los parametros deben ser L-values auto.  */

    // contar elementos
    cout << count(begin(ls), end(ls), 1) << endl;

    int div = 2;
    // contar elementos bajo una condicion con lambdas 
    cout << count_if(begin(ls), end(ls), [] (int x) { return x % 2 == 0; }  );

    // contar elementos bajo una condicion definida on parametros modificables
    cout << count_if(begin(ls), end(ls), [&div] (int x) { return x % ++div == 0; }  );
    /* Los parametros no locales pueden ser modificables si no se declara por defecto */
}


int main() {
    sub_exam1();
    sub_exam2();
}