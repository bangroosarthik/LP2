#include<bits/stdc++.h>
using namespace std;

void solve(int col, vector<string>& board, vector<vector<string>>& vec, vector<int>& LeftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
    //base case 
    if(col == n) {
        vec.push_back(board);
        return;
    }

    for(int row = 0; row < n; row++) {
        //using hashing 
        if(LeftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
            board[row][col] = 'Q';
            LeftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            solve(col + 1, board, vec, LeftRow, upperDiagonal, lowerDiagonal, n);
            board[row][col] = '.';
            LeftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<string>> vec;
    vector<string> board(n, string(n, '.')); // Initialize board with size n and '.' characters
    vector<int> LeftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, vec, LeftRow, upperDiagonal, lowerDiagonal, n);

    // Printing solutions
    for(int i = 0; i < vec.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for(int j = 0; j < n; j++) {
            cout << vec[i][j] << "\n";
        }
        cout << "\n";
    }

    return 0;
}
