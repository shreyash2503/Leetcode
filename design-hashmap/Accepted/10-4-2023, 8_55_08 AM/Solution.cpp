// https://leetcode.com/problems/design-hashmap

class MyHashMap {
public:
    int map[10000000];
    int size;
    MyHashMap() {
        this->size = 0;
        for(int i=0;i<1000000;i++){
            map[i] = -1;
        }
        
    }
    
    void put(int key, int value) {
        if(map[key] != -1){
            map[key] = value;
            return;
        }
        map[key] = value;
        
        
    }
    
    int get(int key) {
        return map[key];
        
    }
    
    void remove(int key) {
        map[key ] = -1;
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */