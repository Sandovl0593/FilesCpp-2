#ifndef PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
#define PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
#include <iostream>
#include <vector>
#include <iomanip>
#include "number.h"

namespace utec {

    class matrix_t {
        int cols=0;
        int rows=0;
    public:
        std::vector<std::vector<number_t*>> matrixx;

        matrix_t() {}
        // inicia con la matriz ampliado
        matrix_t(int row, int col): cols(col), rows(row) {
            matrixx.resize(rows);
            for (int i= 0; i<rows; ++i) {
                matrixx[i].resize(cols);
            }
        }

        // operator para coincidir cada index de la matriz
        // matrix_t operator=(matrix_t arr);
        matrix_t operator=(matrix_t arr) {
            for (int i=0; i<rows; i++) {
                for (int j=0; j<cols; j++) {
                    arr.matrixx[i][j] = matrixx[i][j];
                }
            } return arr;
        }

        // getters de los sizes
        int row_size() { return rows; }
        int col_size() { return cols; }

        // operator() para asignar un elemento de la matriz
        number_t*& operator() (int ro, int col);

        // overload para imprimir la matriz
        friend std::ostream& operator<<(std::ostream& os, matrix_t matrix) {
            for (int i=0; i<matrix.rows; i++) {
                for (int j=0; j<matrix.cols; j++) {
                    os << std::setw(4) << matrix.matrixx[i][j];
                } os << std::endl;
            } return os;
        }

        ~matrix_t() {}
    };

    number_t*& matrix_t::operator() (int ro, int col) {
        return matrixx[ro][col];
    }
}


#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H