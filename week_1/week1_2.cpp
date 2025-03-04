class LFUCache {
    private:
        int capacity, minFreq;
        unordered_map<int, pair<int, int>> keyToValue;
        unordered_map<int, list<int>> freqToKeys;
        unordered_map<int, list<int>::iterator> keyToIter;
    
    public:
        LFUCache(int capacity) {
            this->capacity = capacity;
            this->minFreq = 0;
        }
    
        int get(int key) {
            if (keyToValue.find(key) == keyToValue.end()) return -1;

            int value = keyToValue[key].first;
            int freq = keyToValue[key].second;
            keyToValue[key].second++;

            freqToKeys[freq].erase(keyToIter[key]);
            if (freqToKeys[freq].empty()) {
                freqToKeys.erase(freq);
                if (minFreq == freq) minFreq++;
            }

            freqToKeys[freq + 1].push_back(key);
            keyToIter[key] = --freqToKeys[freq + 1].end();
    
            return value;
        }
    
        void put(int key, int value) {
            if (capacity == 0) return;
    
            if (keyToValue.find(key) != keyToValue.end()) {
                keyToValue[key].first = value;
                get(key);
                return;
            }

            if (keyToValue.size() >= capacity) {
                int lfuKey = freqToKeys[minFreq].front();
                freqToKeys[minFreq].pop_front();
                if (freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq);
                keyToValue.erase(lfuKey);
                keyToIter.erase(lfuKey);
            }

            keyToValue[key] = {value, 1};
            freqToKeys[1].push_back(key);
            keyToIter[key] = --freqToKeys[1].end();
            minFreq = 1;
        }
    };