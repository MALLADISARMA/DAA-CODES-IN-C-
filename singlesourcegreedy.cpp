#include <iostream>
#include <limits>
using namespace std;
const int MAX_VERTICES = 10;
const int INF = 1e9; 
int minDistance(int dist[], bool visited[], int V) {
    int minDist = INF, minIndex = -1;
    for (int v = 0; v < V; ++v) {
        if (!visited[v] && dist[v] < minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int V) {
    int dist[MAX_VERTICES]; // Array to store the shortest distances
    bool visited[MAX_VERTICES]; // Array to mark visited vertices
    for (int i = 0; i < V; ++i) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0; // Distance from source vertex to itself is 0
    for (int count = 0; count < V - 1; ++count) {
        int u = minDistance(dist, visited, V); // Pick the vertex with the minimum distance value
        visited[u] = true; // Mark the picked vertex as visited
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Shortest distances from vertex " << src << " to all other vertices:\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        if (dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }
}
int main() {
    int V; // Number of vertices
    cout << "Enter the number of vertices (maximum " << MAX_VERTICES << "): ";
    cin >> V;
    int graph[MAX_VERTICES][MAX_VERTICES];
    cout << "Enter the adjacency matrix (enter INF for no edge):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }
    int src; // Source vertex
    cout << "Enter the source vertex: ";
    cin >> src;
    dijkstra(graph, src, V);
    return 0;
}
