#include <iostream>
#include <map>
#include <string>

using namespace std;

const int MAX = 100;

// Function to check if it's safe to assign the color 'c' to vertex 'v'
bool isSafe(int v, int graph[MAX][MAX], int color[MAX], int c, int n) {
    for (int i = 0; i < n; ++i) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

// Function to recursively assign colors to the vertices and print all solutions
void graphColoringUtil(int graph[MAX][MAX], int m, int color[MAX], int v, int n, map<int, string>& colorNames) {
    if (v == n) {
        cout << "Solution:\n";
        for (int i = 0; i < n; ++i) {
            cout << "Vertex " << i << ": " << colorNames[color[i]] << endl;
        }
        cout << endl;
        return;
    }

    for (int c = 1; c <= m; ++c) {
        if (isSafe(v, graph, color, c, n)) {
            color[v] = c;
            graphColoringUtil(graph, m, color, v + 1, n, colorNames);
            color[v] = 0;
        }
    }
}

int main() {
    int n; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[MAX][MAX] = {0};

    // Taking adjacency matrix as input
    cout << "Enter the adjacency matrix (0 for no edge, 1 for edge):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int m; // Number of colors
    cout << "Enter the number of colors: ";
    cin >> m;

    map<int, string> colorNames;
    cout << "Enter the names of colors:\n";
    for (int i = 1; i <= m; ++i) {
        string colorName;
        cout << "Color " << i << ": ";
        cin >> colorName;
        colorNames[i] = colorName;
    }

    int color[MAX] = {0};

    graphColoringUtil(graph, m, color, 0, n, colorNames);

    return 0;
}
