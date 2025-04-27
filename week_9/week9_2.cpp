class Solution {
    public:
        bool isMatch(string s, string p) {
            int m = s.length(), n = p.length();
            vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
            
            // Empty pattern matches empty string
            dp[0][0] = true;
            
            // Handle patterns starting with '*'
            for (int j = 1; j <= n && p[j-1] == '*'; j++) {
                dp[0][j] = true;
            }
            
            // Fill DP table
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (p[j-1] == '*') {
                        // '*' can match current char and continue (*) or skip '*' (match empty)
                        dp[i][j] = dp[i][j-1] || dp[i-1][j];
                    } else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                        // '?' matches any char or chars match exactly
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
            
            return dp[m][n];
        }
    };