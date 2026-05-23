#include "Grafo.hpp"
using namespace std;

//construtor
Grafo::Grafo(bool ehOrientado, bool ehPonderado){
    orientado = ehOrientado;
    ponderado = ehPonderado;

}

//mexe com os vertices
void Grafo::inserirVertice(int v){
    
    //add vertice
    vertices.push_back(v);

    int novoTamanho = vertices.size();

    //add coluna
    for(int i = 0; i < matriz.size(); i++){
        matriz[i].push_back(0);
    }

    //add linha
    matriz.push_back(vector<double>(novoTamanho, 0));

}