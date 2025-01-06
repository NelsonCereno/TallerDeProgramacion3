#include "MaxFlow.h"
#include <iostream>
#include <climits>
#include <cassert>

// Función para probar el método BFS de la clase MaxFlow
void testBFS() {
    std::cout << "Probando BFS..." << std::endl;
    Graph graph(4); // Crea un grafo con 4 vértices
    graph.addEdge(0, 1, 10); // Agrega una arista del vértice 0 al vértice 1 con capacidad 10
    graph.addEdge(0, 2, 10); // Agrega una arista del vértice 0 al vértice 2 con capacidad 10
    graph.addEdge(1, 2, 2); // Agrega una arista del vértice 1 al vértice 2 con capacidad 2
    graph.addEdge(1, 3, 4); // Agrega una arista del vértice 1 al vértice 3 con capacidad 4
    graph.addEdge(2, 3, 10); // Agrega una arista del vértice 2 al vértice 3 con capacidad 10

    MaxFlow maxFlow;
    std::vector<int> level(4); // Vector para almacenar los niveles de los nodos
    bool result = maxFlow.bfs(graph, 0, 3, level); // Ejecuta BFS desde el nodo 0 al nodo 3
    std::cout << "Resultado de BFS: " << result << std::endl;
    std::cout << "Niveles de los nodos: ";
    for (int l : level) {
        std::cout << l << " "; // Imprime los niveles de los nodos
    }
    std::cout << std::endl;
    assert(result); // Verifica que BFS encontró un camino desde 0 hasta 3
    assert(level[0] == 0); // Verifica que el nivel del nodo 0 sea 0
    assert(level[1] == 1); // Verifica que el nivel del nodo 1 sea 1
    assert(level[2] == 1); // Verifica que el nivel del nodo 2 sea 1
    assert(level[3] == 2); // Verifica que el nivel del nodo 3 sea 2
    std::cout << "testBFS Completado con exito!" << std::endl;
}

// Función para probar el método Dinic de la clase MaxFlow
void testDinic() {
    std::cout << "Probando Dinic..." << std::endl;
    Graph graph(4); // Crea un grafo con 4 vértices
    graph.addEdge(0, 1, 10); // Agrega una arista del vértice 0 al vértice 1 con capacidad 10
    graph.addEdge(0, 2, 10); // Agrega una arista del vértice 0 al vértice 2 con capacidad 10
    graph.addEdge(1, 2, 2); // Agrega una arista del vértice 1 al vértice 2 con capacidad 2
    graph.addEdge(1, 3, 4); // Agrega una arista del vértice 1 al vértice 3 con capacidad 4
    graph.addEdge(2, 3, 10); // Agrega una arista del vértice 2 al vértice 3 con capacidad 10

    MaxFlow maxFlow;
    int totalFlow = maxFlow.dinic(graph, 0, 3); // Ejecuta el algoritmo de Dinic desde el nodo 0 al nodo 3
    std::cout << "Flujo total encontrado por Dinic: " << totalFlow << std::endl;
    assert(totalFlow == 14); // Verifica que el flujo total encontrado sea 14
    std::cout << "testDinic Completado con exito!" << std::endl;
}

// Función principal que ejecuta las pruebas
int main() {
    testBFS(); // Ejecuta la prueba del método BFS
    testDinic(); // Ejecuta la prueba del método Dinic
    return 0;
}