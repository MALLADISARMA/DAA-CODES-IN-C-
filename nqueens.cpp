#include <iostream>

using namespace std;
bool place(int queens[], int row, int col, int n);
void NQueens(int queens[], int n, int row);

bool place(int queens[], int row, int col, int n) {
    for (int i = 0; i < row; ++i) {
     
        if (queens[i] == col || queens[i] - i == col - row || queens[i] + i == col + row) {
            return false;
        }
    }
    return true;
}
void NQueens(int queens[], int n, int row) {
    if (row == n) {
    
        cout << "Solution: ";
        for (int i = 0; i < n; ++i) {
            cout << queens[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (place(queens, row, col, n)) {
            queens[row] = col; // Place the queen
            NQueens(queens, n, row + 1); // Recur for the next row
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

   
    int queens[n];

  
    NQueens(queens, n, 0);

    return 0;
}