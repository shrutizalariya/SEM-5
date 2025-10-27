#include <stdio.h>
#define INF 9999
#define V 5   // number of vertices (change as needed)

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    int dist[V];      // shortest distances
    int visited[V];   // visited array
    int src = 0;      // starting node

    // initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    // Dijkstra main loop
    for (int c = 0; c < V - 1; c++) {
        // find unvisited vertex with minimum distance
        int min = INF, u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // update distances of neighbors
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print result
    printf("Shortest distance from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}
