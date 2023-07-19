class LRUCache {
    size_t capacity;
    queue<int> window;
    unordered_map<int, pair<int, int>> cache;
public:
    LRUCache(int _capacity) : capacity(_capacity) {
        
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        window.push(key);
        it->second.second++;
        return it->second.first;
    }
    
    void put(int key, int value) {
        window.push(key);
        auto it = cache.find(key);
        if (it == cache.end()) {
            cache[key] = {value, 1};
        } else {
            it->second.first = value;
            it->second.second++;
        }
        while (cache.size() > capacity) {
            int oldest = window.front();
            window.pop();
            auto it = cache.find(oldest);
            it->second.second--;
            if (it->second.second == 0) {
                cache.erase(it);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */