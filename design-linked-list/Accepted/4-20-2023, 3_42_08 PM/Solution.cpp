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
        if (index < 0 || index >= size) { // check if index is out of bounds
            return -1;
        }
        Node* current = this->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->val;
    }

    void addAtHead(int val) {
        Node* newHead = new Node(val);
        newHead->next = this->head; // set newHead's next to current head
        this->head = newHead; // update head to newHead
        this->size++;
    }

    void addAtTail(int val) {
        if (this->head == NULL) { // if list is empty, add new node as head
            addAtHead(val);
            return;
        }
        Node* current = this->head;
        while (current->next != NULL) {
            current = current->next;
        }
        Node* newTail = new Node(val);
        current->next = newTail;
        this->size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        if (index == 0) { // if adding at head, use addAtHead method
            addAtHead(val);
            return;
        }
        Node* current = this->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* newNode = new Node(val);
        newNode->next = current->next;
        current->next = newNode;
        this->size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        if (index == 0) { // if deleting head, update head to next node
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
            this->size--;
            return;
        }
        Node* current = this->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        this->size--;
    }

    ~MyLinkedList(){
        Node* current = this->head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        this->head = NULL;
        this->size = 0;
    }
};
