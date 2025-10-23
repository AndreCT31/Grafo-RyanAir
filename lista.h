#ifndef LISTA_H
#define LISTA_H
#include "arista.h"
#include <iostream>

class Lista {
    public:
        Arista* inicio;

        Lista();
        void insertar(int destino, int peso);
        void eliminar(int destino);
        void imprimir() const;
};
#endif // LISTA_H