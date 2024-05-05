#include <iostream>
using namespace std;

const int MAX = 100;

void floydWarshall(int graph[MAX][MAX], int V) {
    int dist[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            
                cout << dist[i][j] << " ";
            
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[MAX][MAX];
    cout << "Enter the adjacency matrix (use '999 OR ANY other bigger number' for infinity):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
           
            
        }
    }

    floydWarshall(graph, V);

    return 0;
}
