#include "Grafo.h"

//construtor
Grafo::Grafo(int n, bool orientado_grafo, bool ponderado_grafo){
    numVertices = n;
    orientado = orientado_grafo;
    ponderado = ponderado_grafo;

    matriz.resize(n, vector<int>(n, 0));
}

//insere vertice
void Grafo::inserirVertice(){
    numVertices++;

    //add coluna
    for(int i = 0; i < matriz.size(); i++){
        matriz[i].push_back(0);
    }

    //add linha
    matriz.push_back(vector<int>(numVertices, 0));
}