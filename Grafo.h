#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>

using namespace std;

class Grafo{
    private:
        vector<vector<int>> matriz;
        
        int numVertices;
        bool orientado;
        bool ponderado;

    public:
    //construtor
    Grafo(int vertices, bool orientado, bool ponderado);

    //destrutor
    ~Grafo();
};
#endif