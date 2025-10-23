#ifndef VERTICE_H
#define VERTICE_H
#include <string>
using namespace std;

struct Vertice {
    int id;
    std::string tag;

    Vertice(int _id, std::string _tag = "" ) : id(_id), tag(_tag) {}
};

#endif // VERTICE_H


