#ifndef PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_NUMBER_H
#define PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_NUMBER_H
#include <iostream>

class number_t {
protected:
    float real=0; 
public:
    number_t() {}
    number_t(float num): real(num) {}

    // overload para imprimir el numero
    friend std::ostream& operator<<(std::ostream& os, number_t* number) {
        os << number->real;   return os;
    };

    // operator para crear un objeto dinamico copia del numero
    number_t* operator= (number_t* aloj_);

    ~number_t() {}
};

class integer_t: public number_t {
public:
    integer_t(int num): number_t(num) {}
    ~integer_t() {}
};

class real_t: public number_t {
public:
    real_t(float num): number_t(num) {}
    ~real_t() {}
};

number_t* number_t::operator= (number_t* aloj_) {
    number_t* aloj = new number_t(real);
    return aloj;
}

#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_NUMBER_H