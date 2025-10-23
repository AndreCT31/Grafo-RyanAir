#include "grafo.h"
#include <iostream>
using namespace std;

int main() {
    // Grafo g;

    // g.agregarVertice("A");
    // g.agregarVertice("B");
    // g.agregarVertice("C");
    // g.agregarVertice("D");
    // g.agregarVertice("E");

    // g.agregarArista(0, 1, 6);  // A - B
    // g.agregarArista(0, 2, 9);  // A - C
    // g.agregarArista(1, 2, 3);  // B - C
    // g.agregarArista(1, 3, 7);  // B - D
    // g.agregarArista(2, 3, 7);  // C - D
    // g.agregarArista(2, 4, 5);  // C - E
    // g.agregarArista(3, 4, 5);  // D - E

    // cout << "\nLISTAS DE ADYACENCIA:\n";
    // g.imprimirListas();

    // cout << "\nMATRIZ DE ADYACENCIA:\n";
    // g.imprimirMatriz();

    // cout << "\nGRADO DE SALIDA DEL NODO B: " << g.gradoSalida(1) << endl;
    // g.adyacenciaSalida(1);

    // g.guardar("output.txt");

    Grafo nuevo;
    nuevo.cargar("grafo.txt");
    cout << "\nGRAFO CARGADO DESDE ARCHIVO:\n";
    nuevo.imprimirListas();  
    //cout << "\n MATRIZ CARGADA DESDE ARCHIVO:\n";
    //nuevo.guardar1("output_cargado.txt");
    //nuevo.imprimirMatriz();
}
