class FreqStack {
    private:
        // Map to store frequency of each value
        unordered_map<int, int> freq;
        
        // Map to store stacks for each frequency level
        // freq_stacks[i] contains all elements with frequency i
        unordered_map<int, stack<int>> freq_stacks;
        
        // Track the maximum frequency seen so far
        int max_freq;
        
    public:
        FreqStack() {
            max_freq = 0;
        }
        
        void push(int val) {
            // Increment frequency of val
            freq[val]++;
            
            // Update max frequency
            max_freq = max(max_freq, freq[val]);
            
            // Push val to the stack corresponding to its new frequency
            freq_stacks[freq[val]].push(val);
        }
        
        int pop() {
            // Get the element from the highest frequency stack
            int val = freq_stacks[max_freq].top();
            freq_stacks[max_freq].pop();
            
            // Decrease frequency of val
            freq[val]--;
            
            // If the highest frequency stack becomes empty, decrease max_freq
            if (freq_stacks[max_freq].empty()) {
                max_freq--;
            }
            
            return val;
        }
    };