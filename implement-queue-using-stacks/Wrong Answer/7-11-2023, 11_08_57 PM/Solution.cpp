// https://leetcode.com/problems/implement-queue-using-stacks

class MyQueue {
public:
    stack<int> eq;
    stack<int> dq;
    int size;
    int frontElement;
    MyQueue() {
        this->size = 0;
        this->frontElement = -1;
        
    }
    
    void push(int x) {
        eq.push(x);
        if(frontElement == -1){
            this->frontElement = x;
        }
        this->size ++;
        
    }
    
    int pop() {
        if (size == 1){
            int element = eq.top();
            eq.pop();
            this->size --;
            return element;
    
        }
        while(!eq.empty()){
            dq.push(eq.top());
            eq.pop();
        }
        int element = dq.top();
        dq.pop();
        this->frontElement = dq.top();
        while(!dq.empty()){
            eq.push(dq.top());
            dq.pop();
        }
        this->size --;
        return element;  
    }
    
    int peek() {
        return this->frontElement;
    }
    
    bool empty() {
        return size == 0 ? true : false;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */