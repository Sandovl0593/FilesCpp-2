#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

float** generate_rand(int row, int col) {
    float** arr = new float*[row];
    for (int i=0; i<col; i++) {
        float* rows = new float[col];
        for (int j=0; j<col; j++) 
            *(rows+j) = rand()%9;
        *(arr+i) = rows;
    }
}


float** transposicion(float** arr, int row, int col) {
    float** res = new float*[row];
    for (int i=0; i<col; i++) {
        float* fila = new float[row];
        res[i] = fila;
    }
    for (int i=0; i<row; i++) {
        for (int k=0; k<col; i++) {
            *(*(res+k)+i) = *(*(arr+i)+k);
        }
    } return res;
}

void producto(float** arr1, float** arr2, float**& res, int row, int col, int chunk, int chunks){
    int inicio = chunk * (row/chunks);
    int fin = (chunk + 1) * (row/chunks);
    for (int i=inicio; i<fin; i++) {
        for (int j=0; j<row; j++){
            int s = 0.;
            for (int k=0; k<col; k++)
                s += arr1[i][k] * arr2[k][j]; 
            res[i][j] = s;
        }
    }
}  

void mean(float** arr, int row, int col, int& pre, int chunk, int chunks) {
    int inicio = chunk * (row/chunks);
    int fin = (chunk + 1) * (row/chunks);
    float count = row*col;
    for (int i=inicio; i<fin; i++) {
        for (int j=0; j<col; j++)
            pre += arr[i][j]; 
    } 
    pre = pre/count;
}

void suma(float**& arr, int siz, float num) {
    for (int i=0; i<siz; i++) {
        for (int j=0; j<siz; j++){
            arr[i][j] = arr[i][j] + num;
        }
    }
}

int main() {
    srand(time(NULL));
    // dimensions
    int row = 10, col = 8;
    
    // matriz random A
    float** A = generate_rand(row, col);

    // transpuesta de A
    float** AT = transposicion(A, row, col);
    
    // A de mxn X At de nxm origina como resultado mxm
    float** AxAT = new float*[row];
    for (int i=0; i<row; i++) {
        float* rows = new float[row];
        AxAT[i] = rows;
    }
    vector<thread> hilo1;

    // producto de A X AT
    for (int i=0; i<2; i++) {
        hilo1.push_back(thread(&producto, A, AT, ref(AxAT), row, col, i, 2));
    }
    for (int i=0; i<2; i++)  hilo1[i].join(); 

    // mean(A)
    float prom = 0;
    vector<thread> hilo2;
    for (int i=0; i<2; i++) {
        hilo2.push_back(thread(&mean, A, row, ref(prom), i, 2));
    }
    for (int i=0; i<2; i++)  hilo2[i].join(); 
    
    // suma de AxAT y mean(A)
    suma(AxAT, row, prom);

    // A x AT resulta como matriz mxm
    for (int i=0; i<row; i++) {
        for (int j=0; j<row; j++) 
            cout << AxAT[i][j] << " ";
        cout << endl;
    }

    for (int i=0; i<row; i++) {
        for (int j=0; i<col; i++) 
            delete [] AT[j];
        delete[] A[i]; 
    } delete[] A;  delete[] AT;

    for (int i=0; i<row; i++) {
        delete AxAT[i];
    } delete[] AxAT;
}