#include <iostream>
#include <algorithm>
using namespace std;

// Function to solve 0/1 knapsack problem
int knapsack(int W, int wt[], int val[], int n, int selected_items[]) {
    int K[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {