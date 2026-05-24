#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <vector>

using namespace std;

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

    //mexe com as arestas
    void inserirAresta(int u, int v, int peso = 1);
    void removerAresta(int u, int v);
<<<<<<< HEAD
    bool saoAdjacentes(int u, int v);
=======
    bool verificarAresta(int u, int v);    
    void alterarPesoAresta(int u, int v, double peso);

>>>>>>> 55d64ab479449b826a156b37a15f1334c4eaed8a

    // Calcula o grau de um vértice
    int grauVertice(int idVertice);
    // Retorna a lista de vizinhos
    vector<int> listarVizinhos(int idVertice);

    // Exibe o grafo no formato do CS Academy    
    void exibirGrafo();
};
#endif