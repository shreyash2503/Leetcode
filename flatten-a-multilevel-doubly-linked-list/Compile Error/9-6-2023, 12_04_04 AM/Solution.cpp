// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* recursive(Node* head){
        if(head == NULL){
            return NULL;
        }
        Node* temp = head;
        while(temp != NULL){
            if(temp->child){
                Node* _temp = temp->next;
                Node* _next = recursive(temp->child);
                temp->next = _next;
                _next->prev = temp;

                temp->child = NULL;

                Node* prev = NULL;
                Node* flag = temp->next;
                while(flag != NULL){
                    prev = flag;
                    flag = flag->next;
                }
                prev->next = _temp;
                temp = _temp;
                if(_temp){
                _   temp->prev = prev;
                }
                continue;
            }
            temp = temp->next;

        }
        return head;
    }
    Node* flatten(Node* head) {
        return recursive(head);


        
    }
};