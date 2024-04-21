class LRUCache {
private:
    int size;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> lst;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;
        lst.splice(lst.begin(), lst, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            lst.splice(lst.begin(), lst, it->second);
            it->second->second = value;
            return;
        }
        if (m.size() == size) {
            int keyToDelete = lst.back().first;
            lst.pop_back();
            m.erase(keyToDelete);
        }
        lst.push_front({key, value});
        m[key] = lst.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */