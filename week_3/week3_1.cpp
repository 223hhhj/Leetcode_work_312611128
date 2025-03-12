class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            // 先將體重排序
            sort(people.begin(), people.end());
            
            int boats = 0;  // 記錄需要的船數
            int left = 0;   // 指向最輕的人
            int right = people.size() - 1;  // 指向最重的人
            
            // 使用雙指針來配對乘客
            while (left <= right) {
                // 查看最輕和最重的人是否可以一起坐船
                if (people[left] + people[right] <= limit) {
                    left++;  // 最輕的人可以上船
                    right--; // 最重的人可以上船
                } else {
                    right--; // 只有最重的人可以上船
                }
                boats++; // 無論如何都需要一艘船
            }
            
            return boats;
        }
    };