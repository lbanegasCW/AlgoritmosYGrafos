#include <vector>
#include <iostream>

using namespace std;

// Agrega una arista no dirigida entre dos vértices con su peso.
// Se inserta en ambos sentidos dentro de la lista de adyacencia.
void addArista(vector<pair<int, int>> aristas[], int verticeUno, int verticeDos, int peso)
{
    aristas[verticeUno].push_back(make_pair(verticeDos, peso));
    aristas[verticeDos].push_back(make_pair(verticeUno, peso));
}

// Convierte lista de adyacencia a matriz de adyacencia.
// matriz[i][j] = peso de la arista i-j, o 0 si no existe conexión directa.
vector<vector<int>> listaToMatriz(vector<pair<int, int>> aristas[])
{
    vector<vector<int>> matriz(V, vector<int>(V, 0));

    for (int i = 0; i < V; i++) {
        for (auto j = aristas[i].begin(); j != aristas[i].end(); j++) {
            matriz[i][j->first] = j->second;
        }
    }

    return matriz;
}

// Imprime el grafo como lista de adyacencia legible.
void showLista(vector<string> vertices, vector<pair<int, int>> aristas[])
{
    int v, w;
    for (int u = 0; u < V; u++) {
        cout << "Vertice " << vertices[u] << " forma una arista con: \n";
        for (auto it = aristas[u].begin(); it != aristas[u].end(); it++) {
            v = it->first;
            w = it->second;
            cout << "\tVertice " << vertices[v] << " con peso: " << w << "\n";
        }
        cout << "\n";
    }
}

// Imprime el grafo como matriz de adyacencia.
void showMatriz(vector<vector<int>> matriz, vector<string> vertices)
{
    for (int i = 0; i < V; i++) {
        cout << "   " << vertices[i] << "  ";
    }
    cout << endl;

    for (int i = 0; i < V; i++) {
        cout << vertices[i];
        for (int j = 0; j < V; j++) {
            printf("  %02d  ", matriz[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

// Busca el índice de un vértice por su nombre.
int indexarVertice(string vertice, vector<string> vertices)
{
    for (int i = 0; i < V; i++) {
        if (vertice.compare(vertices[i]) == 0) {
            return i;
        }
    }

    // Valor de respaldo en caso de no encontrar coincidencia.
    return -1;
}
