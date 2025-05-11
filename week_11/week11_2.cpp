class ExamRoom {
    private:
        int n;
        vector<int> seats;
    
    public:
        ExamRoom(int n) {
            this->n = n;
        }
        
        int seat() {
            if (seats.empty()) {
                seats.push_back(0);
                return 0;
            }
            
            int maxDist = seats[0]; // 從開始到第一個座位的距離
            int pos = 0;
            
            // 優化：預先計算向量大小避免反覆訪問
            int size = seats.size();
            
            // 檢查相鄰座位之間的距離
            for (int i = 0; i < size - 1; ++i) {
                int curr = seats[i];
                int next = seats[i + 1];
                int mid = curr + (next - curr) / 2;
                int dist = mid - curr;
                
                if (dist > maxDist) {
                    maxDist = dist;
                    pos = mid;
                }
            }
            
            // 檢查最後一個座位到尾端的距離
            int lastDist = n - 1 - seats[size - 1];
            if (lastDist > maxDist) {
                pos = n - 1;
            }
            
            // 使用二分查找，但預先檢查常見情況以減少 binary search 的次數
            if (pos < seats[0]) {
                seats.insert(seats.begin(), pos);
            } else if (pos > seats.back()) {
                seats.push_back(pos);
            } else {
                auto it = lower_bound(seats.begin(), seats.end(), pos);
                seats.insert(it, pos);
            }
            
            return pos;
        }
        
        void leave(int p) {
            // 優化：對於小型數據，線性搜索可能比二分搜索更快
            if (seats.size() < 20) {
                for (auto it = seats.begin(); it != seats.end(); ++it) {
                    if (*it == p) {
                        seats.erase(it);
                        return;
                    }
                }
            } else {
                auto it = lower_bound(seats.begin(), seats.end(), p);
                if (it != seats.end() && *it == p) {
                    seats.erase(it);
                }
            }
        }
    };