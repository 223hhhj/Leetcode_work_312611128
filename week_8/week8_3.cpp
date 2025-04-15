class Solution {
    public:
        vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
            // Create adjacency list for the tree
            vector<vector<int>> graph(n);
            for (auto& edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
            
            // Initialize arrays
            vector<int> count(n, 1);       // Count of nodes in subtree (including the node itself)
            vector<int> answer(n, 0);      // Answer array with sum of distances
            
            // First DFS: Calculate count and partial answer for root node (0)
            dfs1(0, -1, graph, count, answer);
            
            // Second DFS: Calculate answer for all other nodes
            dfs2(0, -1, n, graph, count, answer);
            
            return answer;
        }
        
    private:
        // First DFS to calculate:
        // 1. count[i] - count of nodes in subtree rooted at i
        // 2. answer[0] - sum of distances from node 0 to all other nodes
        void dfs1(int node, int parent, vector<vector<int>>& graph, vector<int>& count, vector<int>& answer) {
            for (int child : graph[node]) {
                if (child != parent) {
                    dfs1(child, node, graph, count, answer);
                    count[node] += count[child];
                    answer[0] += count[child]; // Add distance from node 0 to all nodes in this subtree
                }
            }
        }
        
        // Second DFS to calculate answer for all nodes
        void dfs2(int node, int parent, int n, vector<vector<int>>& graph, vector<int>& count, vector<int>& answer) {
            for (int child : graph[node]) {
                if (child != parent) {
                    // Re-root the tree - calculate answer[child] from answer[node]
                    // When moving from node to child:
                    // 1. We get closer to all nodes in child's subtree (-count[child])
                    // 2. We get farther from all other nodes (n - count[child])
                    answer[child] = answer[node] - count[child] + (n - count[child]);
                    dfs2(child, node, n, graph, count, answer);
                }
            }
        }
    };