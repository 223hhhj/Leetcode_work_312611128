class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            if (n <= 2) return 0; // Need at least 3 bars to trap water
            
            int left = 0, right = n - 1; // Two pointers
            int leftMax = height[left], rightMax = height[right]; // Max heights from both sides
            int result = 0;
            
            while (left < right) {
                // Update the maximum heights from both sides
                leftMax = max(leftMax, height[left]);
                rightMax = max(rightMax, height[right]);
                
                // If left bar is smaller, water trapped at current left position
                // depends on leftMax and current height
                if (height[left] < height[right]) {
                    result += leftMax - height[left];
                    left++;
                } 
                // Otherwise, water trapped at current right position
                // depends on rightMax and current height
                else {
                    result += rightMax - height[right];
                    right--;
                }
            }
            
            return result;
        }
    };