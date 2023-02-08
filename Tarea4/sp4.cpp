#include "sp4.h"
#include <iostream>
#include <iterator>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <vector>
#include <random>
#include <queue>
using namespace std;

// n = numero de filas
// m = numero de columnos
// n == m el caso mas desfavorable

using row_t = vector<int>;
using matrix_t = vector<row_t>;

bool ejercicio_1(const matrix_t& matrix) {
  auto sz_row = size(matrix);         // Cantidad de filas            // O(1)
  auto sz_col = size(matrix.front()); // Cantidad de columnas         // O(1)
  auto tab = vector<bool>(sz_row * sz_col, false);                    // O(n*m) // O(n^2)

  // tab: [(row=1): f, f, f, f, f,  (row=2): f, f, f, f, f, ....] -- n veces

  for (const auto& row: matrix)                   // O(n) fila n de la matriz
    for (const auto& value: row)                  // O(m) elemento m de la fila n
      tab[value - 1] = true;     //  O(1)

  for (const auto& i: tab)                        // O(n*m)
    if(!tab[i])
      return false;

  return true;                                    // O(1)
}
// O(1) + O(n^2) + O(n)*O(n) + O(n^2) + O(1) 
// = O(1) + O(n^2) + O(n^2) + O(n^2) + O(1)
// = O(1 + n^2 + n^2 + n^2 + 1) = O(2 + 3n^2)
// = O(n^2) considerando una matriz cuadrada

// O(1) + O(n*m) + O(n)O(m) + O(n*m) + O(1)
// O(1) + O(nm) + O(nm) + O(nm) + O(1)
// O(2) + O(3nm)
// O(2 + 3mn)
// O(3nm)
// = O(nm) para un C = 4 y n0 = 1 tal que n >= n0 m >= n0
std::string bigO_1() {
    string result = "O(n^2)";
    return result;
}

void ejercicio_2(int n) {
  for( int i = n;  i > 0;  i /= 2 ) {  // ... log(n)
    for( int j = 1;  j < n;  j *= 2 ) {  //  ... log(n)
      for( int k = 0;  k < n;  k += 2 ) { //  ... n
        // ... constant number of operations
      }
    }
  }
}

// log(n)*log(n) * n = n*log(n)^2

std::string bigO_2() {
    // Escribir el resultado del análisis
    string result = "O(n*log(n)^2)";
    return result;
}

void ejercicio_3(int n) {
  auto sum = 0;  // ... C
  for ( int i = 1; i < n; i *= 2 ) {   //  ... log(n)
    for ( int j = n; j > 0; j /= 2 ) {   //  ... log(n)
      for ( int k = j; k < n; k += 2 ) {   //  ... n
        sum += (i + j * k );  //  ... C
      }
    }
  }
}

// C + log(n)*log(n)*n = O(nlog(n)^2)

std::string bigO_3() {
    // Escribir el resultado del análisis
    string result = "O(n*log(n)^2)";
    return result;
}

void ejercicio_4(int n) {
  for( int i = n;  i > 0;  i-- ) {       // ... n
    for( int j = 1;  j < n;  j *= 2 ) {  // ... log(n)
      for( int k = 0;  k < j;  k++ ) {   // ... m
        // ... constant number C of operations
      }
    }
  }
}

// n*log(n)*m = 0(n*m)

std::string bigO_4() {
    // Escribir el resultado del análisis
    string result = "O(n*m)";
    return result;
}

void ejercicio_5(int n) {
  for( int bound = 1; bound <= n; bound *= 2 ) {  // ... log(n)
    for( int i = 0; i < bound; i++ ) {      // ... m
      for( int j = 0; j < n; j += 2 ) {     // ... n
        // ... constant number of operations 
      }
      for( int j = 1; j < n; j *= 2 ) {     // ... log(n)
        // ... constant number of operations
      }
    }
  }
}

// log(n) * m * (n+log(n)) 
// log(n) * m * n = O(m*nlog(n))

std::string bigO_5() {
    // Escribir el resultado del análisis
    string result = "O(m*nlog(n))";
    return result;
}

int randint(int first, int last) {
  random_device rd;
  uniform_int_distribution<int> dis(first, last);
  return dis(rd);
}

int ejercicio_6(int n) {
  if ( n <= 0 ) return 0;                               // ... C1
  int i = randint( 0, n - 1 );              // .. C2
  return ejercicio_6( i ) + ejercicio_6( n - 1 - i );    // ... O(log(n))
      // i + n - 1 - i // i + n - 1 - i
      //  ejercicio_6(n - 1) 
}

// C1 + C2 + log(n) = O(log(n))

std::string bigO_6() {
    // Escribir el resultado del análisis
    string result = "O(log(n))";
    return result;
}

void ejercicio_7(int n) {
  int k = 1;    // ... C
  while (k <= n)
    k = 3 * k;     // ... log(n)
}

// C + log(n) = O(log(n))

std::string bigO_7() {
    // Escribir el resultado del análisis
    string result = "O(log(n))";
    return result;
}

void ejercicio_8(int n) {
  for (int i = 0; i < n; ++i) {    // ... n
    int j = i;              // ... C1
    while (j < i * i) {
      j = j + 1;            // ... n
      if (j % i == 0)       // ... C2
        for (int k = 0; k < j; ++k)   // .. m
          cout << "utec" << endl;
    }
  }
}

// n * (C1 + n* (C2 + m)) 
// n * (n*m)) = O(m *n^2)

std::string bigO_8() {
    // Escribir el resultado del análisis
    string result = "O(m*n^2)";
    return result;
}

void ejercicio_9(int n) {
  int count = 0;     // ... C1
  for (int i = n/2; i < n; ++i) {     // ... n
    int j = 1;       // ... C2
    while (j + n/2 <= n) {            // ... n (esta recorriendo j)
      int k = 1;     // ... C3
      while (k <= n) {        // ... n
        ++count;     // ... C4
        k *= 2;      // ... log(n)
      } // end while
      ++j;           // ... C6
    } // end while
  } // end for
  std::cout << count;
}

// C1 + n *(C2 + n*(C3 + C4log(n) + C6))
// C1 + n * (C2 + nlog(n))
// C + n^2 *log(n) = O(n^2 * log(n))

std::string bigO_9() {
    // Escribir el resultado del análisis
    string result = "O(n^2 *log(n))";
    return result;
}

void ejercicio_10(int n) {
  int sum = 0;        // ... C1
  for (int i = 0; i < sqrt(n)/2; ++i)   // ... n
    sum++;            // ... C2
  int j = 0;          // ... C3
  for (; j < sqrt(n)/4; ++j)            // ... n
    sum++;            // ... C4
  for (int k = 0; k < 8 + j; ++k)            // ... m
    sum++;            // ... C5
  cout << sum << endl;
}

// C1 + C2n + C3 + C4n + C5m = O(n+m) = O(n)  
// siempre n > m, ya que j recorre hasta sqrt(n)/4 que es menor que n

std::string bigO_10() {
    // Escribir el resultado del análisis
    string result = "O(n)";
    return result;
}

int ejercicio_11 (int n, int x) {
  if (n <= 1) return 1;    // ... C1
  else
    for (int i = 1; i <= n; ++i)    // ... n
      x = x + 1;                    // ... C2
  return ejercicio_11 (n-1, x);  // ... O(n)
}

// la recursividad solo depende de n
// C1 + n + C2 + O(n) = O(n)

std::string bigO_11() {
    // Escribir el resultado del análisis
    string result = "O(n)";
    return result;
}

int ejercicio_12 (vector<int> v) {
  auto n = size(v);   // ... C1
  
  // si el vector es atomico, retorna su elemento
  if (n == 0) return 0;               // ... C2
   if (n == 1) {                      // ... C3
    int value = v.back();             // ... C3
    v.pop_back();
    return value;           // ... C4
  }   

  vector<int> v1;
  vector<int> v2; 
  auto left = begin(v);   // ... primer elem C5
  auto middle = next(left, n/2);              // ...  elem medio log(n) por dividir de 2 en 2
  auto right = end(v);     // ... ultimo elem  C6
  
  copy(left, middle, back_inserter(v1));    // insertar la mitad hacia abajo de v a v1
  copy(middle, right, back_inserter(v2));   // insertar la mitad hacia arriba de v a v2
    
  return ejercicio_12 (v1) + ejercicio_12 (v2);                // ... log(n)
}

// C1 + C2 + C3 + C4 + log(n) + C5 + C6 + log(n)
// C + log(n) + log(n) = O(log(n))

std::string bigO_12() {
    // Escribir el resultado del análisis
    string result = "O(log(n))";
    return result;
}

std::string bigO_13() {
    // Escribir el resultado del análisis
    string result = "O(log(n))";
    return result;
}

void permute(string word, string subword, vector<string>& words /* , int& j */ ) {
    // j++;
    if(word.size() == 0) {                 // ... O(1)
        words.push_back(subword);
        // cout << "Obtenido: " << subword << endl;
        return ;  // detiene la ejecucion
    }
    // por cada iteracion se hara un subgrupo de caracteres que seran combinados
    for(int i=0; i<word.size(); i++) {     // ... O(n)
        char c = word[i];
        string left = word.substr(0,i);
        string right = word.substr(i+1);
        string rest = left + right;
        // cout << "Recur. " << j << setw(j*2) << c << ":" << endl;
        // cout << "        " << setw(j*2) << left << " " << right << endl << endl;
        permute(rest , subword + c, words);   // ... O(n!)
        // permute(rest , subword + c, words, j);
        // j--;
    }
}

// Implementacion de los ejercicios 14 y 15
vector<string> get_anagrams(string word, string filename) {
    fstream file(filename, ios::in);
    vector<string> words_anag, result;
    string ob = "", line;
    permute(word, ob, words_anag);     // ... O(n*n!)
    while(getline(file, line)) {           // ... O(m)
        for (auto& w: words_anag) {      // ... O(n)
            if (line == w) {
              result.push_back(w);      // ...  C1
              break;
            }
        }
    }  return result;

  // Complejidad algoritmica -> O(n*n!) + (O(m)*(O(n) + C1) = O(n*n!) + O(m*n) = O(n*n!)
  // (puede ser que el recorrido en el archivo sea menor que la permutacion de anagramas)
}

pair <double, double> get_par_lejano(const vector<double>& data) {
    // Para una mayor diferencia, los dos numeros deben ser los mas separados posibles,
    // uno el mas menor y el otro mas mayor.
    double mayor = 0.;
    for (auto& in: data) {    // ... O(n)
        if (mayor < in)  mayor = in;              // ... C1
    }
    double menor = 0.;
    for (auto& in: data) {    // ... O(n)
        if (menor > in)  menor = in;              // ... C2
    }
    return pair<double, double>{menor, mayor};

    // Complejidad algoritmica -> C1 O(n) + C2 O(n) = O(n)  Lineal
}