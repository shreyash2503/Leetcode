// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateList(ListNode* head){
        ListNode* curr = head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;

        }
        if(curr && prev){
            prev->next = NULL;
            curr->next = temp;
        }
        return curr;

    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        ListNode* temp = head;;
        for(int i=0;i<k;i++){
            temp = rotateList(temp);
        }
        return temp;

        
    }
};