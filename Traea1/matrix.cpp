#include <iostream>
#include "matrix.h"
using namespace utec;

// matrix_t matrix_t::operator=(matrix_t arr) {
//     for (int i=0; i<rows; i++) {
//         for (int j=0; j<cols; j++) {
//             arr.matrixx[i][j] = matrixx[i][j];
//         }
//     } return arr;
// }

number_t*& matrix_t::operator() (int ro, int col) {
    return matrixx[ro][col];
}