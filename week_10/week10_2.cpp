class Solution {
    public:
        vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
            int n = edges.size(); // 節點數量（邊數量等於節點數量）
            vector<int> parent(n + 1, 0); // 記錄每個節點的父節點
            vector<int> candidate1, candidate2; // 儲存可能的多父節點邊
            vector<int> cycleEdge; // 儲存導致循環的邊
            
            // Step 1: 檢查多父節點的情況
            for (const auto& edge : edges) {
                int u = edge[0], v = edge[1]; // 邊：u -> v
                if (parent[v] != 0) { // 如果 v 已經有父節點
                    candidate1 = {parent[v], v}; // 第一條指向 v 的邊
                    candidate2 = edge; // 第二條指向 v 的邊
                } else {
                    parent[v] = u; // 記錄 v 的父節點為 u
                }
            }
            
            // Step 2: 初始化並查集
            vector<int> dsu(n + 1); // 並查集陣列
            for (int i = 1; i <= n; i++) {
                dsu[i] = i; // 每個節點最初指向自己
            }
            
            // 並查集的查找函數
            auto find = [&](int x) {
                while (x != dsu[x]) {
                    x = dsu[x];
                }
                return x;
            };
            
            // 並查集的合併函數
            auto unionSets = [&](int u, int v) {
                dsu[find(v)] = find(u);
            };
            
            // Step 3: 檢查循環並忽略 candidate2（如果有）
            for (const auto& edge : edges) {
                int u = edge[0], v = edge[1];
                // 如果這條邊是 candidate2，跳過（模擬移除這條邊）
                if (!candidate2.empty() && edge[0] == candidate2[0] && edge[1] == candidate2[1]) {
                    continue;
                }
                // 檢查是否形成循環
                if (find(u) == find(v)) {
                    cycleEdge = edge; // 記錄導致循環的邊
                } else {
                    unionSets(u, v); // 合併 u 和 v
                }
            }
            
            // Step 4: 根據情況返回結果
            if (!candidate2.empty()) {
                // 如果有兩個父節點的情況
                if (cycleEdge.empty()) {
                    // 如果沒有循環，移除 candidate2（較晚出現的邊）
                    return candidate2;
                } else {
                    // 如果有循環，移除 candidate1（因為 candidate2 移除後仍有循環）
                    return candidate1;
                }
            } else {
                // 如果只有循環，移除導致循環的邊
                return cycleEdge;
            }
        }
    };