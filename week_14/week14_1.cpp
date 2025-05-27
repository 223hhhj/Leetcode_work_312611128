class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            // 方法1: 使用 Hash Map + Min Heap (優先佇列)
            // 時間複雜度: O(n log k)，空間複雜度: O(n)
            
            // Step 1: 統計每個元素的出現頻率
            unordered_map<int, int> freq;
            for (int num : nums) {
                freq[num]++;
            }
            
            // Step 2: 使用 min heap 維護前 k 個最高頻率的元素
            // pair<頻率, 元素值>，預設會按頻率排序
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
            
            for (auto& entry : freq) {
                minHeap.push({entry.second, entry.first}); // {頻率, 元素}
                
                // 如果 heap 大小超過 k，移除頻率最小的元素
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
            
            // Step 3: 從 heap 中取出結果
            vector<int> result;
            while (!minHeap.empty()) {
                result.push_back(minHeap.top().second);
                minHeap.pop();
            }
            
            return result;
        }
        
        // 方法2: 使用 Bucket Sort (更優的解法)
        // 時間複雜度: O(n)，空間複雜度: O(n)
        vector<int> topKFrequentBucketSort(vector<int>& nums, int k) {
            // Step 1: 統計頻率
            unordered_map<int, int> freq;
            for (int num : nums) {
                freq[num]++;
            }
            
            // Step 2: 建立 bucket，index 代表頻率
            vector<vector<int>> buckets(nums.size() + 1);
            for (auto& entry : freq) {
                buckets[entry.second].push_back(entry.first);
            }
            
            // Step 3: 從高頻率到低頻率收集結果
            vector<int> result;
            for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
                for (int num : buckets[i]) {
                    result.push_back(num);
                    if (result.size() == k) break;
                }
            }
            
            return result;
        }
    };