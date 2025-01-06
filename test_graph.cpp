#include "Graph.h"
#include <iostream>
#include <cassert>

// Función para probar el constructor de la clase Graph
void testGraphConstructor() {
    std::cout << "Probando el constructor de Graph..." << std::endl;
    Graph graph(5); // Crea un grafo con 5 vértices
    assert(graph.V == 5); // Verifica que el número de vértices sea 5
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            assert(graph.capacity[i][j] == 0); // Verifica que todas las capacidades iniciales sean 0
        }
        assert(graph.adj[i].empty()); // Verifica que todas las listas de adyacencia estén vacías
    }
    std::cout << "Número de vértices: " << graph.V << std::endl;
    std::cout << "Capacidades iniciales: " << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << graph.capacity[i][j] << " "; // Imprime las capacidades iniciales
        }
        std::cout << std::endl;
    }
    std::cout << "Listas de adyacencia iniciales: " << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << i << ": ";
        for (int v : graph.adj[i]) {
            std::cout << v << " "; // Imprime las listas de adyacencia iniciales
        }
        std::cout << std::endl;
    }
    std::cout << "testGraphConstructor passed!" << std::endl;
}

// Función para probar el método addEdge de la clase Graph
void testAddEdge() {
    std::cout << "Probando el método addEdge de Graph..." << std::endl;
    Graph graph(5); // Crea un grafo con 5 vértices
    graph.addEdge(0, 1, 10); // Agrega una arista del vértice 0 al vértice 1 con capacidad 10
    assert(graph.capacity[0][1] == 10); // Verifica que la capacidad de la arista sea 10
    assert(graph.capacity[1][0] == 0); // Verifica que la capacidad inversa sea 0
    assert(graph.adj[0].size() == 1); // Verifica que la lista de adyacencia del vértice 0 tenga un elemento
    assert(graph.adj[1].size() == 1); // Verifica que la lista de adyacencia del vértice 1 tenga un elemento
    assert(graph.adj[0][0] == 1); // Verifica que el vértice adyacente a 0 sea 1
    assert(graph.adj[1][0] == 0); // Verifica que el vértice adyacente a 1 sea 0
    std::cout << "Capacidades después de agregar la arista (0, 1, 10): " << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << graph.capacity[i][j] << " "; // Imprime las capacidades después de agregar la arista
        }
        std::cout << std::endl;
    }
    std::cout << "Listas de adyacencia después de agregar la arista (0, 1, 10): " << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << i << ": ";
        for (int v : graph.adj[i]) {
            std::cout << v << " "; // Imprime las listas de adyacencia después de agregar la arista
        }
        std::cout << std::endl;
    }
    std::cout << "testAddEdge Completado con exito!" << std::endl;
}

// Función principal que ejecuta las pruebas
int main() {
    testGraphConstructor(); // Ejecuta la prueba del constructor
    testAddEdge(); // Ejecuta la prueba del método addEdge
    return 0;
}