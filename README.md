[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/g8Mz_c97)
# Estructura de Datos - Unidad 1 - Actividad 2

## Simulación de Campo Eléctrico en una Placa con Cargas Puntuales

### Descripción del problema

Una placa metálica rectangular puede representarse mediante una **matriz bidimensional** donde cada celda almacena un valor numérico que representa la magnitud del **campo eléctrico** en ese punto.

Se sabe que la placa tiene algunas **cargas puntuales** ubicadas en posiciones específicas. Cada una de estas cargas genera un campo eléctrico proporcional a:

$$
E = \frac{k \cdot q}{d^2}
$$

donde:

* ( k ) es una constante (usar **k = 9.0** para simplificar),
* ( q ) es la carga (positivo o negativo),
* ( d ) es la distancia entre la carga y el punto donde se calcula el campo.

Se deberá construir un programa que:

1. Represente la placa como un arreglo estático 2D.
2. Modele cada **carga** mediante una **clase**.
3. Use **plantillas (templates)** para permitir calcular el campo usando distintos tipos numéricos (e.g., `int`, `float`, `double`).
4. Calcule el campo eléctrico generado por **todas las cargas** en cada celda de la placa.
5. Muestre finalmente la **matriz resultante** con los valores del campo.

La matriz se mostraŕa en consola.

---


### Requerimientos específicos del programa

1. Crear una clase `Carga` que contenga:
   * posición en X y Y
   * valor de la carga `q`
   * constructor y métodos necesarios
2. Crear una función **template** que calcule el campo eléctrico dado `k`, `q` y `d`.
3. Representar la placa como una **matriz estática** de tamaño 10x10.
4. Calcular la distancia entre una celda y cada carga usando distancia euclidiana.
5. Llenar toda la matriz con el **campo total** (suma de aportes de todas las cargas).
6. Imprimir la matriz final en formato tabular.

---

### Entregables

1. **Archivo de código fuente (.cpp, .h, y CMAKE)** con:

   * Implementación de la clase `Carga`.
   * Función template.
   * Matriz estática.
   * Cálculo y despliegue del campo eléctrico.
   * Proyecto configurado con CMAKE

2. **Reporte en PDF** con:

   * Explicación del diseño (POO, arreglos, plantillas).
   * Capturas de la salida del programa.
   * **El reporte se subirá a la plataforma google classroom**