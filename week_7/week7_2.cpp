class Solution {
    public:
        int openLock(vector<string>& deadends, string target) {
            // 將deadends放入集合中，便於快速查找
            unordered_set<string> dead(deadends.begin(), deadends.end());
            
            // 如果起點就是死鎖或目標，直接處理
            if (dead.count("0000")) return -1;
            if (target == "0000") return 0;
            
            // 用於BFS
            queue<string> q;
            q.push("0000");
            
            // 用於記錄已訪問的狀態
            unordered_set<string> visited;
            visited.insert("0000");
            
            int steps = 0;
            
            // BFS過程
            while (!q.empty()) {
                int size = q.size();
                steps++;
                
                for (int i = 0; i < size; i++) {
                    string curr = q.front();
                    q.pop();
                    
                    // 嘗試轉動每一位
                    for (int j = 0; j < 4; j++) {
                        for (int d = -1; d <= 1; d += 2) { // +1或-1
                            string next = curr;
                            next[j] = (next[j] - '0' + d + 10) % 10 + '0'; // 處理循環
                            
                            // 如果找到目標
                            if (next == target) return steps;
                            
                            // 如果這是一個新的有效狀態
                            if (!visited.count(next) && !dead.count(next)) {
                                visited.insert(next);
                                q.push(next);
                            }
                        }
                    }
                }
            }
            
            return -1; // 無法到達目標
        }
    };