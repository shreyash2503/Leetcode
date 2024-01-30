// https://leetcode.com/problems/design-linked-list

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }

};


class MyLinkedList {
public:
   Node* head;
   int size;
    MyLinkedList() {
        this->head = NULL;
        this->size = 0;
    }
    
    int get(int index) {
        if(index < 0)  return -1;
        Node* current = this->head;
        int count = index;
        for(int i=0;i<count;i++){
            if(current && current->next){
                current = current->next;
            }
        }
        
        return current->val;
    }
    
    void addAtHead(int val) {
        Node* newHead = new Node(val);
        Node* flag = this->head;
        this->head = newHead;
        newHead->next = flag;
        this->size ++ ;
    }
    
    void addAtTail(int val) {
        Node* current = this->head;
        for(int i=0;i<this->size;i++){
            if(current && current->next){
                current = current->next;
            }
        }
        Node* newTail = new Node(val);
        current->next = newTail;
        this->size++;

        
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size){
            return;
        }
        Node* current = this->head;
        for(int i=0;i<index - 1;i++){
            if(current && current->next){
                 current = current->next;
            }
        }
        Node* newNode = new Node(val);
        Node* flag = current->next;
        newNode->next = flag;
        current->next = newNode;
        this->size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0){
            return;
        }
        if(index == 0){
            Node* flag = this->head->next;
            this->head->next = NULL;
            delete head;
            this->head = flag;
            return;
        }
        Node* current = this->head;
        for(int i=0;i<index-1;i++){
            current = current->next;
        }
        if(current && current->next){
             Node* flag = current->next->next;
            Node* temp = current->next;
            temp->next = NULL;
            current->next = flag;
            delete temp;
        }
       
    }
    ~MyLinkedList(){
        Node* p = this->head;
        while(head != NULL){
            head = head->next;
            delete p;
            p = head;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */