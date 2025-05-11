class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            // Set search boundaries
            int left = 1;  // Minimum possible eating speed
            int right = *max_element(piles.begin(), piles.end());  // Maximum possible eating speed
            
            // Binary search to find the minimum eating speed
            while (left < right) {
                int mid = left + (right - left) / 2;
                
                // Check if Koko can eat all bananas within h hours at speed mid
                if (canEatAll(piles, mid, h)) {
                    // If possible, try a smaller speed
                    right = mid;
                } else {
                    // If not possible, try a larger speed
                    left = mid + 1;
                }
            }
            
            return left;
        }
        
    private:
        // Helper function to check if Koko can eat all bananas in h hours at speed k
        bool canEatAll(const vector<int>& piles, int k, int h) {
            int hoursNeeded = 0;
            
            for (int pile : piles) {
                // Calculate hours needed for this pile
                // Using ceiling division: (pile + k - 1) / k
                hoursNeeded += (pile + k - 1) / k;
                
                // Early termination if hours exceed h
                if (hoursNeeded > h) {
                    return false;
                }
            }
            
            return true;
        }
    };