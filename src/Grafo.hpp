#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

class Grafo{
    private:
        
        vector<int> vertices;
        vector<vector<double>> matriz;

        bool orientado;
        bool ponderado;

    public:
    //construtor
    Grafo(bool ehOrientado, bool ehPonderado);

    //mexe com os vertices
    void inserirVertice(int v);
    void removerVertice(int v);
    //funcao aux do remover vertice
    int getIndiceVertice(int v);

    //mexe com as as arestas
    void inserirAresta(int u, int v, double peso = 1.0);
    void removerAresta(int u, int v);
    bool verificarAresta(int u, int v);
    void alterarPesoAresta(int u, int v, double peso);
    bool saoAdjacentes(int u, int v);

    // Calcula o grau de um vértice
    int grauVertice(int idVertice);
    // Retorna a lista de vizinhos
    vector<int> listarVizinhos(int idVertice);

    // Exibe o grafo no formato do CS Academy
    void exibirGrafo();

    int prim(int verticeInicial, int agmU[], int agmV[], double agmPeso[]);
    void exibirPrim(int verticeInicial = -1);
};
#endif