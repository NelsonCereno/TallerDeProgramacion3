#include "MaxFlow.h"
#include <queue>
#include <climits>
#include <deque>

// Método BFS (Breadth-First Search) para encontrar el nivel de cada nodo
bool MaxFlow::bfs(Graph &graph, int s, int t, std::vector<int> &level) {
    std::fill(level.begin(), level.end(), -1);
    level[s] = 0;
    std::deque<int> q;
    q.push_back(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        for (int v : graph.adj[u]) {
            if (level[v] < 0 && graph.capacity[u][v] > 0) {
                level[v] = level[u] + 1;
                q.push_back(v);
            }
        }
    }

    return level[t] >= 0;
}

// Método DFS (Depth-First Search) para encontrar un camino aumentante
int MaxFlow::dfs(Graph &graph, int u, int t, int flow, std::vector<int> &level, std::vector<int> &start) {
    if (u == t) return flow;

    for (int &i = start[u]; i < graph.adj[u].size(); ++i) {
        int v = graph.adj[u][i];

        if (level[v] == level[u] + 1 && graph.capacity[u][v] > 0) {
            int curr_flow = std::min(flow, graph.capacity[u][v]);
            int temp_flow = dfs(graph, v, t, curr_flow, level, start);

            if (temp_flow > 0) {
                graph.capacity[u][v] -= temp_flow;
                graph.capacity[v][u] += temp_flow;
                return temp_flow;
            }
        }
    }

    return 0;
}

// Método principal del algoritmo de Dinic para encontrar el flujo máximo
int MaxFlow::dinic(Graph &graph, int s, int t) {
    if (s == t) return -1;

    int total_flow = 0;
    std::vector<int> level(graph.V);

    while (bfs(graph, s, t, level)) {
        std::vector<int> start(graph.V, 0);
        while (int flow = dfs(graph, s, t, INT_MAX, level, start)) {
            total_flow += flow;
        }
    }

    return total_flow;
}