#include <iostream>

void warshall(int n, int graph[][100]) {
    int closure[100][100];

    // Initialize closure matrix with the given graph
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            closure[i][j] = graph[i][j];
        }
    }

    // Perform Warshall's algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
            }
        }
    }

    // Print the transitive closure matrix
    std::cout << "Transitive Closure Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << closure[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;

    std::cout << "Enter the number of vertices: ";
    std::cin >> n;

    int graph[100][100];
    std::cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> graph[i][j];
        }
    }

    warshall(n, graph);
    return 0;
}
