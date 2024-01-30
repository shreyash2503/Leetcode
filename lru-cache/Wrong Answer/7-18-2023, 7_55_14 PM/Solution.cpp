// https://leetcode.com/problems/lru-cache


class Node{
    public:
    Node* prev;
    Node* next;
    int val;
    Node(int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
    
};
class LRUCache {
public:
    int size;
    Node* head;
    Node* tail;
    int capacity;
    Node* prev;
    unordered_map<int, int> map;
    LRUCache(int capacity) {
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
        this->capacity = capacity;
        this->prev = NULL;
        
    }
    
    int get(int key) {
        if(map.find(key) != map.end() && this->tail){
            Node* temp = new Node(this->tail->val);
            Node* flag = this->tail->prev;
            this->tail->prev = NULL;
            this->tail = flag;
            temp->next = head;
            head->prev = temp;
            head = temp;
            return map[key];

        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(head == NULL){
            head = new Node(key);
            tail = head;
            map[key] = value;
            this->size++;
            return;
        }
        if(size < capacity){
            map[key] = value;
            Node* temp = new Node(key);
            temp->next = head;
            head->prev = temp;
            head = temp;
            this->size++;
            return;
        } else if (this->tail) {
            map.erase(this->tail->val);
            Node* flag = this->tail->prev;
            this->tail->prev = NULL;
            this->tail =  flag;
            this->size--;
            map[key] = value;
            Node* temp = new Node(key);
            temp->next = head;
            head->prev = temp;
            head = temp;
            this->size++;
            return;

        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */