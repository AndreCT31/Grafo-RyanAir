
#include "grafo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Grafo::Grafo() {}

void Grafo::agregarVertice(string tag){
    int id = vertices.size();
    vertices.push_back(Vertice(id, tag));
    listas.push_back(Lista());
    matrizAdy.inicializar(vertices.size());
    // regenerar conexiones existentes en la matriz
    for (int i = 0; i < listas.size(); ++i){
        Arista* actual = listas[i].inicio;
        while (actual){
            matrizAdy.insertar(i, actual->destino, actual->peso);
            actual = actual->sig;
        }
    }
}

void Grafo::agregarArista(int origen, int destino, int peso){
    if (origen < vertices.size() && destino < vertices.size()){
        listas[origen].insertar(destino, peso);
        matrizAdy.insertar(origen, destino, peso);
    }
}


void Grafo::eliminarVertice(int id) {
    if (id >= vertices.size()) return;

    // Borra todas las aristas que apuntan al ndo
    for (int i = 0; i < listas.size(); i++) {
        listas[i].eliminar(id);
    }

    //Elimina el vertice y su lista 
    listas.erase(listas.begin() + id);
    vertices.erase(vertices.begin() + id);

    //Ordena de nuevo las arsitas con destino mayor al id eliminado
    for (auto& lista : listas) {
        Arista* actual = lista.inicio;
        while (actual) {
            if (actual->destino > id) {
                actual->destino--;
            }
            actual = actual->sig;
        }
    }

    //  Aqui se regenera la matriz de new
    matrizAdy.inicializar(vertices.size());
    for (int i = 0; i < listas.size(); ++i) {
        Arista* actual = listas[i].inicio;
        while (actual) {
            matrizAdy.insertar(i, actual->destino, actual->peso);
            actual = actual->sig;
        }
    }
}

void Grafo::imprimirMatriz() const{
    matrizAdy.imprimir(vertices);
}

void Grafo::imprimirListas() const{
    for (int i = 0; i < listas.size(); ++i){
        cout << "Vertice " << i << " (" << vertices[i].tag << "):";
        listas[i].imprimir();
        cout << endl;
    }
}

void Grafo::guardar(string archivo){
    ofstream out(archivo);

    // Guardado de vértices
    for (const auto& vertice : vertices)
        out << vertice.id << " " << vertice.tag << endl;

    out << "#\n";

    // Guardado de aristas
    for (int i = 0; i < listas.size(); i++){
        Arista* actual = listas[i].inicio;
        while (actual){
            out << i << " " << actual->destino << " " << actual->peso << endl;
            actual = actual->sig;
        }
    }

    //MATRIZ DE ADYACENCIA 
    out << "\n# MATRIZ DE ADYACENCIA (visual)\n    ";
    for (const auto& v : vertices)
        out << v.tag << "(" << v.id << ")  ";
    out << "\n";

    for (int i = 0; i < vertices.size(); ++i) {
        out << vertices[i].tag << "(" << vertices[i].id << ")  ";
        for (int j = 0; j < vertices.size(); ++j) {
            int peso = matrizAdy.obtener(i, j);
            if (peso == INF)
                out << "I    ";
            else
                out << peso << "    ";
        }
        out << "\n";
    }

    out.close();
}


void Grafo::guardar1(string archivo){
    ofstream out(archivo);

    // Guardado de vértices
    for (const auto& vertice : vertices)
        out << vertice.id << " " << vertice.tag << endl;

    out << "#\n";

    // Guardado de aristas
    for (int i = 0; i < listas.size(); i++){
        Arista* actual = listas[i].inicio;
        while (actual){
            out << i << " " << actual->destino << " " << actual->peso << endl;
            actual = actual->sig;
        }
    }

  
    out.close();
}

void Grafo::cargar(string archivo){
    ifstream in(archivo);
    string linea;
    vertices.clear();
    listas.clear();

    // simbolo # como identificador de linea para la hora de cargar desde una rchivo
    while (getline(in, linea) && linea != "#"){
        int id;
        string nombre;
        istringstream iss(linea);
        iss >> id >> nombre;
        vertices.push_back(Vertice(id, nombre));
        listas.push_back(Lista());
    }


    matrizAdy.inicializar(vertices.size());

    // Aqui se cargan las arsitas
    while (getline(in, linea)){
        int o, d , p;
        istringstream iss(linea);
        iss >> o >> d >> p;
        agregarArista(o, d, p);
    }
    in.close();
}

int Grafo::gradoSalida(int id){
    int cont = 0;
    Arista* actual = listas[id].inicio;
    while (actual){
        cont++;
        actual = actual->sig;
    }
    return cont;
}

void Grafo::adyacenciaSalida(int id) {
    cout << "Adyacencia de " << vertices[id].tag << ": ";
    listas[id].imprimir();
    cout << endl;
}