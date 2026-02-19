#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Búsqueda exhaustiva de ciclo mínimo del viajante (TSP) para tamaño pequeño.
// Idea:
// 1) Fijar un origen.
// 2) Permutar el orden de visita de los demás vértices.
// 3) Calcular el costo total de cada ruta cerrada.
// 4) Conservar el menor costo observado.
void caminoDelViajero(int origen, vector<vector<int>> matriz)
{
    vector<int> vertices;
    for (int i = 0; i < V; i++) {
        if (i != origen) {
            vertices.push_back(i);
        }
    }

    int pesoMinimo = INT_MAX;

    do {
        int pesoActual = 0;
        int k = origen;

        // Recorre la permutación actual y acumula los pesos de cada salto.
        for (int i = 0; i < vertices.size(); i++) {
            pesoActual += matriz[k][vertices[i]];
            k = vertices[i];
        }

        // Cierra el ciclo regresando al origen.
        pesoActual += matriz[k][origen];

        // Guarda el mejor resultado.
        pesoMinimo = min(pesoMinimo, pesoActual);

    } while (next_permutation(vertices.begin(), vertices.end()));

    cout << "El recorrido minimo es de: " << pesoMinimo;
}
