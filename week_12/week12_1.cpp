class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int total = 0;
            
            // Calculate the total sum of the array
            for (int num : nums) {
                total += num;
            }
            
            // If the total sum is odd, it cannot be partitioned into equal subsets
            if (total % 2 != 0) {
                return false;
            }
            
            int target = total / 2;
            int n = nums.size();
            
            // dp[i] = true if sum i can be achieved using any subset of nums
            vector<bool> dp(target + 1, false);
            
            // Base case: 0 sum is always achievable (by taking no elements)
            dp[0] = true;
            
            // For each number, update the dp table
            for (int num : nums) {
                // We need to go backwards to avoid counting the same element multiple times
                for (int i = target; i >= num; i--) {
                    // If we can form sum i-num, we can form sum i by adding num
                    dp[i] = dp[i] || dp[i - num];
                }
            }
            
            // Return whether we can form the target sum
            return dp[target];
        }
    };