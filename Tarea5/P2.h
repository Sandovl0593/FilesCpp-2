#ifndef PROG3_PROGRAMACION_CONCURRENTE_V2022_1_P2_H
#define PROG3_PROGRAMACION_CONCURRENTE_V2022_1_P2_H
#include <thread>

template <typename T> void add(T& num, T val) { num += val; }

template<typename T, template <typename ...> class Container>
void increase_values(Container<T>& cnt, T value) {
    for (int i=0; i<cnt.size(); i++) {
        std::thread hilo(add<T>, std::ref(cnt[i]), value);
        hilo.join();
    }
}

#endif //PROG3_PROGRAMACION_CONCURRENTE_V2022_1_P2_H