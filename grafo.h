#ifndef GRAFO_H
#define GRAFO_H

#include "vertice.h"
#include "lista.h"
#include "matriz.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Grafo {
    private:
    vector<Vertice> vertices;
    vector<Lista> listas;
    Matriz matrizAdy;

    public:
    Grafo();
    void agregarVertice(string tag);
    void agregarArista(int origen, int destino, int peso);
    void eliminarArista(int origen, int destino);
    void eliminarVertice(int id);
    void imprimirListas() const;
    void imprimirMatriz() const;
    void guardar(string nombreArchivo);
    void cargar(string nombreArchivo);
    void guardar1(string nombreArchivo);
    int gradoSalida(int id);
    void adyacenciaSalida(int id);
};

#endif // GRAFO_H