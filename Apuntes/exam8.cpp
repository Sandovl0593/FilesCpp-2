#include <bits/stdc++.h>
#include <chrono>
using namespace std;

template <class T>
int binary_search(const vector<T>& A, T e, int inicio, int final){
    if (inicio <= final){
        int medio = (inicio + final) / 2;
        if (A[medio] == e)
            return medio;
        else if (A[medio] > e)
            return binary_search(A, e, inicio, medio - 1);
        else if (A[medio] < e)
            return binary_search(A, e, medio + 1, final);
    }
    return -1;
}
/*
    std::chrono::duration<double, std::milli>

*/

int main() {
    srand(time(NULL));
    cout << "Vector liviano:\n";
    // dos variables que determina el i
    chrono::time_point<chrono::system_clock> inicio, fin;
    vector<float> red(10);

    // comienzo del tiempo
    inicio = chrono::high_resolution_clock::now();
    generate(red.begin(), red.end(), [] () { return rand()%1000; });
    // detencion del tiempo
    fin = chrono::high_resolution_clock::now();
    cout << "Terminado" << endl;
    // determinando el rango del tiempo
    chrono::duration<double, milli> t = fin - inicio;
    cout << "time = " << t.count() << "ms" << endl;

    // ¿ante ejecuciones mas duraderos?
    cout << "\n-----------\nVectores masivos:\n";
    vector<double> A(200000);
    vector<double> B(200000);
    inicio = chrono::high_resolution_clock::now();
    generate(A.begin(), A.end(), [](){return rand()%1000;});
    fin = chrono::high_resolution_clock::now();
    cout << "Terminado" << endl;
    chrono::duration<double, milli> t2 = fin - inicio;
    cout << "time = " << t2.count() << "ms" << endl;

    cout << "\n-----------\nBusqueda binaria masiva:\n";
    inicio = chrono::high_resolution_clock::now();
    int indx1 = binary_search<double>(A, 500, 0, A.size()-1);
    fin = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> t3 = fin - inicio;
    cout << "pos: " << indx1 << "\nencontrado con time de : " << t3.count() << "ms\n";  

    // limpiar los datos
    red.clear();  A.clear(); B.clear();

}
