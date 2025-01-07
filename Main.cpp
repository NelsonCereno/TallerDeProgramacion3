#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Graph.h"
#include "MaxFlow.h"

using namespace std;
using namespace std::chrono;

class Main {
public:
    // Método principal que ejecuta el menú interactivo
    static void run() {
        Graph* graph = nullptr; // Puntero al grafo
        vector<int> sources; // Vectores para almacenar las fuentes
        vector<int> sinks; // Vectores para almacenar los sumideros
        int artificialSource, artificialSink; // Variables para las fuentes y sumideros artificiales

        while (true) {
            // Mostrar el menú
            cout << "Menu:\n";
            cout << "1. Cargar grafo\n";
            cout << "2. Ejecutar flujo máximo\n";
            cout << "3. Salir\n";
            cout << "Seleccione una opción: ";
            int option;
            cin >> option;

            if (option == 1) {
                // Cargar un nuevo grafo
                if (graph != nullptr) {
                    delete graph;
                    graph = nullptr;
                }
                tie(graph, sources, sinks, artificialSource, artificialSink) = loadGraph();
            } else if (option == 2) {
                // Ejecutar el cálculo del flujo máximo
                if (graph == nullptr) {
                    cout << "Primero debe cargar un grafo.\n";
                } else {
                    executeMaxFlow(*graph, sources, sinks, artificialSource, artificialSink);
                }
            } else if (option == 3) {
                // Salir del programa
                break;
            } else {
                cout << "Opción no válida. Intente de nuevo.\n";
            }
        }

        // Liberar la memoria del grafo si está cargado
        if (graph != nullptr) {
            delete graph;
        }
    }

private:
    // Método para cargar el grafo desde un archivo
    static tuple<Graph*, vector<int>, vector<int>, int, int> loadGraph() {
        string filename;
        cout << "Ingrese el nombre del archivo que contiene el grafo (junto con su extension .txt): ";
        cin >> filename;

        auto start_read = high_resolution_clock::now();

        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "No se pudo abrir el archivo." << endl;
            return {nullptr, {}, {}, -1, -1};
        }

        string line;
        getline(file, line);
        vector<int> sources = parseLine(line);
        getline(file, line);
        vector<int> sinks = parseLine(line);

        vector<tuple<int, int, int>> edges;
        edges.reserve(1000000); // Reservar espacio para evitar realocaciones frecuentes

        while (getline(file, line)) {
            istringstream iss(line);
            int u, v, cap;
            iss >> u >> v >> cap;
            edges.push_back({u, v, cap});
        }
        file.close();

        int V = 0;
        for (const auto &edge : edges) {
            V = max(V, max(get<0>(edge), get<1>(edge)) + 1);
        }

        Graph* graph = new Graph(V + 2); // +2 por la fuente y el sumidero extra
        int artificialSource = V;
        int artificialSink = V + 1;

        vector<int> sourceCapacities(V, 0);
        vector<int> sinkCapacities(V, 0);

        for (const auto &edge : edges) {
            int u = get<0>(edge);
            int v = get<1>(edge);
            int cap = get<2>(edge);
            graph->addEdge(u, v, cap);
            if (find(sources.begin(), sources.end(), u) != sources.end()) {
                sourceCapacities[u] += cap;
            }
            if (find(sinks.begin(), sinks.end(), v) != sinks.end()) {
                sinkCapacities[v] += cap;
            }
        }

        for (int source : sources) {
            graph->addEdge(artificialSource, source, sourceCapacities[source]);
        }

        for (int sink : sinks) {
            graph->addEdge(sink, artificialSink, sinkCapacities[sink]);
        }

        auto stop_read = high_resolution_clock::now();
        auto duration_read = duration_cast<duration<double, std::milli>>(stop_read - start_read);

        cout << "Tiempo de lectura y creación del grafo: " << duration_read.count() << " [ms]" << endl;

        return {graph, sources, sinks, artificialSource, artificialSink};
    }

    // Método para ejecutar el cálculo del flujo máximo
    static void executeMaxFlow(Graph &graph, const vector<int> &sources, const vector<int> &sinks, int artificialSource, int artificialSink) {
        MaxFlow maxFlow;
        auto start_flow = high_resolution_clock::now();
        int totalFlow = maxFlow.dinic(graph, artificialSource, artificialSink);
        auto stop_flow = high_resolution_clock::now();
        auto duration_flow = duration_cast<duration<double, std::milli>>(stop_flow - start_flow);

        cout << "Nodos fuente: ";
        for (int source : sources) {
            cout << source << " ";
        }
        cout << endl;

        cout << "Nodos sumidero: ";
        for (int sink : sinks) {
            cout << sink << " ";
        }
        cout << endl;

        cout << "Flujo Total: " << totalFlow << endl;
        cout << "Tiempo de cálculo del flujo máximo: " << duration_flow.count() << " [ms]" << endl;
    }

    // Método para parsear una línea de texto en un vector de enteros
    static vector<int> parseLine(const string &line) {
        istringstream iss(line);
        vector<int> result;
        int num;
        while (iss >> num) {
            result.push_back(num);
        }
        return result;
    }
};

int main() {
    Main::run();
    return 0;
}