#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 20;
const int INF = 1e9; 
int calculateTotalCost(int costMatrix[MAX_N][MAX_N], int assignment[MAX_N], int n) {
    int totalCost = 0;
    for (int i = 0; i < n; ++i) {
        totalCost += costMatrix[i][assignment[i]];
    }
    return totalCost;
}
void bruteForceAssignment(int costMatrix[MAX_N][MAX_N], int n) {
    int assignment[MAX_N];
    for (int i = 0; i < n; ++i) {
        assignment[i] = i; 
    }
    int minCost = INF;
    int minAssignment[MAX_N];
    do {
        int totalCost = calculateTotalCost(costMatrix, assignment, n);
        if (totalCost < minCost) {
            minCost = totalCost;
            for (int i = 0; i < n; ++i) {
                minAssignment[i] = assignment[i];
            }
        }
    } while (next_permutation(assignment, assignment + n));

    cout << "Minimum cost: " << minCost << endl;
    cout << "Corresponding assignment: ";
    for (int i = 0; i < n; ++i) {
        cout << "(" << i << "," << minAssignment[i] << ") ";
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Enter the number of jobs/workers ";
    cin >> n;
    int costMatrix[MAX_N][MAX_N];
    cout << "Enter the cost matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> costMatrix[i][j];
        }
    }
    bruteForceAssignment(costMatrix, n);
    return 0;
}
