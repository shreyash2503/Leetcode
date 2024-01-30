// https://leetcode.com/problems/min-stack

class Node{
    public:
    Node* next;
    Node* min;
    int val;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->min = NULL;
    }
};

class MinStack {
public:
    Node* head;
    int size;
    Node* min;

    
    MinStack() {
        this->size = 0;
        this->head = NULL;
        this->min = NULL;       
    }
    
    void push(int val) {
        if(head == NULL){
            Node* node = new Node(val);
            head = node;
            min = node;
            return;
        }
        Node* node = new Node(val);
        node->next = head;
        head = node;
        if(head->val < min->val){
            head->min = min;
            min = head;
        }
        this->size++;
    }
    
    void pop() {
        if(head->min != NULL){
            this->min = head->min;
        }
        head = head->next;
        this->size--;
    }
    
    int top() {
        return head->val;
        
    }
    
    int getMin() {
        return min->val;
        
    }

   


    

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */