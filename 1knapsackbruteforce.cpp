#include <iostream>
#include <algorithm>
using namespace std;

// Function to solve 0/1 knapsack problem
int knapsack(int W, int wt[], int val[], int n, int selected_items[]) {
    int K[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    int maxVal = K[n][W];
    int w = W;
    int items_count = 0;
    for (int i = n; i > 0 && maxVal > 0; i--) {
        if (maxVal != K[i - 1][w]) {
            selected_items[items_count++] = i - 1;
            maxVal -= val[i - 1];
            w -= wt[i - 1];
        }
    }

    return K[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int val[n], wt[n];
    cout << "Enter the values and weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i] >> wt[i];
    }

    int W;
    cout << "Enter the capacity of knapsack: ";
    cin >> W;

    int selected_items[n]; // Assuming the maximum number of selected items won't exceed n
    int maxVal = knapsack(W, wt, val, n, selected_items);
    cout << "The maximum value that can be obtained is: " << maxVal << endl;

    cout << "Items selected:\n";
    for (int i = 0; i < maxVal; i++) {
        cout << "Value: " << val[selected_items[i]] << ", Weight: " << wt[selected_items[i]] << endl;
    }

    return 0;
}
