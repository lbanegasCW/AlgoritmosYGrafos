# Proyecto de Grafos en C++

Aplicación de consola para crear un grafo no dirigido y ejecutar algoritmos clásicos de teoría de grafos.

## Funcionalidades

El programa permite:

1. Ingresar vértices (cantidad fija: `V = 5`).
2. Ingresar aristas con peso.
3. Mostrar el grafo como **lista de adyacencia**.
4. Mostrar el grafo como **matriz de adyacencia**.
5. Calcular caminos mínimos desde un origen con **Dijkstra**.
6. Calcular caminos mínimos entre todos los pares con **Floyd-Warshall**.
7. Recorrer el grafo en profundidad con **DFS**.
8. Recorrer el grafo en anchura con **BFS**.
9. Calcular un ciclo mínimo tipo **viajante (TSP por fuerza bruta)**.

## Requisitos

- Compilador C++ con soporte de C++11 o superior.
- Windows (si se usa Visual Studio) o Linux/macOS (si se compila con `g++`).

## Cómo compilar y ejecutar

### Opción 1: Visual Studio

1. Abrir `Grafos.sln`.
2. Seleccionar configuración `Debug` o `Release`.
3. Ejecutar con `Ctrl + F5`.

### Opción 2: g++ (Linux/macOS o Windows con MinGW)

Desde la raíz del repositorio:

```bash
g++ -std=c++11 -o grafos Grafos/Grafos.cpp
./grafos
```

> Nota: el programa usa `system("cls")` para limpiar pantalla, comando propio de Windows.
> En Linux/macOS no limpia la consola, pero la lógica del programa funciona igual.

## Uso básico

1. Primero cargar los 5 vértices.
2. Luego cargar las aristas con sus pesos.
3. Ejecutar cualquiera de las opciones del menú.

## Estructura del código

- `Grafos/Grafos.cpp`: menú principal e integración de algoritmos.
- `Grafos/grafo.h`: estructura base del grafo y conversiones.
- `Grafos/dijkstra.h`: caminos mínimos desde un origen.
- `Grafos/floydWarshall.h`: caminos mínimos para todos los pares.
- `Grafos/recorridos.h`: recorridos DFS y BFS.
- `Grafos/hamilton.h`: búsqueda exhaustiva de ciclo mínimo del viajante.

## Screenshot
![img.png](img.png)