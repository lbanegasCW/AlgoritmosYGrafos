#include <vector>
#include <iostream>

using namespace std;

// Valor utilizado para representar "no hay camino directo".
#define INF 99999

// Matriz de trabajo global para el algoritmo.
int matrizFloydWarshall[V][V];

// Adapta una matriz de adyacencia clásica:
// - Diagonal principal queda con 0.
// - Ausencia de arista (valor 0 fuera de diagonal) pasa a INF.
void transformMatriz(vector<vector<int>> matriz)
{
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j && matriz[i][j] == 0) {
                matrizFloydWarshall[i][j] = INF;
            } else {
                matrizFloydWarshall[i][j] = matriz[i][j];
            }
        }
    }
}

// Imprime matriz de distancias mínimas entre pares de vértices.
void showMatrizFW(int matriz[V][V], vector<string> vertices)
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

// Floyd-Warshall:
// Usa programación dinámica para permitir progresivamente vértices intermedios.
// Si pasar por k mejora la distancia i->j, reemplaza el valor anterior.
void floydWarshall(vector<vector<int>> matrizOrigen, vector<string> vertices)
{
    transformMatriz(matrizOrigen);

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (matrizFloydWarshall[i][k] != INF
                    && matrizFloydWarshall[k][j] != INF
                    && matrizFloydWarshall[i][j] > matrizFloydWarshall[i][k] + matrizFloydWarshall[k][j]) {
                    matrizFloydWarshall[i][j] = matrizFloydWarshall[i][k] + matrizFloydWarshall[k][j];
                }
            }
        }
    }

    showMatrizFW(matrizFloydWarshall, vertices);
}
