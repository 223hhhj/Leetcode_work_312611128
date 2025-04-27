class Solution {
    public:
        int paintWalls(vector<int>& cost, vector<int>& time) {
            int n = cost.size();
            
            // dp[i] 表示塗 i 面牆的最小花費
            // 初始化為一個很大的值，表示無窮大
            vector<int> dp(n + 1, 1e9);
            dp[0] = 0;  // 塗 0 面牆不需要花費
            
            // 遍歷每面牆
            for (int i = 0; i < n; i++) {
                // 從後往前更新，避免重複使用同一面牆
                for (int j = n; j > 0; j--) {
                    // 付費工人塗這面牆，同時免費工人可以塗 time[i] 面牆
                    // 所以總共可以塗 1 + time[i] 面牆
                    int walls = min(j, 1 + time[i]);
                    dp[j] = min(dp[j], dp[j - walls] + cost[i]);
                }
            }
            
            return dp[n];
        }
    };