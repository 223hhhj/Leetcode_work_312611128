class Solution {
    public:
        string removeDuplicates(string s, int k) {
            // Use a stack to store pairs of (character, count)
            vector<pair<char, int>> stack;
            
            for (char c : s) {
                // If stack is empty or current char is different from top
                if (stack.empty() || stack.back().first != c) {
                    stack.push_back({c, 1});
                } else {
                    // Same character, increment count
                    stack.back().second++;
                    
                    // If count reaches k, remove this group
                    if (stack.back().second == k) {
                        stack.pop_back();
                    }
                }
            }
            
            // Build result string from stack
            string result = "";
            for (auto& p : stack) {
                for (int i = 0; i < p.second; i++) {
                    result += p.first;
                }
            }
            
            return result;
        }
    };