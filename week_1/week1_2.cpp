class LFUCache {
    private:
        int capacity, minFreq;
        unordered_map<int, pair<int, int>> keyToValFreq;
        unordered_map<int, list<int>> freqToKeys;
        unordered_map<int, list<int>::iterator> keyToIter;
    
        void updateFrequency(int key) {
            int freq = keyToValFreq[key].second;
            freqToKeys[freq].erase(keyToIter[key]);
            if (freqToKeys[freq].empty() && freq == minFreq) {
                minFreq++;
            }
            keyToValFreq[key].second++;
            freqToKeys[freq + 1].push_back(key);
            keyToIter[key] = --freqToKeys[freq + 1].end();
        }
    
    public:
        LFUCache(int capacity) : capacity(capacity), minFreq(0) {}
    
        int get(int key) {
            if (keyToValFreq.find(key) == keyToValFreq.end()) return -1;
            updateFrequency(key);
            return keyToValFreq[key].first;
        }
    
        void put(int key, int value) {
            if (capacity == 0) return;
    
            if (keyToValFreq.find(key) != keyToValFreq.end()) {
                keyToValFreq[key].first = value;
                updateFrequency(key);
                return;
            }
    
            if (keyToValFreq.size() == capacity) {
                int lfuKey = freqToKeys[minFreq].front();
                freqToKeys[minFreq].pop_front();
                keyToValFreq.erase(lfuKey);
                keyToIter.erase(lfuKey);
            }
    
            keyToValFreq[key] = {value, 1};
            freqToKeys[1].push_back(key);
            keyToIter[key] = --freqToKeys[1].end();
            minFreq = 1;
        }
    };