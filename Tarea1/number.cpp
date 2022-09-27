#include "number.h"

number_t* number_t::operator= (number_t* aloj_) {
    number_t* aloj = new number_t(real);
    return aloj;
}