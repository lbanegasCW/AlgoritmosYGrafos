#include <vector>
#include <iostream>
#include <list>

using namespace std;

// Vector global de marcas para no visitar un vértice más de una vez.
bool verticesVisitados[V];

// Reinicia el estado de visitados antes de cada recorrido.
void clearVisitados()
{
    for (int i = 0; i < V; i++) {
        verticesVisitados[i] = false;
    }
}

// DFS recursivo:
// - Marca el vértice actual.
// - Procesa recursivamente cada adyacente no visitado.
void recursiveDFS(int origen, vector<pair<int, int>> aristas[], vector<string> vertices)
{
    verticesVisitados[origen] = true;
    cout << vertices[origen] << " ";

    for (auto i = aristas[origen].begin(); i != aristas[origen].end(); i++) {
        if (!verticesVisitados[i->first]) {
            cout << "-> ";
            recursiveDFS(i->first, aristas, vertices);
        }
    }
}

// Envoltura de DFS para limpiar estado antes de iniciar.
void DFS(int origen, vector<pair<int, int>> aristas[], vector<string> vertices)
{
    clearVisitados();
    recursiveDFS(origen, aristas, vertices);
}

// BFS iterativo:
// - Usa una cola.
// - Visita primero vecinos cercanos (por niveles).
void BFS(int origen, vector<pair<int, int>> aristas[], vector<string> vertices)
{
    clearVisitados();

    list<int> colaVertices;

    int verticeActual = origen;
    verticesVisitados[verticeActual] = true;
    colaVertices.push_back(verticeActual);

    while (!colaVertices.empty()) {
        verticeActual = colaVertices.front();
        cout << " -> " << vertices[verticeActual];
        colaVertices.pop_front();

        for (auto i = aristas[verticeActual].begin(); i != aristas[verticeActual].end(); i++) {
            if (!verticesVisitados[i->first]) {
                verticesVisitados[i->first] = true;
                colaVertices.push_back(i->first);
            }
        }
    }
}
