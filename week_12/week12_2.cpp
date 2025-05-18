class Solution {
    public:
        int superEggDrop(int k, int n) {
            // dp[i][j] represents the maximum number of floors that can be tested with
            // i eggs and j moves
            vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
            
            // Initialize moves count
            int moves = 0;
            
            // Keep increasing moves until we can cover all n floors
            while (dp[k][moves] < n) {
                moves++;
                
                // For each egg count from 1 to k
                for (int eggs = 1; eggs <= k; eggs++) {
                    // The maximum number of floors we can test with eggs and moves:
                    // 1. If the egg breaks at the current floor: dp[eggs-1][moves-1] floors below
                    // 2. If the egg doesn't break: dp[eggs][moves-1] floors above
                    // 3. Plus the current floor
                    dp[eggs][moves] = dp[eggs - 1][moves - 1] + dp[eggs][moves - 1] + 1;
                }
            }
            
            return moves;
        }
    };