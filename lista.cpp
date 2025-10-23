#include "lista.h"

Lista::Lista() {
    inicio = nullptr;
}




void Lista::insertar(int destino, int peso) {
    Arista* nuevo = new Arista(destino, peso);
    nuevo->sig = inicio;
    inicio = nuevo;
}

void Lista::eliminar(int destino) {
    Arista* actual = inicio;
    Arista* anterior = nullptr;

    while (actual && actual->destino != destino) {
        anterior = actual;
        actual = actual->sig;
    }

    if (actual) {
        if (anterior) anterior->sig = actual->sig;
        else inicio = actual->sig;
        delete actual;
    }
}

void Lista::imprimir() const {
    Arista* actual = inicio;
    while (actual) {
        std::cout << " -> " << actual->destino << " (" << actual->peso << ")";
        actual = actual->sig;
    }
}