#ifndef MATRIZ_H
#define MATRIZ_H
#include "vertice.h"
#include <vector>
#include <iostream>

const int INF = 99999;


using namespace std;

class Matriz {
    public:
        vector<vector<int>> matriz;

        int obtener(int origen, int destino) const;

        void inicializar(int n);
        void insertar(int origen, int destino, int peso);
        void eliminar(int origen, int destino);
        void imprimir(const std::vector<Vertice>& vertices) const;
    
    };

#endif // MATRIZ_H