class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> result;
            vector<string> board(n, string(n, '.'));
            
            // Sets to keep track of attacked columns and diagonals
            vector<bool> cols(n, false);
            vector<bool> diag1(2 * n - 1, false); // Main diagonals (top-left to bottom-right)
            vector<bool> diag2(2 * n - 1, false); // Anti-diagonals (bottom-left to top-right)
            
            backtrack(result, board, 0, n, cols, diag1, diag2);
            return result;
        }
        
    private:
        void backtrack(vector<vector<string>>& result, vector<string>& board, int row, int n, 
                       vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
            // Base case: All queens are placed
            if (row == n) {
                result.push_back(board);
                return;
            }
            
            // Try placing a queen in each column of the current row
            for (int col = 0; col < n; col++) {
                // Calculate diagonal indices
                int d1 = row + col;          // Main diagonal index
                int d2 = row - col + n - 1;  // Anti-diagonal index
                
                // If this position is not under attack
                if (!cols[col] && !diag1[d1] && !diag2[d2]) {
                    // Place queen
                    board[row][col] = 'Q';
                    cols[col] = diag1[d1] = diag2[d2] = true;
                    
                    // Proceed to the next row
                    backtrack(result, board, row + 1, n, cols, diag1, diag2);
                    
                    // Backtrack: remove queen
                    board[row][col] = '.';
                    cols[col] = diag1[d1] = diag2[d2] = false;
                }
            }
        }
    };