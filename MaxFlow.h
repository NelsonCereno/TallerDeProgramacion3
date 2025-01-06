#ifndef MAXFLOW_H
#define MAXFLOW_H

#include "Graph.h"
#include <vector>

// Clase que implementa el algoritmo de Dinic para encontrar el flujo máximo en un grafo
class MaxFlow {
public:
    // Método principal del algoritmo de Dinic para encontrar el flujo máximo
    // graph: referencia al grafo
    // s: nodo fuente
    // t: nodo sumidero
    // Devuelve el flujo máximo desde el nodo fuente s al nodo sumidero t
    int dinic(Graph &graph, int s, int t);

    // Método BFS (Breadth-First Search) para encontrar el nivel de cada nodo
    // graph: referencia al grafo
    // s: nodo fuente
    // t: nodo sumidero
    // level: vector de niveles de los nodos
    // Devuelve true si se encuentra un camino desde s hasta t, false en caso contrario
    bool bfs(Graph &graph, int s, int t, std::vector<int> &level);

    // Método DFS (Depth-First Search) para encontrar un camino aumentante
    // graph: referencia al grafo
    // u: nodo actual
    // t: nodo sumidero
    // flow: flujo actual
    // level: vector de niveles de los nodos
    // start: vector de índices de inicio para los nodos
    // Devuelve el flujo encontrado en el camino aumentante
    int dfs(Graph &graph, int u, int t, int flow, std::vector<int> &level, std::vector<int> &start);
};

#endif // MAXFLOW_H