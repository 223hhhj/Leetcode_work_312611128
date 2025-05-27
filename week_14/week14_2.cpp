class Solution {
    public:
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
            if (indexDiff <= 0 || valueDiff < 0) return false;
            
            // Use multiset to maintain a sorted sliding window
            multiset<long long> window;
            
            for (int i = 0; i < nums.size(); i++) {
                // Remove element that is outside the indexDiff range
                if (i > indexDiff) {
                    window.erase(window.find(nums[i - indexDiff - 1]));
                }
                
                // Convert to long long to avoid overflow
                long long current = nums[i];
                
                // Find the smallest element >= (current - valueDiff)
                auto it = window.lower_bound(current - valueDiff);
                
                // Check if there exists an element within valueDiff range
                if (it != window.end() && *it <= current + valueDiff) {
                    return true;
                }
                
                // Add current element to window
                window.insert(current);
            }
            
            return false;
        }
    };