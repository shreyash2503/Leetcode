// https://leetcode.com/problems/design-hashset

class MyHashSet {
public:
    int map[10000000];
    MyHashSet() {
        memset(this->map, -1, sizeof(map));
        
        
    }
    
    void add(int key) {
        map[key] = key;
        
    }
    
    void remove(int key) {
        map[key] = -1;
        
    }
    
    bool contains(int key) {
        return map[key] != -1 ? true : false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */