class Solution {
    public:
        int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
            if (source == target) return 0;
    
            unordered_map<int, vector<int>> stop_to_buses;
            for (int i = 0; i < routes.size(); ++i) {
                for (int stop : routes[i]) {
                    stop_to_buses[stop].push_back(i);
                }
            }
    
            queue<int> q;
            unordered_set<int> visited_stops;
            unordered_set<int> visited_buses;
            int bus_count = 0;
    
            q.push(source);
            visited_stops.insert(source);
    
            while (!q.empty()) {
                int size = q.size();
                ++bus_count;
    
                for (int i = 0; i < size; ++i) {
                    int stop = q.front(); q.pop();
    
                    for (int bus : stop_to_buses[stop]) {
                        if (visited_buses.count(bus)) continue;
                        visited_buses.insert(bus);
    
                        for (int next_stop : routes[bus]) {
                            if (next_stop == target) return bus_count;
                            if (!visited_stops.count(next_stop)) {
                                visited_stops.insert(next_stop);
                                q.push(next_stop);
                            }
                        }
                    }
                }
            }
    
            return -1;
        }
    };
    