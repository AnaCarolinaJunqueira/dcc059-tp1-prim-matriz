#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <vector>

using namespace std;

class Grafo{
    private:
        
        vector<int> vertices;
        vector<vector<double>> matriz;

        bool existeVertice(int v);

        bool orientado;
        bool ponderado;

    public:
    //construtor
    Grafo(bool ehOrientado, bool ehPonderado);
};
#endif