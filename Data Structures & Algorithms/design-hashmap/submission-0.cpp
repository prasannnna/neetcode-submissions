class MyHashMap {
public:
    static const int SIZE = 1009; // Prime number, which helps distribute keys more evenly across buckets and reduces collisions.
    vector<list<pair<int, int>>>table;
    MyHashMap() {
        table.resize(SIZE);
    }
    int myHashFunction(int key) {
        return key % SIZE;
    }
    
    void put(int key, int value) {
        int idx = myHashFunction(key);
        for(auto &t : table[idx]) {
            if(t.first == key) {
                t.second = value;
                return;
            }
        }
        table[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = myHashFunction(key);
        for(auto &t : table[idx]) {
            if(t.first == key) {
                return t.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = myHashFunction(key);
        for(auto it = table[idx].begin(); it != table[idx].end(); it++) {
            if(it->first == key) {
                table[idx].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */