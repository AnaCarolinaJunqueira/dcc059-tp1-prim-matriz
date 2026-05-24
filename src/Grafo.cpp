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
void Grafo::inserirAresta(int u, int v, double peso){
    int indiceU = getIndiceVertice(u);
    int indiceV = getIndiceVertice(v);

    //trata vertices invalidos
    if(indiceU == -1 || indiceV == -1){
        return;
    }

    //se o grafo nao for ponderado
    if(!ponderado){
        peso = 1.0;
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

bool Grafo::saoAdjacentes(int u, int v){
    return verificarAresta(u, v);
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

int Grafo::prim(int verticeInicial, int agmU[], int agmV[], double agmPeso[]){
    int n = matriz.size();

    if(n == 0 || n>MAX){
        return 0;
    }

    int s=0;
    if(verticeInicial != -1){
        int ind = getIndiceVertice(verticeInicial);
        if(ind != -1){
            s = ind;
        }
    }

    double chave[MAX];
    int pai[MAX];
    int naArvore[MAX];

    for(int i = 0; i < n; i++){
        chave[i] = 1e18;
        pai[i] = -1;
        naArvore[i] = 0;
    }

    chave[s] = 0;

    for(int count = 0; count < n; count++){
        int u = -1;

        for(int i = 0; i < n; i++){
            if(naArvore[i] == 0 && (u == -1 || chave[i] < chave[u])){
                u = i;
            }
        }

        if(u == -1){
            break;
        }

        naArvore[u] = 1;

        for(int v = 0; v < n; v++){
            if(naArvore[v] == 0 && matriz[u][v] != 0 && matriz[u][v] < chave[v]){
                chave[v] = matriz[u][v];
                pai[v] = u;
            }
        }
    }

    int tam = 0;
    for(int i = 0; i < n; i++){
        if(pai[i] != -1){
            agmU[tam] = vertices[pai[i]];
            agmV[tam] = vertices[i];
            agmPeso[tam] = matriz[pai[i]][i];
            tam++;
        }
    }

    return tam;
}

void Grafo::exibirPrim(int verticeInicial){
    int agmU[MAX];
    int agmV[MAX];
    double agmPeso[MAX];
    int tam = prim(verticeInicial, agmU, agmV, agmPeso);
    double total = 0;

    for(int i = 0; i < tam; i++){
        cout << agmU[i] << " " << agmV[i] << " " << agmPeso[i] << endl;
        total += agmPeso[i];
    }

    cout << total << endl;
}