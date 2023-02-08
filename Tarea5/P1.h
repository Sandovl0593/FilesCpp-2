#ifndef PROG3_PROGRAMACION_CONCURRENTE_V2022_1_P1_H
#define PROG3_PROGRAMACION_CONCURRENTE_V2022_1_P1_H
#include <thread>

template<typename T> void s(T& num, T org) { num += org; }

template <typename T, template <typename...> class Container>
T sumar(Container<T>& cnt) {
    T suma = 0.;
    for (auto it: cnt) {
        std::thread hilo(s<T>, std::ref(suma), it); 
        hilo.join();
    }   return suma;
}

#endif //PROG3_PROGRAMACION_CONCURRENTE_V2022_1_P1_H