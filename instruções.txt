# Trabalho Prático 1 - Teoria dos Grafos (DCC059)

Este repositório contém a implementação da estrutura de dados de Grafo utilizando Matriz de Adjacência. O projeto conta com testes de validação para garantir o funcionamento correto de grafos Orientados e Não Orientados, Ponderados ou Não.

## Estrutura do Projeto

* `src/Grafo.hpp` - Declaração da classe Grafo e seus métodos.
* `src/Grafo.cpp` - Implementação das lógicas da matriz de adjacência, inserção/remoção de arestas, vértices e cálculo de graus.
* `src/testall.cpp` - Bateria de testes oficial para validar o funcionamento do grafo.

## Como Compilar e Rodar os Testes

Para garantir que a implementação obedece a todas as especificações do trabalho, você pode rodar a bateria de testes usando o compilador G++ via terminal.

### Passo 1: Abrir o terminal
Abra o terminal (Prompt de Comando, PowerShell ou terminal do VS Code) na raiz deste projeto.

### Passo 2: Navegar para a pasta `src`
Caso ainda não esteja dentro da pasta que contém os arquivos de código, navegue até ela:
```bash
cd src
```

### Passo 3: Compilar o código
Use o compilador `g++` para juntar a sua implementação (`Grafo.cpp`) e o arquivo de teste (`testall.cpp`) em um único arquivo executável:
```bash
g++ Grafo.cpp testall.cpp -o testall.exe
```

### Passo 4: Executar os testes
Após a compilação, o arquivo `testall.exe` será gerado. Para rodá-lo no Windows, digite:
```bash
.\testall.exe
```

A saída vai detalhar todos os testes de operações (inserir arestas, verificar graus, adjacência unidirecional/bidirecional, etc) separando grafos não orientados e orientados, informando os que PASSARAM ou FALHARAM.
