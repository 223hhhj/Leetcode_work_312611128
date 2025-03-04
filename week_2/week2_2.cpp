class Solution {
    public:
        long long minimumReplacement(vector<int>& nums) {
            int n = nums.size();
            long long operations = 0;
            int target = nums[n - 1];
    
            for (int i = n - 2; i >= 0; --i) {
                if (nums[i] > target) {
                    int k = (nums[i] + target - 1) / target;
                    operations += k - 1;
                    target = nums[i] / k;
                } else {
                    target = nums[i];
                }
            }
            return operations;
        }
    };