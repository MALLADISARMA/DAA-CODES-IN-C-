#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 15; // Maximum number of cities, adjust as needed

// Function to solve TSP using dynamic programming
int tsp(int graph[MAX][MAX], int n) {
    // dp[i][j] stores the minimum cost to visit all cities starting from i and ending at j
    int dp[1 << MAX][MAX];

    // Base case: reaching a single city has cost 0
    for (int i = 0; i < n; ++i)
        dp[1 << i][i] = 0;

    // Iterate over all possible subsets of cities
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            // Check if the current city 'u' is in the current subset 'mask'
            if (!(mask & (1 << u)))
                continue;
            // Iterate over all possible previous cities 'v' to reach 'u'
            for (int v = 0; v < n; ++v) {
                if (mask & (1 << v)) {
                    // If 'v' is in the subset and is not equal to 'u'
                    if (dp[mask ^ (1 << u)][v] != INT_MAX && graph[v][u] != -1) {
                        dp[mask][u] = min(dp[mask][u], dp[mask ^ (1 << u)][v] + graph[v][u]);
                    }
                }
            }
        }
    }

    // Find the minimum cost to visit all cities starting and ending at 0
    int minCost = INT_MAX;
    for (int v = 1; v < n; ++v) {
        if (graph[v][0] != -1) {
            minCost = min(minCost, dp[(1 << n) - 1][v] + graph[v][0]);
        }
    }

    return minCost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    // Example graph - adjacency matrix representation
    int graph[MAX][MAX];
    cout << "Enter the adjacency matrix for the graph (enter -1 for unreachable):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int minCost = tsp(graph, n);

    cout << "Minimum cost to visit all cities: " << minCost << endl;

    return 0;
}
