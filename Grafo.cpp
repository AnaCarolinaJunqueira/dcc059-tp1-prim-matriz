#include "Grafo.h"

//construtor
Grafo::Grafo(int n, bool orientado_grafo, bool ponderado_grafo){
    numVertices = n;
    orientado = orientado_grafo;
    ponderado = ponderado_grafo;

    matriz.resize(n, vector<int>(n, 0));
}