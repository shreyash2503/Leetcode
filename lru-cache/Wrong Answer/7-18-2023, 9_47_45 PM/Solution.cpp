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
    unordered_map<int, Node*> map;
    LRUCache(int capacity) {
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
        this->capacity = capacity;
        
    }
    
    int get(int key) {
        if(map.find(key) != map.end() && this->head == this->tail){
            return this->head->val;
        }
        if(map.find(key) != map.end() && map[key] == this->head){
            return this->head->val;
        }
        if(map.find(key) != map.end() && map[key] == this->tail){
            Node* flag = this->tail;
            Node* temp = this->tail->prev;
            this->tail->prev = NULL;
            this->tail = temp;
            flag->next = head;
            head->prev = flag;
            head = flag;
            return head->val;
            
        } else if(map.find(key) != map.end()){
            Node* temp = map[key];
            Node* prev = temp->prev;
            Node* next = temp->next;
            if(prev){
                prev->next = next;
            }
            if(next){
                next->prev = prev;

            }
            temp->prev = NULL;
            temp->next = NULL;

            temp->next = head;
            head->prev = temp;
            head = temp;

            return temp->val;
        }
        return -1;
       
        
    }
    
    void put(int key, int value) {
        if(head == NULL){
            Node* temp = new Node(value);
            head = temp;
            tail = temp;
            map[key] = temp;
            this->size++;
            return;
        }
        if(size < capacity){
            Node* temp = new Node(value);
            temp->next = head;
            head->prev = temp;
            head = temp;
            map[key] = temp;
            this->size++;
            return;
        } else if(this->tail && size == capacity) {
            map.erase(this->tail->val);
            Node* flag = this->tail;
            Node* temp = this->tail->prev;
            this->tail->prev = NULL;
            this->tail = temp;
            flag->val = value;

            flag->next = head;
            head->prev = flag;
            head = flag;
            map[key] = head;
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