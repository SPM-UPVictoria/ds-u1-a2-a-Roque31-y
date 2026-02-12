#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "carga.h"

const int FILAS = 10;
const int COLUMNAS = 10;

// Declaraciones
template<typename T>
void inicializarPlaca(T placa[FILAS][COLUMNAS]);
template<typename T>
void calcularCampoTotal(T placa[FILAS][COLUMNAS], const std::vector< Carga<T> > &cargas, T k);
template<typename T>
void mostrarPlaca(T placa[FILAS][COLUMNAS]);

int main(){
    // Usamos double como tipo numérico (puedes cambiarlo por float o int en instancias distintas)
    typedef double T;

    T placa[FILAS][COLUMNAS];

    // Definir algunas cargas puntuales (posición x,y y magnitud q)
    std::vector< Carga<T> > cargas;
    cargas.emplace_back(2, 3, 5.0);   // carga positiva
    cargas.emplace_back(7, 7, -3.0);  // carga negativa
    cargas.emplace_back(0, 0, 2.5);   // carga en esquina

    const T k = 9.0; // constante simplificada

    inicializarPlaca<T>(placa);
    calcularCampoTotal<T>(placa, cargas, k);

    std::cout << "Simulacion: placa " << FILAS << "x" << COLUMNAS << " con cargas puntuales\n";
    std::cout << "Cargas definidas (x, y, q):" << std::endl;
    for (size_t i = 0; i < cargas.size(); i++){
        std::cout << "  (" << cargas[i].x << ", " << cargas[i].y << ") -> " << cargas[i].q << std::endl;
    }

    std::cout << std::endl;
    mostrarPlaca<T>(placa);

    return 0;
}

template<typename T>
void inicializarPlaca(T placa[FILAS][COLUMNAS]){
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            placa[i][j] = static_cast<T>(0);
        }
    }
}

template<typename T>
void calcularCampoTotal(T placa[FILAS][COLUMNAS], const std::vector< Carga<T> > &cargas, T k){
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            T suma = static_cast<T>(0);
            for(const auto &c : cargas){
                T dx = static_cast<T>(i - c.x);
                T dy = static_cast<T>(j - c.y);
                T d = std::sqrt(dx*dx + dy*dy);
                suma += calcularCampo<T>(k, c.q, d);
            }
            placa[i][j] = suma;
        }
    }
}

template<typename T>
void mostrarPlaca(T placa[FILAS][COLUMNAS]){
    std::cout << std::fixed << std::setprecision(3);
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            std::cout << std::setw(8) << placa[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
