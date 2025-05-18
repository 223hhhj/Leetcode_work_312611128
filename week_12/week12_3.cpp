class Solution {
    public:
        int maxCoins(vector<int>& nums) {
            int n = nums.size();
            // Add 1 at the beginning and end (virtual balloons)
            vector<int> balloons(n + 2, 1);
            for (int i = 0; i < n; i++) {
                balloons[i + 1] = nums[i];
            }
            
            // dp[i][j] = maximum coins obtained by bursting all balloons between i and j (exclusive)
            vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
            
            // Length of subarray
            for (int len = 1; len <= n; len++) {
                // Starting index i (inclusive)
                for (int i = 1; i <= n - len + 1; i++) {
                    // Ending index j (exclusive)
                    int j = i + len - 1;
                    
                    // Try each balloon as the last one to burst
                    for (int k = i; k <= j; k++) {
                        // Left balloon value * Current balloon value * Right balloon value
                        // + maximum coins from bursting all balloons in range (i, k-1)
                        // + maximum coins from bursting all balloons in range (k+1, j)
                        dp[i][j] = max(dp[i][j], 
                                      dp[i][k-1] + 
                                      balloons[i-1] * balloons[k] * balloons[j+1] + 
                                      dp[k+1][j]);
                    }
                }
            }
            
            // Return maximum coins obtainable by bursting all balloons
            return dp[1][n];
        }
    };