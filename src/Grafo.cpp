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
    int indiceU = getIndiceVertice(u);
    int indiceV = getIndiceVertice(v);

    //trata vertices invalidos
    if(indiceU == -1 || indiceV == -1){
        return;
    }

    //se o grafo nao for ponderado
    if(!ponderado){
        peso = 1;
    }

    //adiciona aresta
    matriz[indiceU][indiceV] = peso;

    //se não for orientado
    if(!orientado){
        matriz[indiceV][indiceU] = peso;
    }
}

void Grafo::removerAresta(int u, int v){
    int indiceU = getIndiceVertice(u);
    int indiceV = getIndiceVertice(v);

    //trata vertices invalidos
    if(indiceU == -1 || indiceV == -1){
        return;
    }

    //remove aresta
    matriz[indiceU][indiceV] = 0;

    //se o grafo nao for orientado
    if(!orientado){
        matriz[indiceV][indiceU] = 0;
    }
}

int Grafo::grauVertice(int v){
    int indice = getIndiceVertice(v);

    //trata vertice inexistente
    if(indice == -1){
        return 0;
    }

    int grau = 0;

    //conta arestas na linha do vertice
    for(int j = 0; j < matriz.size(); j++){
        if(matriz[indice][j] != 0){
            grau++;
        }
    }

    return grau;
}

vector<int> Grafo::listarVizinhos(int v){
    vector<int> vizinhos;
    int indice = getIndiceVertice(v);

    //trata vertice inexistente
    if(indice == -1){
        return vizinhos;
    }

    //busca vizinhos na linha da matriz
    for(int j = 0; j < matriz.size(); j++){
        if(matriz[indice][j] != 0){
            //adiciona o ID real do vertice vizinho
            vizinhos.push_back(vertices[j]);
        }
    }

    return vizinhos;
}

bool Grafo::verificarAresta(int u, int v) {
    int indiceU = getIndiceVertice(u);
    int indiceV = getIndiceVertice(v);

    if (indiceU == -1 || indiceV == -1) {
        return false;
    }

    return matriz[indiceU][indiceV] != 0;
}

void Grafo::alterarPesoAresta(int u, int v, double peso) {
    inserirAresta(u, v, peso);
}

void Grafo::exibirGrafo() {
    cout << vertices.size() << endl;
    for (int i = 0; i < matriz.size(); i++) {
        int start = orientado ? 0 : i;
        for (int j = start; j < matriz[i].size(); j++) {
            if (matriz[i][j] != 0) {
                cout << vertices[i] << " " << vertices[j] << " " << matriz[i][j] << endl;
            }
        }
    }
}