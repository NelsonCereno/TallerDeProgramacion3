#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

// Clase que representa un grafo dirigido con capacidades en las aristas
class Graph {
public:
    int V; // Número de vértices en el grafo
    std::vector<std::vector<int>> capacity; // Matriz de capacidades de las aristas
    std::vector<std::vector<int>> adj; // Lista de adyacencia para representar el grafo

    // Constructor que inicializa un grafo con V vértices
    Graph(int V);

    // Método para agregar una arista al grafo
    // u: vértice de origen
    // v: vértice de destino
    // cap: capacidad de la arista
    void addEdge(int u, int v, int cap);
};

#endif // GRAPH_H