#include <bits/stdc++.h>
using namespace std;

float promedio(vector<int> V){
    float s;
    int n = V.size();
    for (int i = 0; i < n; i++){
        s = s + V[i];
        cout << "s = " << s << ", la suma de los primeros ";
        cout << i + 1 << " terminos: ";
        for (int j = 0; j <= i; j++)
            cout << V[j] << " ";
        cout << endl;
    }
    return s / n;
}

int maximo(vector<int> V){
    int max = V[0];
    for (int i = 1; i < V.size(); i++){
        if (V[i] > max)
            max = V[i];
        // demostrando el mantenimiento
        cout << "max = " << max << ", el MAXIMO de los primeros ";
        cout << i + 1 << " terminos: ";
        for (int j = 0; j <= i; j++)
            cout << V[j] << " ";
        cout << endl;
    }
    return max;
}

int producto(int a, int b){
    int x = a;
    int y = b;
    int total = 0;
    // demostrando el inicializacion
    cout << "Inicializacion:" << endl;
    cout << "Inv. Bucle = " << total + x * y << endl;

    while (x > 0){
        if (x % 2 == 1)
            total = total + y;
        x = x / 2;
        y = y * 2;
        // observando en la obtencion y acercamiento de la solucion
        cout << "Inv. Bucle = " << total + x * y;
        cout << ", x = "<< x << " y = " << y;
        // demostrando el mantenimiento
        cout << " total = " << total << endl;
    }
    cout << "Fin." << endl;
    return total;
}
int main() {
    //vector<int> V = {6,1,7,6,11,3,13,3,1};
    //promedio(V);
    //maximo(V);
    cout << producto(11,7) << endl;
    return 0;
}