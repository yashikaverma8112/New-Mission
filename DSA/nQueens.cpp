// User function Template for C++

class Solution {
  public:

    bool isSafe(int row, int col, vector<int>& positions) {
        for (int prevRow = 0; prevRow < row; prevRow++) {
            int prevCol = positions[prevRow];
            // Same column or same diagonal
            if (prevCol == col || abs(prevCol - col) == abs(prevRow - row)) {
                return false;
            }
        }
        return true;
    }

    void solve(int row, int n, vector<int>& positions, vector<vector<int>>& result) {
        if (row == n) {
            // Copy and convert to 1-based indexing
            vector<int> solution;
            for (int col : positions) {
                solution.push_back(col + 1);
            }
            result.push_back(solution);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, positions)) {
                positions[row] = col;
                solve(row + 1, n, positions, result);
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> result;
        vector<int> positions(n);  // positions[i] = column of queen in row i
        solve(0, n, positions, result);
        return result;
    }


};
