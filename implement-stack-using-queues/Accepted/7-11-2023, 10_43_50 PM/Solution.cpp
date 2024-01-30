// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
public:
    deque<int> dq;
    int size;
    MyStack() {
        this->size = 0;
        
    }
    
    void push(int x) {
        dq.push_back(x);
        size++;
        
    }
    
    int pop() {
        int element = dq.back();
        dq.pop_back();
        this->size--;
        return element;

    }
    
    int top() {
        return dq.back();
    }
    
    bool empty() {
        return size == 0 ? true : false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */