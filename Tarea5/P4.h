#ifndef PROG3_PROGRAMACION_CONCURRENTE_V2022_1_P4_H
#define PROG3_PROGRAMACION_CONCURRENTE_V2022_1_P4_H
#include <vector>
#include <thread>
#include <mutex>

template <typename T> void trans(std::vector<T> arr, int i) { 
    std::swap(arr[i], arr[i-1]);
}

template <typename T> void pree(std::vector<T> arr, int i) { 
    std::swap(arr[i], arr[i+1]);
}

template < typename T>
class linked_list_t {
  public:
    std::vector<T> arr;
    // int siz = 0;
    void push_front(const T& value) {
        arr.push_back(value);
        // std::vector<std::thread> hilos;
        for (int i=arr.size()-1; i>0; i--) 
            // hilos.push_back(std::thread(trans<T>, std::ref(arr), i));
            // int val = arr[i]
            std::swap(arr[i], arr[i-1]);
            // trans<T>(arr, i);
        // for (int i=0; i<hilos.size(); i++)    hilos[i].join();
        // siz++;
    }

    void pop_front() {
        // std::mutex mtx;
        // std::vector<std::thread> hilos;
        for (int i=0; i<arr.size()-1; i++) 
            // hilos.push_back(std::thread(pree<T>, std::ref(arr), i));
            // pree<T>(arr, i);
            std::swap(arr[i], arr[i+1]);
        // mtx.lock();
        // for (int i=0; i<hilos.size(); i++)    hilos[i].join();
        // mtx.unlock();
        arr.pop_back();
        // siz--; 
    }

    bool empty() { return !(arr.size() > 0); }
    int size() { return arr.size(); }
    auto begin() { return arr.begin(); }
    auto end() { return arr.end(); }
};

#endif //PROG3_PROGRAMACION_CONCURRENTE_V2022_1_P4_H