class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> current;
            vector<bool> used(nums.size(), false);
            
            backtrack(nums, used, current, result);
            
            return result;
        }
        
    private:
        void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
            // If the current permutation is complete (has all elements)
            if (current.size() == nums.size()) {
                result.push_back(current);
                return;
            }
            
            // Try each number that hasn't been used yet
            for (int i = 0; i < nums.size(); i++) {
                // Skip if this number is already used in the current permutation
                if (used[i]) continue;
                
                // Choose the current number
                used[i] = true;
                current.push_back(nums[i]);
                
                // Recursively build the rest of the permutation
                backtrack(nums, used, current, result);
                
                // Backtrack (undo the choice)
                current.pop_back();
                used[i] = false;
            }
        }
    };