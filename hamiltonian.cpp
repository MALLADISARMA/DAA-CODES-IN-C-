#include <iostream>
using namespace std;

const int MAX = 10; 
bool graph[MAX][MAX]; 
int path[MAX]; 
int n; 
bool isSafe(int v, int pos) {
  
    if (!graph[path[pos - 1]][v]) 
        return false;

   
    for (int i = 0; i < pos; ++i)
        if (path[i] == v) 
            return false;

    return true;
}


bool hamiltonianCycleUtil(int pos) {
    
    if (pos == n) {
     
        if (graph[path[pos - 1]][path[0]])
            return true;
        else
            return false;
    }

    for (int v = 1; v < n; ++v) {
        if (isSafe(v, pos)) {
            path[pos] = v; 
            if (hamiltonianCycleUtil(pos + 1)) 
                return true;
            path[pos] = -1; 
        }
    }

    return false; 
}


void findHamiltonianCycle() {
    path[0] = 0; 
    if (!hamiltonianCycleUtil(1)) {
        cout << "No Hamiltonian cycle exists.\n";
        return;
    }

    cout << "Hamiltonian cycle exists:\n";
    for (int i = 0; i < n; ++i)
        cout << path[i] << " ";
    cout << path[0] << "\n";
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix (0 for no edge, 1 for edge):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];

    findHamiltonianCycle();

    return 0;
}
