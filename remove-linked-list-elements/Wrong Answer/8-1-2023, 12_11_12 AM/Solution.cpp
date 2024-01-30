// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return NULL;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            if(curr->val == val && prev == NULL){
                ListNode* temp = curr->next;
                curr->next = NULL;
                curr = temp;
                continue;
            }
            if(curr->val == val){
                ListNode* temp = prev->next->next;
                curr->next = NULL;
                prev->next = temp;
                curr = prev->next;
                continue;
            }
            prev = curr;
            curr = curr->next;

        }
        if(head != NULL && head->val == val){
            return NULL;
        }
        return head;
        
    }
};