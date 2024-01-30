// https://leetcode.com/problems/add-two-numbers-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* prev = NULL;
       ListNode* curr = l1;
       int carry = 0;
       while(curr != NULL){
           ListNode* next = curr->next;
           curr->next = prev;
           prev = curr;

           curr = next;
       }
       ListNode* head1 = prev;
        curr = l2;
        prev = NULL;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;

            curr = next;
        }
        ListNode* head2 = prev;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int value = 0;
        while(head1 != NULL || head2 != NULL){
            int digit1 = (head1 != NULL) ? head1->val : 0;
            int digit2 = (head2 != NULL) ? head2->val : 0;
            int add = digit1 + digit2 + carry;
            if(add / 10 > 0){
           
                int tens = add / 10;
                int units = add % 10;
                carry = tens;
                ListNode* temp = new ListNode(units);
                if(head == NULL){
                    head = temp;
                    tail = temp;
                } else {
                    tail->next = temp;
                    tail = temp;
                }
                
            } else {
                carry = 0;
                ListNode* temp = new ListNode(add);
                if(head == NULL){
                    head = temp;
                    tail = temp;
                } else {
                    tail->next = temp;
                    tail = temp;
                }

            }
            head1 = (head1 != NULL) ? head1->next : NULL;
            head2 = (head2 != NULL) ? head2->next : NULL;
        }
        if(carry != 0){
            ListNode* temp = new ListNode(carry);
            temp->next = head;
            head = temp;
        }

        prev = NULL;
        curr = head;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;

            curr = next;

        }

        return prev;

        
    }
};