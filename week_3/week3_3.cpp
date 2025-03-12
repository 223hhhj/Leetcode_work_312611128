class Solution {
    public:
        int intersectionSizeTwo(vector<vector<int>>& intervals) {
            // 按照區間的結束點升序排序，如果結束點相同，則按照起始點降序排序
            sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
                if (a[1] == b[1]) return a[0] > b[0];
                return a[1] < b[1];
            });
            
            vector<int> result; // 存放選擇的數字
            
            for (const auto& interval : intervals) {
                int start = interval[0];
                int end = interval[1];
                
                // 檢查當前區間與已選數字的交集
                int size = result.size();
                int count = 0; // 記錄與當前區間的交集大小
                
                // 從後往前檢查已選的數字，看是否在當前區間內
                for (int i = size - 1; i >= 0 && count < 2; i--) {
                    if (result[i] >= start && result[i] <= end) {
                        count++;
                    }
                }
                
                // 如果交集數量不足2，需要添加數字
                if (count == 0) {
                    // 添加區間的最後兩個數字
                    result.push_back(end - 1);
                    result.push_back(end);
                } else if (count == 1) {
                    // 已有一個交集，再添加一個（盡量選大的，即區間結束點）
                    result.push_back(end);
                }
                // 如果交集已經有2個或以上，不需要再添加
            }
            
            return result.size();
        }
    };