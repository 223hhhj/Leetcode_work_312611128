class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n = ratings.size();
            // 初始化糖果數組，每個小朋友至少1顆糖果
            vector<int> candies(n, 1);
            
            // 從左到右遍歷
            for (int i = 1; i < n; i++) {
                if (ratings[i] > ratings[i - 1]) {
                    // 如果當前小朋友評分比左邊高，則糖果數比左邊多1
                    candies[i] = candies[i - 1] + 1;
                }
            }
            
            // 從右到左遍歷
            for (int i = n - 2; i >= 0; i--) {
                if (ratings[i] > ratings[i + 1]) {
                    // 如果當前小朋友評分比右邊高，則糖果數至少比右邊多1
                    candies[i] = max(candies[i], candies[i + 1] + 1);
                }
            }
            
            // 計算總糖果數
            int totalCandies = 0;
            for (int candy : candies) {
                totalCandies += candy;
            }
            
            return totalCandies;
        }
    };