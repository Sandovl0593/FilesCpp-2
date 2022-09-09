#include <bits/stdc++.h>
using namespace std;

// un tipo T también puede ser una clase T
template <typename T> T maximo1(T x, T y) {
    return x>y?x:y; 
}

template<typename T> class coord {
    T x = T();
    T y = T();
public:
    coord() {}
    coord(T x_, T y_): x(x_), y(y_) {}

    // overload para imprimur una variable coord<T>
    friend ostream& operator<<(ostream& os, coord<T> coord) {
        os << coord.x << "," << coord.y;
        return os;
    }

    T get_x() { return x; }
    T get_y() { return y; }

    // overload para dos parametros coord<T> que retorna un bool evaluado por dos variables tipo T
    friend bool operator>(const coord<T> coord1, const coord<T> coord2) {
        auto sum1 = coord1.x*coord1.x + coord1.y*coord1.y;
        auto sum2 = coord2.x*coord2.x + coord2.y*coord2.y;
        return sum1>sum2; 
    }

    // maximo con parametros coord<int> y coord<double>
    coord<double> maximo_dist(coord<int> num1, coord<double> num2) {
        auto sum1 = num1.get_x()*num1.get_x() + num1.get_y()*num1.get_y();
        auto sum2 = num2.get_x()*num2.get_x() + num2.get_y()*num2.get_y();
        if (sum1 > sum2) {
            // se crea un tipo coord<double> con los parametros de num1 como doubles
            coord<double> result(double(num1.get_x()), double(num1.get_y()));
            return result;
        } return num2;  
    }

};


template <typename V, typename W>  auto maximo2(V x, W y) {
    return x>y?x:y;
}

template <typename V, typename W> class tuple {
    V x = V(); 
    W y = W();
public:
    tuple(){}
    tuple(V _x, W _y): x(_x), y(_y) {}

    friend bool operator>(const tuple<V> tuple1, const tuple<W> tuple2) {
        auto sum1 = tuple1.x*tuple1.x + tuple1.y*tuple1.y;
        auto sum2 = tuple2.x*tuple2.x + tuple2.y*tuple2.y;
        return sum1>sum2; 
    }

};

int main() {
    coord<int> men1(3, 4);
    coord<int> men2(7, 2);
    cout << men1 << " y " << men2 << endl;
    /* aqui recrea el template de maximo1() para dos variables coord<T> y retorna el maximo coord<T>
    (comparacion sobrecargada para variables coord<T> en especifico) */
    cout << maximo1(men1, men2) << endl;
}