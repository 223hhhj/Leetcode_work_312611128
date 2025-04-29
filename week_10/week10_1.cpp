class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            // Step 1: 建立鄰接表和入度陣列
            vector<vector<int>> adj(numCourses); // 鄰接表：adj[i] 儲存課程 i 的後修課程
            vector<int> indegree(numCourses, 0); // 入度陣列：indegree[i] 儲存課程 i 的先修課程數量
            
            // 遍歷 prerequisites，填充鄰接表和入度陣列
            for (const auto& prereq : prerequisites) {
                int course = prereq[0]; // 要修的課程
                int pre = prereq[1];    // 先修課程
                adj[pre].push_back(course); // pre 是 course 的先修課程
                indegree[course]++; // course 的入度加 1
            }
            
            // Step 2: 初始化隊列，將入度為 0 的課程加入隊列
            queue<int> q;
            for (int i = 0; i < numCourses; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
            
            // Step 3: 執行拓撲排序
            vector<int> result; // 儲存修課順序
            while (!q.empty()) {
                int curr = q.front(); // 取出當前課程
                q.pop();
                result.push_back(curr); // 將課程加入結果
                
                // 遍歷當前課程的後修課程
                for (int next : adj[curr]) {
                    indegree[next]--; // 後修課程的入度減 1
                    if (indegree[next] == 0) { // 如果入度變為 0，加入隊列
                        q.push(next);
                    }
                }
            }
            
            // Step 4: 檢查是否所有課程都修完
            if (result.size() == numCourses) {
                return result; // 回傳修課順序
            } else {
                return {}; // 如果有循環依賴，回傳空陣列
            }
        }
    };