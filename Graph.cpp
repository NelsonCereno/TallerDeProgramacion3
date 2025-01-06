#include "Graph.h"

// Constructor de la clase Graph
// Inicializa un grafo con V vértices, una matriz de capacidad y una lista de adyacencia
Graph::Graph(int V) : V(V), capacity(V, std::vector<int>(V, 0)), adj(V) {}

// Método para agregar una arista al grafo
// u: vértice de origen
// v: vértice de destino
// cap: capacidad de la arista
void Graph::addEdge(int u, int v, int cap) {
    // Establece la capacidad de la arista de u a v
    capacity[u][v] = cap;
    // Agrega v a la lista de adyacencia de u
    adj[u].push_back(v);
    // Agrega u a la lista de adyacencia de v (para el grafo residual)
    adj[v].push_back(u);
}