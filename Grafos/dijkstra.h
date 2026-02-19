#include <vector>
#include <iostream>
#include <climits>

using namespace std;

// Devuelve el índice del vértice no procesado con menor distancia acumulada.
// Es la operación "extract-min" en la versión simple de Dijkstra (O(V)).
int distanciaMinima(int distancias[], bool verticeMarcado[])
{
    int min = INT_MAX;
    int min_index = 0;

    for (int v = 0; v < V; v++) {
        if (!verticeMarcado[v] && distancias[v] <= min) {
            min = distancias[v];
            min_index = v;
        }
    }

    return min_index;
}

// Muestra la distancia mínima desde el origen hacia cada vértice del grafo.
void mostrarCaminos(int distancias[], vector<string> vertices)
{
    cout << "Vertice  |  Distancia desde el origen" << endl;
    for (int i = 0; i < V; i++) {
        cout << vertices[i] << " \t\t" << distancias[i] << endl;
    }
}

// Algoritmo de Dijkstra (pesos no negativos):
// 1) Inicializa todas las distancias en infinito, salvo el origen en 0.
// 2) Repite V-1 veces: toma el vértice no procesado con menor distancia.
// 3) Relaja todas sus aristas salientes.
// 4) Al final, distancias[] contiene el costo mínimo desde el origen.
void dijkstra(vector<vector<int>> matriz, int origen, vector<string> vertices)
{
    int distancias[V];
    bool verticeMarcado[V];

    for (int i = 0; i < V; i++) {
        distancias[i] = INT_MAX;
        verticeMarcado[i] = false;
    }

    distancias[origen] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = distanciaMinima(distancias, verticeMarcado);
        verticeMarcado[u] = true;

        for (int v = 0; v < V; v++) {
            // Relajación: si u->v existe y el camino pasando por u mejora,
            // se actualiza la mejor distancia conocida para v.
            if (!verticeMarcado[v] && matriz[u][v] && distancias[u] != INT_MAX
                && distancias[u] + matriz[u][v] < distancias[v]) {
                distancias[v] = distancias[u] + matriz[u][v];
            }
        }
    }

    mostrarCaminos(distancias, vertices);
}
