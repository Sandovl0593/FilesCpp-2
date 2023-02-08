#ifndef PROG3_PROGRAMACION_CONCURRENTE_V2022_1_P3_H
#define PROG3_PROGRAMACION_CONCURRENTE_V2022_1_P3_H
#include <mutex>
#include <thread>
#include <iostream>
#include <vector>


template <typename T> 
void es_primo(bool& valid, T num) {
    std::mutex mtx;
    mtx.lock();
    for (int v=2; v<num; v++) {
        if (num % v == 0)  valid = false;
    }
    mtx.unlock();
}

template <typename T, template <typename ...> class Container>
void get_primes(Container<T>& cnt, T start, T stop) {
    for (auto i= start; i<stop; i++) { 
        bool primo = true;
        std::thread hilo(es_primo<T>, std::ref(primo), i);
        hilo.join();
        if (primo) cnt.push_back(i);
    }
}

#endif //PROG3_PROGRAMACION_CONCURRENTE_V2022_1_P3_H