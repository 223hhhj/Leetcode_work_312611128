class Solution {
    public:
        string removeDuplicateLetters(string s) {
            // Count frequency of each character
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            
            // Track which characters are already in result
            vector<bool> inStack(26, false);
            
            // Use string as stack for result
            string result = "";
            
            for (char c : s) {
                // Decrease count as we process each character
                count[c - 'a']--;
                
                // If character is already in result, skip it
                if (inStack[c - 'a']) {
                    continue;
                }
                
                // Remove characters from result if:
                // 1. Current char is smaller (lexicographically)
                // 2. The character at top of stack will appear later in string
                while (!result.empty() && 
                       result.back() > c && 
                       count[result.back() - 'a'] > 0) {
                    inStack[result.back() - 'a'] = false;
                    result.pop_back();
                }
                
                // Add current character to result
                result.push_back(c);
                inStack[c - 'a'] = true;
            }
            
            return result;
        }
    };