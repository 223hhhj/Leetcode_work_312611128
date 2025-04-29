class Solution {
    public:
        int shortestPathLength(vector<vector<int>>& graph) {
            int n = graph.size(); // 節點數量
            int target = (1 << n) - 1; // 目標狀態：所有節點都訪問過（二進位全為 1）
            
            // 隊列：儲存 (當前節點, 當前狀態, 步數)
            queue<tuple<int, int, int>> q;
            // 訪問記錄：避免重複訪問 (節點, 狀態)
            vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
            
            // Step 1: 初始化，從每個節點開始
            for (int i = 0; i < n; i++) {
                int initialState = (1 << i); // 只訪問當前節點 i
                q.push({i, initialState, 0}); // 加入隊列：節點 i，狀態，步數 0
                visited[i][initialState] = true; // 標記已訪問
            }
            
            // Step 2: BFS 搜尋
            while (!q.empty()) {
                auto [currNode, currState, steps] = q.front(); // 取出當前狀態
                q.pop();
                
                // 如果所有節點都訪問過，回傳步數
                if (currState == target) {
                    return steps;
                }
                
                // 遍歷當前節點的鄰居
                for (int nextNode : graph[currNode]) {
                    // 更新狀態：訪問 nextNode
                    int nextState = currState | (1 << nextNode);
                    
                    // 如果這個 (節點, 狀態) 沒訪問過
                    if (!visited[nextNode][nextState]) {
                        visited[nextNode][nextState] = true; // 標記為已訪問
                        q.push({nextNode, nextState, steps + 1}); // 加入隊列
                    }
                }
            }
            
            // 如果無法訪問所有節點（理論上不會發生，因為圖是連通的）
            return 0;
        }
    };