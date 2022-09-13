#include <bits/stdc++.h>
#include <list>
using namespace std;
 
// referencia L-value
int sumar(int a, int b) { return a+b; }
// funcion no asignable para R-values
int sumart(int& a, int& b) { return a+b; }
// referencia L-value = R-value
int sumar2(const int& a, const int& b) { return a+b; }
// referencia R-value
int sumar3(int&& a, int&& b) { a+= 10; b+= 10; return a+b;}


// template por parametro no tipo
template <typename T, int sizA, int sizB> 
auto&& union_arr(T (&a)[sizA], T (&b)[sizB]) { // genera los tamaños de array
    static T result [sizA + sizB];
    int j=0;
    for (int i=0; i<sizA; i++) {
        result[j++] = a[i];
    }
    for (int i=0; i<sizB; i++) {
        result[j++] = b[i];
    }
    return result;
}

/* parametro template 
     // deducible para tipos que se encuentren en la
     lista de parametros
     // 
*/
template <template <typename...> class Cont_type=vector,
          typename T>
Cont_type<T> to_contenerador(int sz, T valor) {
    Cont_type<T> cont(sz);
    for (int i=0; i<sz; i++)  cont[i] = valor;
    return cont;
} 

template <template <typename...> class Cont_type=vector, 
          typename T>
void print_cont(Cont_type<T> vec) {
    for (const auto& i: vec) cout << i << " ";
    cout << endl;
}

int main(){
    int r = sumar(3,4);
    int r2 = sumar2(3, 4);
    int r3 = sumar3(3, 4);
    int r4 = 3 + 4; // L-value (modificable en types no const)
    cout << 3 + 4 << endl;  // R-value (no modificable y estatico)

    auto vec1 = to_contenerador(4, 'A');
    auto vec2 = to_contenerador<list>(3, 11);
    print_cont(vec1);
    print_cont(vec2);
}