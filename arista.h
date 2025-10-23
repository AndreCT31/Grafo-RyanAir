#ifndef ARISTA_H
#define ARISTA_H

struct Arista {
    int destino;
    int peso;
    Arista* sig;

    Arista(int dest, int p);

};

#endif // ARISTA