#include "matriz.h"

using namespace std;

void Matriz::inicializar(int n){
    matriz = vector<vector<int>>(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i)
        matriz[i][i] = 0; //diagonal cero
}

void Matriz::insertar(int origen, int destino, int peso){
    matriz[origen][destino] = peso;
}

void Matriz::eliminar(int origen, int destino){
    matriz[origen][destino] = INF;
}
int Matriz::obtener(int origen, int destino) const {
    return matriz[origen][destino];
}

void Matriz::imprimir(const vector<Vertice>& vertices) const {
    cout << "    ";
    for (const auto& v : vertices) {
        cout << v.tag << "(" << v.id << ")  ";
    }
    cout << "\n";

    for (int i = 0; i < vertices.size(); ++i) {
        cout << vertices[i].tag << "(" << vertices[i].id << ")";
        if (vertices[i].tag.size() < 6) cout << "  ";
        else cout << " ";
        for (int j = 0; j < vertices.size(); ++j) {
            if (matriz[i][j] == INF)
                cout << "I    ";
            else
                cout << matriz[i][j] << "    ";
        }
        cout << "\n";
    }
}