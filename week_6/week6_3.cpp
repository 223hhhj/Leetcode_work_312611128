class Solution {
    public:
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
            unordered_map<string, vector<string>> memo;
            
            return backtrack(s, wordSet, memo);
        }
        
    private:
        vector<string> backtrack(const string& s, const unordered_set<string>& wordSet, 
                                unordered_map<string, vector<string>>& memo) {
            // If we've already solved this subproblem, return the cached result
            if (memo.count(s)) {
                return memo[s];
            }
            
            vector<string> result;
            
            // If the entire string is a word, add it to results
            if (wordSet.count(s)) {
                result.push_back(s);
            }
            
            // Try to break the string at different positions
            for (int i = 1; i < s.length(); i++) {
                string word = s.substr(0, i);
                
                // If the prefix is a valid word, explore the rest of the string
                if (wordSet.count(word)) {
                    // Recursively solve for the remaining substring
                    vector<string> subResults = backtrack(s.substr(i), wordSet, memo);
                    
                    // Combine the current word with all valid strings from the remaining substring
                    for (const string& subResult : subResults) {
                        result.push_back(word + " " + subResult);
                    }
                }
            }
            
            // Cache the result for this subproblem
            memo[s] = result;
            return result;
        }
    };