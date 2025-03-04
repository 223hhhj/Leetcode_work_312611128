class LRUCache {
    private:
        int capacity;
        
        list<pair<int, int>> cache_list;

        unordered_map<int, list<pair<int, int>>::iterator> cache_map;
    
    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
        }

        int get(int key) {
            auto it = cache_map.find(key);

            if (it == cache_map.end()) {
                return -1;
            }
            
            cache_list.splice(cache_list.begin(), cache_list, it->second);
            
            return it->second->second;
        }
        
        void put(int key, int value) {
            auto it = cache_map.find(key);
            
            if (it != cache_map.end()) {
                it->second->second = value;
                
                cache_list.splice(cache_list.begin(), cache_list, it->second);
                return;
            }

            if (cache_list.size() >= capacity) {
                cache_map.erase(cache_list.back().first);

                cache_list.pop_back();
            }

            cache_list.push_front({key, value});

            cache_map[key] = cache_list.begin();
        }
    };