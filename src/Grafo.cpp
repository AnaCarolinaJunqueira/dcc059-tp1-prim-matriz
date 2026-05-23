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

//funcao aux do remover vertice
int Grafo::getIndiceVertice(int v){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i] == v){
            return i;
        }
    }

    return -1;
}

void Grafo::removerVertice(int v){
    int indice = getIndiceVertice(v);

    //tratar se o vertice eh inexistente
    if(indice == -1){
        return;
    }

    //remove o vertice
    vertices.erase(vertices.begin() + indice);

    //remove a linha
    matriz.erase(matriz.begin() + indice);

    //remove a coluna
    for(int i = 0; i < matriz.size(); i++){
        matriz[i].erase(matriz[i].begin() + indice);
    }
}

//mexe com as arestas
void Grafo::inserirAresta(int u, int v, int peso){

}