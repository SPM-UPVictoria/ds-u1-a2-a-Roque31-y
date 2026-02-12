#ifndef CARGA_H
#define CARGA_H

#include <cmath>

template<typename T>
class Carga {
public:
    int x;
    int y;
    T q;

    Carga(int x_, int y_, T q_) : x(x_), y(y_), q(q_) {}
};

// Funcion template que calcula el campo E = k * q / d^2
template<typename T>
T calcularCampo(T k, T q, T d){
    const T EPS = static_cast<T>(1e-9);
    if (d < EPS) { // evitar division por cero: si la carga está en la celda, se puede considerar aporte cero o saltarlo
        return static_cast<T>(0);
    }
    return (k * q) / (d * d);
}

#endif // CARGA_H
