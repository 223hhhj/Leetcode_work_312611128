class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            // 如果區間為空，不需要刪除
            if (intervals.empty()) return 0;
            
            // 按照區間結束時間排序
            sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });
            
            int count = 0;  // 要刪除的區間數量
            int end = intervals[0][1];  // 記錄當前選擇的區間的結束時間
            
            // 從第二個區間開始檢查
            for (int i = 1; i < intervals.size(); i++) {
                // 如果當前區間開始時間小於前一個區間結束時間，表示重疊
                if (intervals[i][0] < end) {
                    count++;  // 需要刪除這個區間
                } else {
                    // 不重疊，更新結束時間
                    end = intervals[i][1];
                }
            }
            
            return count;
        }
    };